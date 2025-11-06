#include "Level.h"

#include <cassert>

Level::Level()
    : height(5), width(5), grid(height, std::vector<Tile*>(width, nullptr)) {

    // test field: wall and floor
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            bool border = (r == 0 || c == 0 || r == height - 1|| c == width - 1);
            grid[r][c] = border ? static_cast<Tile*>(new Wall(r, c)) : static_cast<Tile*>(new Floor(r, c));
        }
    }

    // portal pair
    auto* p1 = new Portal(1, 1);
    auto p2 = new Portal(3, 3);
    grid[1][1] = p1;
    grid[3][3] = p2;
    p1->setDestination(p2);
    p2->setDestination(p1);

    // place a character in the middle
    auto* hero = new Character("X");
    characters.push_back(hero);
    placeCharacter(hero, 2, 2);
}

Level::~Level() {
    // delete characters
    for (Character* c : characters) {
        delete c;
    }
    characters.clear();

    // delete Tiles
    for (auto& row : grid) {
        for (Tile* t : row) {
            delete t;
        }
    }
    grid.clear();
}

Tile* Level::getTile(int row, int col) {
    if (!inBounds(row, col))
        return nullptr;
    return grid[row][col];
}

const Tile *Level::getTile(int row, int col) const {
    if (!inBounds(row, col))
        return nullptr;
    return grid[row][col];
}

void Level::placeCharacter(Character* c, int row, int col) {
    // QUESTION ?!??!?!?!?!??!?!??!
    assert(c != nullptr);
    Tile* t = getTile(row, col);
    if (!t)
        return; // out of bounds

    // without onEnter
    if (c->getTile()) {
        // clear kachel
        if (c->getTile()->getCharacter() == c) {
            c->getTile()->setCharacter(nullptr);
        }
    }
    t->setCharacter(c);
    c->setTile(t);
}

int Level::getHeight() const { return height; }
int Level::getWidth() const { return width; }

Character *Level::getPlayer() const {
    return characters.empty() ? nullptr : characters.front();
}

