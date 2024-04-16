//
// Created by Alex on 4/15/2024.
//

#ifndef OOP_MENUITEMUSEREXECMETHOD_H
#define OOP_MENUITEMUSEREXECMETHOD_H


#include "MenuItem.h"
#include "User.h"


class MenuItemUserExecMethod : public MenuItem {
private:
    User *user;
    std::string execMethod;
    MenuItem* menuI;
public:
    MenuItemUserExecMethod() = default;
    ~MenuItemUserExecMethod() override = default;

    MenuItemUserExecMethod(const std::string &key, User *user, const std::string &execMethod);

//    using MenuItem::executeAction;
    void executeAction() override;
};


#endif //OOP_MENUITEMUSEREXECMETHOD_H
