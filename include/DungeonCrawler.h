#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "AbstractUI.h"
#include "TerminalUI.h"
#include "Level.h"
#include "Character.h"
#include "Tile.h"

#include <cstdlib>

class Level;
class AbstractUI;
class Input;
class Character;

class DungeonCrawler {
    Level* level;
    AbstractUI* ui;

public:
    DungeonCrawler();
    ~DungeonCrawler();

    // genau eine Runde, false bei Spielende
    bool turn();

    Level* getLevel() const;
};



#endif //DUNGEONCRAWLER_H
