//
// Created by Alex on 5/28/2024.
//

#include "../headers/PackFactory.h"
template<typename T>
template<typename... Args>
std::unique_ptr<Pack> PackFactory<T>::createPack(Args&&... args) {
    static_assert(std::is_base_of<Pack, T>::value, "T must be derived from Pack");
    return std::make_unique<T>(std::forward<Args>(args)...);
}
