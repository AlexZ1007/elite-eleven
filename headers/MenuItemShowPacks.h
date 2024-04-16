//
// Created by Alex on 4/15/2024.
//

#ifndef OOP_MENUITEMSHOWPACKS_H
#define OOP_MENUITEMSHOWPACKS_H


#include <vector>
#include "MenuItem.h"
#include "User.h"

class MenuItemShowPacks : public MenuItem {
private:
    MenuItem* menuI;
public:
    MenuItemShowPacks() = default;
    ~MenuItemShowPacks() override = default;

    explicit MenuItemShowPacks(const std::string &key);

    using MenuItem::executeAction;
    void executeAction(const std::vector<Pack>& packs, User &user);

};


#endif //OOP_MENUITEMSHOWPACKS_H
