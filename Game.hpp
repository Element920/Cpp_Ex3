#ifndef GAME_H
#define GAME_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include "Player.hpp"
#include "Board.hpp"




class Game {
private:
    std::vector<Player> players;
    Player* longestRoadPlayer;
    Player* largestArmyPlayer;
    Board board;

public:
    Game(const std::vector<std::string>& playerNames);
    void updateLongestRoad(Player* player);
    void updateLargestArmy(Player* player);
    void playKnightCard(Player* player);
    void rollDiceAndDistributeResources();
    void startGame();
    void printGameState() const;
};

#endif // GAME_H
