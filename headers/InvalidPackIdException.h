//
// Created by Alex on 4/16/2024.
//

#ifndef OOP_INVALIDPACKIDEXCEPTION_H
#define OOP_INVALIDPACKIDEXCEPTION_H

#include <iostream>
#include <exception>

class InvalidPackIdException : public std::exception {
public:
    [[nodiscard]] const char * what() const noexcept override;
};


#endif //OOP_INVALIDPACKIDEXCEPTION_H
