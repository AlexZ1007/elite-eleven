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
    Player() = default;
    Player(const std::string &name, const std::string &type, int ovr);

    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]]  const std::string &getType() const;
    [[nodiscard]]  int getOvr() const;

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

};


#endif //OOP_PLAYER_H
