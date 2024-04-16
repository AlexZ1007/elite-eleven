//
// Created by Alex on 4/3/2024.
//

#include <random>

#include "../headers/Pack.h"
Player Pack::open() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, possibleDrops.size() - 1);
    return possibleDrops[distr(gen)];
}

std::ostream &operator<<(std::ostream &os, const Pack &pack) {
    os << "Pack: " << pack.name << "(" << pack.cost << " gold)";
    return os;
}

int Pack::getCost() const {
    return cost;
}

Pack::Pack(const std::string &name, int cost, const std::vector<Player> &possibleDrops) : name(name), cost(cost),
                                                                                          possibleDrops(possibleDrops) {}
