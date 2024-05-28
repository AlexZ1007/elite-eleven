#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include "headers/Pack.h"
#include "headers/PremiumPack.h"
#include "headers/User.h"
#include "headers/MenuItemLogOut.h"
#include "headers/MenuItemShowPacks.h"
#include "headers/MenuItemUserExecMethod.h"
#include "headers/InvalidInputException.h"

int main() {
    std::vector<Player> players = {
            Player("Lionel Messi", "basic", 88),
            Player("Cristiano Ronaldo", "basic", 85),
            Player("Neymar Jr", "basic", 92),
            Player("Kylian Mbappe", "basic", 90),
            Player("Robert Lewandowski", "basic", 86),
            Player("Kevin De Bruyne", "basic", 86),
            Player("Virgil van Dijk", "basic", 94),
            Player("Mohamed Salah", "basic", 87),
            Player("Sadio Mane", "basic", 88),
            Player("Erling Haaland", "basic", 86)
    };

    std::vector<std::unique_ptr<Pack>> packs;
    packs.push_back(std::make_unique<Pack>("basic", 10, players));
    packs.push_back(std::make_unique<PremiumPack>("premium", 150, players, 90));

    std::cout << "Insert username: ";
    std::string name;
    std::cin >> name;
    User user(name);

    MenuItemLogOut menuItemLogOut("logout");
    MenuItemShowPacks menuItemShowPacks("packs");
    MenuItemUserExecMethod menuItemUserExecMethod("i",&user,"showInventory");
    // Check the input
    while (true) {
        std::cout << "Your input: ";
        std::string input;
        std::cin >> input;
        try{
            if (input == "pack") {
                menuItemShowPacks.executeAction(packs, user);
            } else if (input == "inventory" || input == "i")
                menuItemUserExecMethod.executeAction();
            else if (input == "logout") {
                menuItemLogOut.executeAction(user);
            } else if (input == "quit")
                break;
            else throw InvalidInputException();
        } catch(const InvalidInputException& e) {
            std::cout << "Error "  << e.what();
        }
    }

    return 0;
}