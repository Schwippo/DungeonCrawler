#include <iostream>
#include "../include/DungeonCrawler.h"

int main() {
    DungeonCrawler game;
    while (true) {
        if (!game.turn()) break;
    }

    std::cout << "Spiel beendet\n";
    return 0;
}