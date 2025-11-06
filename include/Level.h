#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "Tile.h"
#include "Floor.h"
#include "Wall.h"
#include "Portal.h"
#include "../Character.h"

// Forward declaration
class Tile;
class Character;

class Level {
    int height;
    int width;

    // 2d grid out of Tile*
    std::vector<std::vector<Tile*>> grid;

    // character in levels
    std::vector<Character*> characters;

    bool inBounds(int r, int c) const {
        return r >= 0 && r < height && c >= 0 && c < width;
    }

public:
    // standard map (>= 4x4, portal pair, one character)
    Level();
    // delete Tiles and Characters
    ~Level();

    int getHeight() const;
    int getWidth() const;

    Tile* getTile(int row, int col);
    const Tile* getTile(int row, int col) const;
    void placeCharacter(Character* c, int row, int col);

    // access to one character in P1
    Character* getPlayer() const;
};



#endif //LEVEL_H
