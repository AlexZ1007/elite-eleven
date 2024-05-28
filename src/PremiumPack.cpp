//
// Created by Alex on 5/28/2024.
//

#include <random>
#include "../headers/PremiumPack.h"
#include <algorithm>

Player PremiumPack::open() {
    std::vector<Player> filteredDrops;
    std::copy_if(possibleDrops.begin(), possibleDrops.end(), std::back_inserter(filteredDrops),
                 [this](const Player& player) { return player.getOvr() >= minOvr; });
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, filteredDrops.size() - 1);
    return filteredDrops[distr(gen)];
}

PremiumPack::PremiumPack(const std::string &name, int cost, const std::vector<Player> &possibleDrops, int minOvr)
        : Pack(name, cost, possibleDrops), minOvr(minOvr) {}


