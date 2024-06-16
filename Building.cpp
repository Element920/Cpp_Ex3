#include "Building.hpp"

using namespace catan_game;

Building::Building(Player* player, bool isCity) : owner(player), isCity(isCity) {}

Player* Building::getOwner() const {
    return owner;
}

bool Building::getIsCity() const {
    return isCity;
}
