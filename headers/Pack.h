//
// Created by Alex on 4/3/2024.
//

#ifndef OOP_PACK_H
#define OOP_PACK_H
#include "Player.h"

class Pack {
protected:
    std::string name;
    int cost;
    std::vector<Player> possibleDrops;
public:
    Pack() = default;
    Pack(const std::string &name, int cost, const std::vector<Player> &possibleDrops);
    virtual ~Pack() = default;

    [[nodiscard]] int getCost() const;
    friend std::ostream &operator<<(std::ostream &os, const Pack &pack);
    virtual Player open();

};

#endif //OOP_PACK_H
