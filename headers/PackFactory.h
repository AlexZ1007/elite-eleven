#ifndef PACK_FACTORY_H
#define PACK_FACTORY_H

#include <memory>
#include <vector>
#include <string>
#include <type_traits>
#include "Pack.h"
#include "PremiumPack.h"

template<typename T>
class PackFactory {
public:
    template<typename... Args>
    static std::unique_ptr<Pack> createPack(Args&&... args);
};

#include "../src/PackFactory.tpp"



#endif // PACK_FACTORY_H
