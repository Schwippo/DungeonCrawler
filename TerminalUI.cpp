#include "TerminalUI.h"
#include <iostream>

void TerminalUI::printLevel(Level* level) {
    for (int r = 0; r < level->getHeight(); ++r) {
        for (int c = 0; c < level->getWidth(); ++c) {
            const Tile* t = level->getTile(r, c);
            std::cout << t->getTexture();
        }
        std::cout << "\n";
    }
}

int TerminalUI::readDirection() {
    std::cout << "\nBewegung (Ziffernblock 1-9, 5=stehen, 0=Ende): ";
    int direction = -1;

    if (!(std::cin >> direction)) {
        // input error -> stay in position
        std::cin.clear();
        std::string dump;
        std::getline(std::cin, dump);
        return 5;
    }
    return direction;
}

void TerminalUI::draw(Level* level) {
    printLevel(level);
    int direction = readDirection();
    if (direction == 0) {
        // end programm
        return;
    }
    if (controller) {
        controller->turn(direction);
    }
}



