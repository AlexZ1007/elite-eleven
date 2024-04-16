//
// Created by Alex on 4/16/2024.
//

#ifndef OOP_INVALIDINPUTEXCEPTION_H
#define OOP_INVALIDINPUTEXCEPTION_H

#include <iostream>
#include <exception>

class InvalidInputException : public std::exception {
public:
    [[nodiscard]] const char * what() const noexcept override;
};


#endif //OOP_INVALIDINPUTEXCEPTION_H
