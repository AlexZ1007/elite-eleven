//
// Created by Alex on 4/3/2024.
//
#include <fstream>
#include <random>
#include "../headers/User.h"

User::User(const std::string &name) : name(name), balance(100) {
    this->login();
}

/**
 *@brief Print the player inventory into console.
 */
void User::showInventory() {
    for (unsigned long long i = 0; i < inventory.size(); i++)
        std::cout << "ID: " << i << " " << inventory[i] << std::endl;
}

/**
 * @brief Opens a given pack if the user has enough balance.
 *
 * This method attempts to open a specified pack, checking first if the user's balance covers the pack's cost.
 * If insufficient, a message displays the shortfall. Otherwise, the cost is deducted, the pack is opened, and the resulting player is added to the user's inventory.
 *
 * @param pack The pack to be opened.
 *
 * @note This method modifies the user's balance and inventory if the pack is successfully opened.
 *
 */
void User::openPack(Pack pack) {
    if (this->balance < pack.getCost()) {
        std::cout << "You don't have enough money! You have " << this->balance << ", but you need "
                  << pack.getCost() << std::endl;
    } else {
        this->balance -= pack.getCost();
        std::cout << "You opened " << pack << std::endl;
        Player openedPlayer = pack.open();
        std::cout << "You got " << openedPlayer << std::endl;
        this->inventory.push_back(openedPlayer);
    }
}

int User::getBalance() const {
    return balance;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "Logged in as " << user.name << std::endl;
    return os;
}

User &User::operator=(const User &user) {
    this->name = user.name;
    this->balance = user.balance;
    this->inventory = user.inventory;
    return *this;
}

void User::logout() {

//        std::cout<<"Logged out of "<<this->name<<std::endl;
    std::ofstream printInFile("../saveFiles/" + name + ".txt");
    printInFile << (this->balance + 100) << std::endl;
    printInFile << inventory.size() << std::endl;
    for (unsigned long long i = 0; i < inventory.size(); i++) {
        printInFile << inventory[i].getName() << std::endl;
        printInFile << inventory[i].getType() << std::endl;
        printInFile << inventory[i].getOvr() << std::endl;

    }
    printInFile.close();
}

const std::vector<Player> &User::getInventory() const {
    return inventory;
}

User::User(const User &entitate) {
    this->name = entitate.getName();
    this->inventory = entitate.getInventory();
    this->balance = entitate.getBalance();
}

void User::login() {
    std::cout << "Logged in successfully! " << std::endl;
    std::ifstream readFromFile("../saveFiles/" + name + ".txt");

    if (readFromFile.is_open()) {
        int savedBalance;
        readFromFile >> savedBalance;
        this->balance = savedBalance;
        std::string playerName, type;
        int ovr;
        unsigned long long elements;
        readFromFile >> elements;
        readFromFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (unsigned long long i = 0; i < elements; i++) {
            std::getline(readFromFile, playerName);
            std::getline(readFromFile, type);

            readFromFile >> ovr;
            readFromFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Player p(playerName, type, ovr);
            inventory.push_back(p);
        }
        readFromFile.close();
    }
    std::cout << "Your balance is " << this->balance << "." << std::endl;
}

User::~User() {
    this->logout();
}

const std::string &User::getName() const {
    return name;
}
