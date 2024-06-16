#ifndef CATAN_H
#define CATAN_H

#include <vector>
#include "Player.hpp"
#include "Board.hpp"

class Catan {
private:
    std::vector<Player> players;
    Board board;
    size_t currentPlayerIndex;

public:
    Catan(Player& p1, Player& p2, Player& p3);

    void ChooseStartingPlayer();

    Board& getBoard();

    void placeInitialSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);
    
    void placeInitialRoad(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);

    void rollDice(Player& player);

    void trade(Player& offerer, Player& receiver, const std::string& offerResource, const std::string& receiveResource, int offerAmount, int receiveAmount);

    void buyDevelopmentCard(Player& player);

    void endTurn();

    void printWinner() const;
};

#endif // CATAN_H
