#include "../include/DungeonCrawler.h"
#include "../include/Level.h"
#include "../include/TerminalUI.h"
#include "../include/Character.h"
#include "../include/Tile.h"

DungeonCrawler::DungeonCrawler()
    : level(new Level()), ui(new TerminalUI()) {
    // Character kennt seine UI (Delegation)
    if (auto* p = level->getPlayer()) p->setUI(ui);
    ui->draw(level);
}

DungeonCrawler::~DungeonCrawler() {
    delete ui;
    delete level;
}

Level *DungeonCrawler::getLevel() const { return level; }

bool DungeonCrawler::turn() {
    auto* player = level->getPlayer();
    if (!player) return false;

    // 1) Eingabe
    Input in = player->getNextMove();
    if (in.quit) return false;

    // 2) Zielkachel berechnen
    int r = player->getTile()->getRow() + in.dr;
    int c = player->getTile()->getColumn() + in.dc;
    auto* dest = level->getTile(r, c);

    // 3) Bewegung ausführen, falls innerhalb des levels
    if (dest) {
        player->getTile()->moveTo(dest, player);
    }

    // 4) Neu zeichnen
    ui->draw(level);
    return true;
}


