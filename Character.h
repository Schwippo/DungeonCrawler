#ifndef CHARACTER_H
#define CHARACTER_H
#include "Tile.h"

// forward declaration
class Tile;

class Character {
    Tile* tile;
    std::string texture;

public:
    Character(std::string texture);

    const std::string& getTexture() const;

    Tile* getTile() const;
    void setTile(Tile* t);
};



#endif //CHARACTER_H
