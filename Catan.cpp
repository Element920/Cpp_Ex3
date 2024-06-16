#include "Catan.hpp"
#include <iostream>
#include "Board.hpp"

Catan::Catan(Player& p1, Player& p2, Player& p3)
    : players({p1, p2, p3}), board(), currentPlayerIndex(0) {}

void Catan::ChooseStartingPlayer() {
    std::cout << "Starting player: " << players[currentPlayerIndex].getUsername() << std::endl;
}

Board& Catan::getBoard() {
    return board;
}

void Catan::placeInitialSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
    // Logic to place initial settlement
    // (Assume implementation here, including validity checks)
}

void Catan::placeInitialRoad(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
    // Logic to place initial road
    // (Assume implementation here, including validity checks)
}

void Catan::rollDice(Player& player) {
    size_t diceRoll = player.rollDice();
    std::cout << player.getUsername() << " rolled " << diceRoll << std::endl;

    // Logic to distribute resources based on dice roll
    // (Assume implementation here)
}

void Catan::trade(Player& offerer, Player& receiver, const std::string& offerResource, const std::string& receiveResource, int offerAmount, int receiveAmount) {
    // Logic for player trade
    // (Assume implementation here, including validity checks)
}

void Catan::buyDevelopmentCard(Player& player) {
    if (player.hasResourcesForDevelopmentCard()) {
        player.removeResourceForDevCard();
        // Logic to give a development card to the player
        // (Assume implementation here)
    }
}

void Catan::endTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    std::cout << "Turn ended. Next player: " << players[currentPlayerIndex].getUsername() << std::endl;
}

void Catan::printWinner() const {
    for (const auto& player : players) {
        if (player.getMyPoints() >= 10) {
            std::cout << player.getUsername() << " wins!" << std::endl;
            return;
        }
    }
    std::cout << "None of the players reached 10 points. No winner yet." << std::endl;
}
