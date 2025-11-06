#include "../include/Character.h"

Character::Character(std::string texture)
    : texture(std::move(texture)), tile(nullptr) {}

const std::string &Character::getTexture() const { return texture; }

Tile *Character::getTile() const { return tile;}
void Character::setTile(Tile *t) { tile = t; }


