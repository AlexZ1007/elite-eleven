//
// Created by Alex on 4/15/2024.
//

#ifndef OOP_MENUITEMLOGOUT_H
#define OOP_MENUITEMLOGOUT_H

#include "MenuItem.h"
#include "User.h"

class MenuItemLogOut : public MenuItem {
private:
    MenuItem* menuI;
public:
    MenuItemLogOut()  = default;
    ~MenuItemLogOut() override  = default;

    explicit MenuItemLogOut(const std::string &key);

    using MenuItem::executeAction;
    void executeAction(User &user);
};


#endif //OOP_MENUITEMLOGOUT_H
