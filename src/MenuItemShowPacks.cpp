//
// Created by Alex on 4/15/2024.
//

#include "../headers/MenuItemShowPacks.h"

MenuItemShowPacks::MenuItemShowPacks(const std::string &key) : MenuItem(key) {}

void MenuItemShowPacks::executeAction(const std::vector<Pack> &packs, User &user) {
    int pack_id;
    std::cout << "Available packs: \n";
    int sizeAsInt = static_cast<int>(packs.size());

    for (int i = 0; i < sizeAsInt; i++)
        std::cout << "ID: " << i << " " << packs[i] << std::endl;
    std::cout << "Select pack id (-1 to cancel)";
    std::cin >> pack_id;
    if (pack_id < 0 || pack_id >= sizeAsInt)
        std::cout << "Pack selector left" << std::endl;
    else {
        user.openPack(packs[pack_id]);
    }

}
