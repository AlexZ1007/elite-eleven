//
// Created by Alex on 4/16/2024.
//

#include "../headers/InvalidInputException.h"

const char *InvalidInputException::what() const noexcept {
    return "Invalid input \n";
}
