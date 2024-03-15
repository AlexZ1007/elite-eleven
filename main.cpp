#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <Helper.h>
#include <random>

void SetConsoleColor(WORD color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput, color);
}





class Player{
private:
    std::string name;
    std::string type;
    int ovr;
public:
    Player(const std::string &name, const std::string &type, int ovr) : name(name), type(type), ovr(ovr) {}
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Player::name = name;
    }

    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        Player::type = type;
    }

    int getOvr() const {
        return ovr;
    }

    void setOvr(int ovr) {
        Player::ovr = ovr;
    }

    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        SetConsoleColor(FOREGROUND_GREEN); // Set text color to green
        os <<  player.name << " ";
        SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to red
        os <<  player.type << " ";
        SetConsoleColor(FOREGROUND_BLUE); // Set text color to blue
        os << player.ovr << " ";
        SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to default color
        return os;
    }


};


class Pack{
private:
    std::string name;
    int cost;
    std::vector<Player> possibleDrops;
public:
    Pack(const std::string &name, int cost, const std::vector<Player> &possibleDrops) : name(name), cost(cost), possibleDrops(possibleDrops) {}

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Pack::name = name;
    }

    int getCost() const {
        return cost;
    }

    void setCost(int cost) {
        Pack::cost = cost;
    }

    friend std::ostream &operator<<(std::ostream &os, const Pack &pack) {
        os << "Pack: " << pack.name << "(" << pack.cost<<" gold)";
        return os;
    }

    Player open() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, possibleDrops.size() - 1);
        return possibleDrops[distr(gen)];
    }

};

class User{
private:
    std::string name;
    int balance;
    std::vector<Player> inventory;
public:
    User(const std::string &name) : name(name), balance(100) {
        this->login();
    }


    ~User() {
       this->logout();
    }

    User( User const &entitate ){
        this->name = entitate.getName();
        this->inventory = entitate.getInventory();
        this->balance = entitate.getBalance();
    }



    const std::string &getName() const {
        return name;
    }

    void login(){
        std::cout<<"Logged in successfully! "<<std::endl;
        std::ifstream readFromFile("../saveFiles/"+name+".txt");

        if (readFromFile.is_open()) {
            int savedBalance;
            readFromFile>>savedBalance;
            this->balance = savedBalance;
            std::string playerName, type;
            int ovr;
            unsigned long long elements;
            readFromFile>>elements;
            readFromFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            for(unsigned long long i=0; i<elements; i++){
                std::getline(readFromFile, playerName);
                std::getline(readFromFile, type);

                readFromFile>>ovr;
                readFromFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                Player p(playerName, type, ovr);
                inventory.push_back(p);
            }
            readFromFile.close();
        }
        std::cout<<"Your balance is "<<this->balance<<"."<<std::endl;
    }

    void logout(){

//        std::cout<<"Logged out of "<<this->name<<std::endl;
        std::ofstream printInFile("../saveFiles/"+name+".txt");
        printInFile<<(this->balance+100)<<std::endl;
        printInFile<<inventory.size()<<std::endl;
        for (unsigned long long i=0; i<inventory.size(); i++) {
            printInFile << inventory[i].getName() << std::endl;
            printInFile << inventory[i].getType() << std::endl;
            printInFile << inventory[i].getOvr() << std::endl;

        }
        printInFile.close();
    }

    void setName(const std::string &name) {
        User::name = name;
    }

    const std::vector<Player> &getInventory() const {
        return inventory;
    }
    User &operator = ( const User &user ) {
        this->name = user.name;
        this->balance = user.balance;
        this->inventory = user.inventory;
        return *this;
    }

    int getBalance() const {
        return balance;
    }

    friend std::ostream &operator<<(std::ostream &os, const User &user) {
        os << "Logged in as " << user.name<<std::endl;
        return os;
    }

