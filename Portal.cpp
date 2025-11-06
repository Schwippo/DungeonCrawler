#include "Portal.h"

Portal::Portal(int row, int column)
    : Tile("O", row, column), destination(nullptr) {}

void Portal::setDestination(Tile* dest) { destination = dest; }

Tile* Portal::getDestination() const { return destination; }

Tile* Portal::onEnter(Tile* fromTile, Character* who) { return destination; }


