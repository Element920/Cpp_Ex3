#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Player.hpp"

namespace catan_game {

    class Player;

    class Building {
    public:
        enum Type {
            SETTLEMENT,
            CITY
        };

    private:
        Type buildingType;
        Player* owner;

    public:
        Building(Type type, Player* owner);

        Type getType() const;
        Player* getOwner() const;
        void setOwner(Player* owner);
    };

}

#endif
