#include "Floor.h"

Floor::Floor(int row, int column)
    : Tile(".", row, column) {}

Tile *Floor::onEnter(Tile *fromTile, Character *who) {
    return this;
}
