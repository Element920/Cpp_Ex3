#include "Player.hpp"

Player::Player(const std::string& name)
    : username(name), myPoints(0), longestRoad(false), longestRoadLength(0) {}

std::string Player::getUsername() const {
    return username;
}

const std::vector<Edge*>& Player::getMyRoads() const {
    return myRoads;
}

const std::vector<Vertex*>& Player::getMyBuildings() const {
    return myBuildings;
}

const std::unordered_map<TileType, int>& Player::getMyResources() const {
    return myResources;
}

const std::vector<Card*>& Player::getMyDevelopmentCards() const {
    return myCards;
}

int Player::getKnightCount() const{
    return myKnights;
}


int Player::getMyPoints() const {
    return myPoints;
}

int Player::getNumOfResources() const {
    int totalResources = 0;
    for (const auto& resource : myResources) {
        totalResources += resource.second;
    }
    return totalResources;
}

bool Player::addRoad(Edge* road, bool isStartGame) {
    // Logic for adding a road
    // (Assuming there are checks for valid road placement)
    myRoads.push_back(road);
    return true;
}

bool Player::addBuilding(Vertex* building, bool isCity, bool isStartGame) {
    // Logic for adding a building
    // (Assuming there are checks for valid building placement)
    myBuildings.push_back(building);
    myPoints += isCity ? 2 : 1;
    return true;
}

void Player::addResources(TileType type, int amount) {
    myResources[type] += amount;
}

void Player::addDevelopmentCard(Card* card) {
    myCards.push_back(card);
}

bool Player::removeResourceForDevCard() {
    // Logic for removing resources needed to buy a development card
    return true;
}

void Player::removeResources(TileType type, int amount) {
    if (myResources[type] >= amount) {
        myResources[type] -= amount;
    }
}

void Player::removeDevelopmentCard(Card* card) {
    // Logic for removing a development card from player
}

void Player::sevenPenalty() {
    // Logic for penalty when rolling a 7
}

size_t Player::rollDice() {
    // Logic for rolling dice
    return 0;
}

bool Player::hasResourcesForRoad() const {
    // Logic to check if player has resources for a road
    return true;
}

bool Player::hasResourcesForSettlement() const {
    // Logic to check if player has resources for a settlement
    return true;
}

bool Player::hasResourcesForCity() const {
    // Logic to check if player has resources for a city
    return true;
}

bool Player::hasResourcesForDevelopmentCard() const {
    // Logic to check if player has resources for a development card
    return true;
}

bool Player::operator==(const Player &other) const {
    return username == other.username;
}

void Player::printMyResources() const {
    // Logic to print player resources
}

void Player::printMyCards() const {
    // Logic to print player cards
}

std::ostream& operator<<(std::ostream &stream, const Player& player) {
    // Logic for default printing of player using cout
    return stream;
}

void Player::setLongestRoad(bool value) {
    longestRoad = value;
}

bool Player::hasLongestRoad() const {
    return longestRoad;
}

int Player::getLongestRoadLength() const {
    return longestRoadLength;
}

void Player::calculateLongestRoad() {
    // Logic to calculate the longest road
    // This typically involves traversing the roads (edges) owned by the player
    // and finding the longest contiguous path of connected roads.
    // Update the longestRoadLength attribute accordingly.
    // Example:
    // Implement your own algorithm to find the longest road.
    // This is a placeholder to demonstrate the concept.
    // You may need to use graph traversal algorithms like DFS or BFS.

    // Example: Calculating longest road length using a simple algorithm
    int maxLength = 0;
    // Assuming roads are stored in myRoads vector
    for (Edge* road : myRoads) {
        int currentLength = 1; // Start with this road
        // Perform DFS or BFS to find the longest path
        // Example: DFS
        // Implement your DFS logic here
        // Update currentLength based on the traversal
        // Example: Simple traversal
        currentLength = std::max(currentLength, 1 + road->calculateLongestRoad());
        // Update maxLength if currentLength is greater
        maxLength = std::max(maxLength, currentLength);
    }
    longestRoadLength = maxLength;
}
