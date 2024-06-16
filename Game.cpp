#include "Game.hpp"

Game::Game(const std::vector<std::string>& playerNames) : longestRoadPlayer(nullptr), largestArmyPlayer(nullptr) {
    for (const auto& name : playerNames) {
        players.emplace_back(name);
    }
}

void Game::updateLongestRoad(Player* player) {
    int playerLongestRoad = player->calculateLongestRoad();
    if (!longestRoadPlayer || playerLongestRoad > longestRoadPlayer->calculateLongestRoad()) {
        if (longestRoadPlayer) {
            longestRoadPlayer->setLongestRoad(false);
        }
        longestRoadPlayer = player;
        player->setLongestRoad(true);
    }
}

void Game::updateLargestArmy(Player* player) {
    if (!largestArmyPlayer || player->getKnightCount() > largestArmyPlayer->getKnightCount()) {
        if (largestArmyPlayer) {
            largestArmyPlayer->setLargestArmy(false);
        }
        largestArmyPlayer = player;
        player->setLargestArmy(true);
    }
}

void Game::playKnightCard(Player* player) {
    player->playKnightCard();
    updateLargestArmy(player);
}

void Game::rollDiceAndDistributeResources() {
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(1, 6);
    int diceSum = distribution(generator) + distribution(generator);

    for (auto& player : players) {
        for (auto& building : player.getMyBuildings()) {
            for (auto tile : building->getAdjacentTiles()) {
                if (tile->getNumber() == diceSum) {
                    player.addResources(tile->getType(), building->getBuildingType() == BuildingType::City ? 2 : 1);
                }
            }
        }
    }
}

void Game::startGame() {
    // Game initialization and main loop
}

void Game::printGameState() const {
    for (const auto& player : players) {
        std::cout << player << std::endl;
        player.printMyResources();
        player.printMyCards();
        std::cout << std::endl;
    }
}
