//
// Created by Alex on 4/16/2024.
//
#include <cstring>
#include "../headers/NotEnoughMoneyException.h"

const char *NotEnoughMoneyException::what() const noexcept {
    std::string message = "You don't have enough money! You have " + std::to_string(this->balance) + ", but you need " + std::to_string(this->cost) +"\n";

    char* buffer = new char[message.size() + 1];
    // Copy the contents of the std::string to the dynamically allocated buffer
    std::strcpy(buffer, message.c_str());
    return buffer;
}

NotEnoughMoneyException::NotEnoughMoneyException(int cost, int balance) : cost(cost), balance(balance) {}
