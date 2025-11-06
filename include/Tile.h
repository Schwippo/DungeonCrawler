#ifndef TILE_H
#define TILE_H
#include <string>
#include "Character.h"

// Forward Declaration WHY???
class Character;

// abstract class
class Tile {
protected:
    std::string texture;
    Character* character;
    const int row;
    const int column;

public:
    Tile(std::string texture, int row, int column);
    virtual ~Tile() = default;

    virtual bool moveTo(Tile* destTile, Character* who);
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who);

    // getter methods
    const std::string& getBaseTexture() const; // base texture
    virtual std::string getTexture() const; // character texture

    bool hasCharacter() const;

    Character* getCharacter() const;
    void setCharacter(Character* c);

    int getRow() const;
    int getColumn() const;
};



#endif //TILE_H
