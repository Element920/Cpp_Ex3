#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.hpp" // Assuming Edge class is defined
#include "Card.hpp"
#include "TileType.hpp"
#include "Tile.hpp"


class Player {
private:
    std::string username;
    std::vector<Edge*> myRoads;
    std::vector<Vertex*> myBuildings;
    std::unordered_map<TileType, int> myResources;
    std::vector<Card*> myCards;
    int myPoints;
    int myKnights;
    bool longestRoad;
    int longestRoadLength; // New attribute to store longest road length

public:
    Player(const std::string& name);

    std::string getUsername() const;
    const std::vector<Edge*>& getMyRoads() const;
    const std::vector<Vertex*>& getMyBuildings() const;
    const std::unordered_map<TileType, int>& getMyResources() const;
    const std::vector<Card*>& getMyDevelopmentCards() const;
    int getMyPoints() const;
    int getNumOfResources() const;
    int getKnightCount() const;
    bool addRoad(Edge* road, bool isStartGame);
    bool addBuilding(Vertex* building, bool isCity, bool isStartGame);
    void addResources(TileType type, int amount);
    void addDevelopmentCard(Card* card);
    bool removeResourceForDevCard();
    void removeResources(TileType type, int amount);
    void removeDevelopmentCard(Card* card);
    void sevenPenalty();
    size_t rollDice();
    bool hasResourcesForRoad() const;
    bool hasResourcesForSettlement() const;
    bool hasResourcesForCity() const;
    bool hasResourcesForDevelopmentCard() const;
    bool operator==(const Player &other) const;
    void printMyResources() const;
    void printMyCards() const;
    friend std::ostream& operator<<(std::ostream &stream, const Player& player);

    // New methods for managing longest road
    void setLongestRoad(bool value);
    bool hasLongestRoad() const;
    int getLongestRoadLength() const;
    void calculateLongestRoad(); // Method to calculate the longest road
};

#endif // PLAYER_H
