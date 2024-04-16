//
// Created by Alex on 4/15/2024.
//

#include "../headers/MenuItemUserExecMethod.h"
#include <map>

void MenuItemUserExecMethod::executeAction() {
    // Check if the user object is valid
    if (user) {
        // Define a map of method names to pointers to member functions of User class
        std::map<std::string, void (User::*)()> methodMap = {
                {"showInventory", &User::showInventory},
        };

        // Find the method pointer corresponding to the method name
        auto methodIter = methodMap.find(execMethod);

        // Check if the method name is found in the map
        if (methodIter != methodMap.end()) {
            (user->*(methodIter->second))();
        } else {
            std::cout << "Error: Method '" << execMethod << "' not found or not supported." << std::endl;
        }
    }

}

MenuItemUserExecMethod::MenuItemUserExecMethod(const std::string &key, User *user, const std::string &execMethod)
        : MenuItem(key), user(user), execMethod(execMethod) {}
