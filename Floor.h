#ifndef FLOOR_H
#define FLOOR_H
#include "Tile.h"


class Floor : public Tile {
public:
    Floor(int row, int column);

    Tile* onEnter(Tile* fromTile, Character* who) override;
};



#endif //FLOOR_H
