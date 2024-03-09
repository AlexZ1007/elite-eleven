#include <iostream>
#include <array>
#include <windows.h>

#include <Helper.h>

void SetConsoleColor(WORD color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput, color);
}

class User{
private:
    std::string name;
public:
    User(const std::string &name) : name(name) {std::cout<<"Logged in successfully!"<<std::endl;}
    ~User() {
        std::cout<<"Logged out of "<<this->name<<std::endl;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        User::name = name;
    }

    friend std::ostream &operator<<(std::ostream &os, const User &user) {
        os << "Logged in as " << user.name<<std::endl;
        return os;
    }
};



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


    bool operator==(const Player &rhs) const {
        return name == rhs.name &&
               type == rhs.type &&
               ovr == rhs.ovr;
    }

    bool operator!=(const Player &rhs) const {
        return !(rhs == *this);
    }


};

int main(){
    std::cout<<"Insert username: ";
    std::string name;
    std::cin>>name;
    User user(name);

    // Check the input
    while(true){
        std::cout<<"Your input: ";
        std::string input;
        std::cin>>input;

        if (input == "pack")
            std::cout << "Pack\n";
        else if(input == "logout")
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
