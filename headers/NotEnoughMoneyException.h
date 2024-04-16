//
// Created by Alex on 4/16/2024.
//

#ifndef OOP_NOTENOUGHMONEYEXCEPTION_H
#define OOP_NOTENOUGHMONEYEXCEPTION_H

#include <iostream>
#include <exception>

class NotEnoughMoneyException : public std::exception {
private:
    int cost;
    int balance;
public:
    NotEnoughMoneyException(int cost, int balance);

    [[nodiscard]] const char * what() const noexcept override;
};


#endif //OOP_NOTENOUGHMONEYEXCEPTION_H
