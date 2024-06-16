#include "Vertex.hpp"
#include "Building.hpp"
#include "Tile.hpp"

using namespace catan_game;

Vertex::Vertex() : building(nullptr) {}

const std::vector<Tile*>& Vertex::getAdjacentTiles() const {
    return adjacentTiles;
}

const std::vector<Vertex*>& Vertex::getNeighbors() const {
    return neighbors;
}

Building* Vertex::getBuilding() const {
    return building;
}

void Vertex::addAdjacentTile(Tile* tile) {
    adjacentTiles.push_back(tile);
}

void Vertex::addNeighbor(Vertex* vertex) {
    neighbors.push_back(vertex);
}

void Vertex::setBuilding(Building* building) {
    this->building = building;
}

bool Vertex::hasBuilding() const {
    return building != nullptr;
}
