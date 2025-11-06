#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "AbstractUI.h"
#include "Level.h"
#include "Tile.h"
#include "Character.h"
#include "DungeonCrawler.h"

#include <iostream>
#include <string>


class TerminalUI : public AbstractUI {
    void printLevel(Level* level);
    int readDirection();

public:
    void draw(Level* level) override;
};



#endif //TERMINALUI_H
