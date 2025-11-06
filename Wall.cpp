#include "Wall.h"

Wall::Wall(int row, int column)
    : Tile("#", row, column) {}

Tile *Wall::onEnter(Tile *fromTile, Character *who) {
    return nullptr;
}

