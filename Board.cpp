#include "Board.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>

using namespace catan_game;

// Initialize the static instance to nullptr
Board* Board::boardInstance = nullptr;

// Private constructor
Board::Board() {
    initializeVertices();
    initializeEdges();
    initializeTiles();
    assignNumbers();
    assignVertexToTiles();
    updateVertexNeighbors();
    deleteAndUpdateInvalidVertices();
}

// Destructor
Board::~Board() {
    for (auto& row : boardVertices) {
        for (auto& vertex : row) {
            delete vertex;
        }
    }
    for (auto& edge : boardEdges) {
        delete edge;
    }
    for (auto& tile : boardTiles) {
        delete tile;
    }
}

// Public method to get the single instance
Board* Board::getBoardInstance() {
    if (boardInstance == nullptr) {
        boardInstance = new Board();
    }
    return boardInstance;
}

const std::vector<Tile*>& Board::getTiles() const {
    return boardTiles;
}

Vertex* Board::placeSettlement(int row, int col, Player* player, bool isCity, bool freeFromResource) {
    if (isOutOfBound(row, col)) {
        throw std::out_of_range("Trying to place settlement out of board bounds.");
    }
    Vertex* vertex = boardVertices[row][col];
    if (vertex->hasBuilding()) {
        throw std::logic_error("There is already a building on this vertex.");
    }
    Building* building = new Building(player, isCity);
    vertex->setBuilding(building);
    return vertex;
}

Edge* Board::placeRoad(int fromRow, int fromCol, int toRow, int toCol, Player* player, bool freeFromResource) {
    if (isOutOfBound(fromRow, fromCol) || isOutOfBound(toRow, toCol)) {
        throw std::out_of_range("Trying to place road out of board bounds.");
    }
    Vertex* vertex1 = boardVertices[fromRow][fromCol];
    Vertex* vertex2 = boardVertices[toRow][toCol];
    Edge* edge = addEdge(vertex1, vertex2);
    if (edge->getRoadOwner() != nullptr) {
        throw std::logic_error("There is already a road on this edge.");
    }
    edge->setRoad(player);
    return edge;
}

bool Board::isOutOfBound(int row, int col) const {
    return row < 0 || col < 0 || row >= boardVertices.size() || col >= boardVertices[row].size();
}

// Other methods for initializing and managing the board...
