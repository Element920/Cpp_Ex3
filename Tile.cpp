#include "Tile.hpp"

Tile::Tile(TileType type, int number) : type(type), number(number) {}

TileType Tile::getType() const {
    return type;
}

int Tile::getNumber() const {
    return number;
}

void Tile::addVertex(Vertex* vertex) {
    adjacentVertices.push_back(vertex);
}

const std::vector<Vertex*>& Tile::getAdjacentVertices() const {
    return adjacentVertices;
}
