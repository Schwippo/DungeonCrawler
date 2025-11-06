#ifndef PORTAL_H
#define PORTAL_H
#include "Tile.h"


class Portal : public Tile {
    Tile* destination;

public:
    Portal(int row, int column);

    void setDestination(Tile* dest);
    Tile* getDestination() const;

    Tile* onEnter(Tile* fromTile, Character* who) override;
};



#endif //PORTAL_H