    void openPack(Pack pack){
        if(this->balance < pack.getCost()){
            std::cout<<"You don't have enough money! You have "<<this->balance<<", but you need "<<pack.getCost()<<std::endl;
        }else{
            this->balance -= pack.getCost();
            std::cout<<"You opened "<<pack<<std::endl;
            Player openedPlayer = pack.open();
            std::cout<<"You got "<<openedPlayer<<std::endl;
            this->inventory.push_back(openedPlayer);
        }
    }

    void showInventory(){
        for(unsigned long long i = 0; i<inventory.size();i++)
            std::cout<<"ID: "<<i<<" "<<inventory[i]<<std::endl;
    }
};



int main(){
    std::vector<Player> players = {
            Player("Lionel Messi", "basic", 88),
            Player("Cristiano Ronaldo", "basic", 85),
            Player("Neymar Jr", "basic", 92),
            Player("Kylian Mbappe", "basic", 90),
            Player("Robert Lewandowski", "basic", 86),
            Player("Kevin De Bruyne", "basic", 86),
            Player("Virgil van Dijk", "basic", 94),
            Player("Mohamed Salah", "basic", 87),
            Player("Sadio Mane", "basic", 88),
            Player("Erling Haaland", "basic", 86)
    };

    std::vector<Pack> packs = {Pack("basic", 10, players)};


    std::cout<<"Insert username: ";
    std::string name;
    std::cin>>name;
    User user(name);

    // Check the input
    while(true){
        std::cout<<"Your input: ";
        std::string input;
        std::cin>>input;

        if (input == "pack") {
            int pack_id;
            std::cout<<"Available packs: \n";
            int sizeAsInt = static_cast<int>(packs.size());

            for (int i=0; i < sizeAsInt; i++)
                std::cout<<"ID: "<<i<<" "<<packs[i]<<std::endl;
            std::cout<<"Select pack id (-1 to cancel)";
            std::cin>>pack_id;
            if(pack_id < 0 || pack_id >= sizeAsInt)
              std::cout<<"Pack selector left"<<std::endl;
            else{
                user.openPack(packs[pack_id]);
            }

        } else if(input == "inventory" || input == "i")
            user.showInventory();
        else if(input == "logout") {
            user.logout();
            std::cout<<"Insert username: ";
            std::string newName;
            std::cin>>newName;
            User newUser(newName);
            user=newUser;
        }
        else if(input == "quit")
            break;
        else
            std::cout << "Unknown input\n";

    }

    return 0;
}




//int main() {
//    std::cout << "Hello, world!\n";
//    std::array<int, 100> v{};
//    int nr;
//    std::cout << "Introduceti nr: ";
//    /////////////////////////////////////////////////////////////////////////
//    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
//    /// dați exemple de date de intrare folosind fișierul tastatura.txt
//    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
//    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
//    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
//    /// pentru cât mai multe ramuri de execuție.
//    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
//    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
//    ///
//    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
//    /// pentru a simula date introduse de la tastatură.
//    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
//    ///
//    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
//    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
//    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
//    /// program care merg (și să le evitați pe cele care nu merg).
//    ///
//    /////////////////////////////////////////////////////////////////////////
//    std::cin >> nr;
//    /////////////////////////////////////////////////////////////////////////
//    for(int i = 0; i < nr; ++i) {
//        std::cout << "v[" << i << "] = ";
//        std::cin >> v[i];
//    }
//    std::cout << "\n\n";
//    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
//    for(int i = 0; i < nr; ++i) {
//        std::cout << "- " << v[i] << "\n";
//    }
//    ///////////////////////////////////////////////////////////////////////////
//    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
//    /// alt fișier propriu cu ce alt nume doriți.
//    /// Exemplu:
//    /// std::ifstream fis("date.txt");
//    /// for(int i = 0; i < nr2; ++i)
//    ///     fis >> v2[i];
//    ///
//    ///////////////////////////////////////////////////////////////////////////
//    ///                Exemplu de utilizare cod generat                     ///
//    ///////////////////////////////////////////////////////////////////////////
//    Helper helper;
//    helper.help();
//    ///////////////////////////////////////////////////////////////////////////
//    return 0;
//}
