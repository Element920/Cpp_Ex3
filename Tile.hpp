#ifndef TILE_H
#define TILE_H

#include <vector>

// Forward declaration of Vertex class
class Vertex;

// Enum for different types of tiles
enum class TileType {
    Forest,
    Fields,
    Hills,
    PastureLand,
    AgriculturalLand,
    Mountains,
    Desert
};

class Tile {
private:
    TileType type;
    int number;
    std::vector<Vertex*> adjacentVertices; // Vector to store adjacent vertices

public:
    Tile(TileType type, int number);

    TileType getType() const;
    int getNumber() const;

    void addVertex(Vertex* vertex);
    const std::vector<Vertex*>& getAdjacentVertices() const;
};

#endif // TILE_H
