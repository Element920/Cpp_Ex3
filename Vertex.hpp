#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

namespace catan_game {
    class Tile; // Forward declaration
    class Building; // Forward declaration

    class Vertex {
    private:
        std::vector<Tile*> adjacentTiles;
        std::vector<Vertex*> neighbors;
        Building* building;

    public:
        Vertex();

        const std::vector<Tile*>& getAdjacentTiles() const;
        const std::vector<Vertex*>& getNeighbors() const;
        Building* getBuilding() const;

        void addAdjacentTile(Tile* tile);
        void addNeighbor(Vertex* vertex);
        void setBuilding(Building* building);
        bool hasBuilding() const;
    };
}

#endif
