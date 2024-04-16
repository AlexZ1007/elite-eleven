//
// Created by Alex on 4/3/2024.
//

#include <iostream>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

class Player {
private:
    std::string name;
    std::string type;
    int ovr;
public:
    Player(const std::string &name, const std::string &type, int ovr);

    const std::string &getName() const;


    const std::string &getType() const;


    int getOvr() const;

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

};


#endif //OOP_PLAYER_H
