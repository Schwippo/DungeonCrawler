#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "../include/AbstractUI.h"

// forward declaration
class Tile;
class AbstractUI;

class Character {
    std::string texture;
    Tile* tile{nullptr};
    AbstractUI* ui{nullptr};

public:
    explicit Character(std::string texture);
    const std::string& getTexture() const;

    Tile* getTile() const;
    void setTile(Tile* t);

    // set UI für move-Delegation
    void setUI(AbstractUI* u);
    inline Input getNextMove();
};



#endif //CHARACTER_H
