//
// Created by Alex on 4/15/2024.
//

#include "../headers/MenuItemLogOut.h"

MenuItemLogOut::MenuItemLogOut(const std::string &key) : MenuItem(key) {}

void MenuItemLogOut::executeAction(User &user) {
    user.logout();
    std::cout << "Insert username: ";
    std::string newName;
    std::cin >> newName;
    User newUser(newName);
    user = newUser;
}

