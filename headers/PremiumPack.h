//
// Created by Alex on 5/28/2024.
//

#ifndef OOP_PREMIUMPACK_H
#define OOP_PREMIUMPACK_H

#include "Pack.h"

class PremiumPack : public Pack {
private:
    int minOvr;
public:

    PremiumPack(const std::string &name, int cost, const std::vector<Player> &possibleDrops, int minOvr);
    ~PremiumPack() override = default;
    Player open() override;

};


#endif //OOP_PREMIUMPACK_H
