#ifndef WALL_H
#define WALL_H
#include "Tile.h"


class Wall : public Tile {
public:
    Wall(int row, int column);
    Tile* onEnter(Tile* fromTile, Character* who) override;
};



#endif //WALL_H
