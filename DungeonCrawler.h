#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "AbstractUI.h"
#include "TerminalUI.h"
#include "Level.h"
#include "Character.h"
#include "Tile.h"

#include <cstdlib>

class AbstractUI;
class Level;

class DungeonCrawler {
    AbstractUI* ui;
    Level* level;

    // helping function: calculate row/col out of movingDir
    static void directionToDelta(int movingDir, int& dr, int& dc);

public:
    DungeonCrawler();
    ~DungeonCrawler();

    void turn(int movingDir);
    Level* getLevel() const;
};



#endif //DUNGEONCRAWLER_H
