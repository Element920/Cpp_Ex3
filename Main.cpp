#include <iostream>
#include <vector>
#include "Game.hpp"

int main() {
    std::vector<std::string> playerNames = { "Alice", "Bob", "Charlie" };
    Game game(playerNames);

    game.startGame();
    game.printGameState();

    return 0;
}
