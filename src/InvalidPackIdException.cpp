//
// Created by Alex on 4/16/2024.
//

#include "../headers/InvalidPackIdException.h"
const char *InvalidPackIdException::what() const noexcept {
    return "Invalid pack ID \n";
}