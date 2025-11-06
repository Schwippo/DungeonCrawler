#include "../include/Tile.h"

Tile::Tile(std::string texture, int row, int column)
    : texture(std::move(texture)), character(nullptr), row(row), column(column) {}

const std::string& Tile::getBaseTexture() const { return texture; }
bool Tile::hasCharacter() const { return character != nullptr; }

Character* Tile::getCharacter() const { return character; }
void Tile::setCharacter(Character* c) { character = c; }

int Tile::getRow() const { return row; }
int Tile::getColumn() const { return column; }

std::string Tile::getTexture() const {
    if (character)
        return character->getTexture();
}

bool Tile::moveTo(Tile *destTile, Character *who) {
    if (!destTile || !who)
        return false;

    // check if kachel can be left
    Tile* left = onLeave(destTile, who);
    if (left == nullptr)
        return false;

    // check which kachel is joined (floor: this, wall: nullptr, portal:: destPortal)
    Tile* entered = destTile->onEnter(left, who);
    if (entered == nullptr)
        return false;

    // change character from left to join
    if (left->getCharacter() == who) {
        left->setCharacter(nullptr);
    }
    entered->setCharacter(who);
    who->setTile(entered);
    return true;
}

Tile *Tile::onLeave(Tile *destTile, Character *who) {
    // in P1 always allowed
    return this;
}




