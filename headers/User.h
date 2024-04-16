//
// Created by Alex on 4/3/2024.
//

#include <iostream>
#include <vector>
#include "Pack.h"

#ifndef OOP_USER_H
#define OOP_USER_H


class User {
private:
    std::string name;
    int balance;
    std::vector<Player> inventory;
public:
    User(const std::string &name);


    ~User();

    User(User const &entitate);


    const std::string &getName() const;

    void login();

    void logout();

    const std::vector<Player> &getInventory() const;    

    User &operator=(const User &user);

    int getBalance() const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);

    void openPack(Pack pack);

    void showInventory();
};

#endif //OOP_USER_H
