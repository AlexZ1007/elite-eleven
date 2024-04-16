//
// Created by Alex on 4/15/2024.
//

#include "../headers/MenuItemShowPacks.h"
#include "../headers/InvalidPackIdException.h"

MenuItemShowPacks::MenuItemShowPacks(const std::string &key) : MenuItem(key) {}

void MenuItemShowPacks::executeAction(const std::vector<Pack> &packs, User &user) {
    int pack_id;
    std::cout << "Available packs: \n";
    int sizeAsInt = static_cast<int>(packs.size());

    for (int i = 0; i < sizeAsInt; i++)
        std::cout << "ID: " << i << " " << packs[i] << std::endl;
    std::cout << "Select pack id (-1 to cancel)";
    std::cin >> pack_id;
    try {
        if (pack_id < 0 || pack_id >= sizeAsInt)
            throw InvalidPackIdException();
        user.openPack(packs[pack_id]);
    } catch(const InvalidPackIdException& e) {
        std::cout << "Error "  << e.what();
    }


}
