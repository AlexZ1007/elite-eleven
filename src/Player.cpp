//
// Created by Alex on 4/3/2024.
//

#include "../headers/Player.h"
#include <windows.h>

void SetConsoleColor(WORD color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput, color);
}

Player::Player(const std::string &name, const std::string &type, int ovr) : name(name), type(type), ovr(ovr) {}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    SetConsoleColor(FOREGROUND_GREEN); // Set text color to green
    os << player.name << " ";
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to red
    os << player.type << " ";
    SetConsoleColor(FOREGROUND_BLUE); // Set text color to blue
    os << player.ovr << " ";
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to default color
    return os;
}

const std::string &Player::getType() const {
    return type;
}

int Player::getOvr() const {
    return ovr;
}

const std::string &Player::getName() const {
    return name;
}
