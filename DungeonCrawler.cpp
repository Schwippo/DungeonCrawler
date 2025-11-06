#include "DungeonCrawler.h"

DungeonCrawler::DungeonCrawler()
    : ui(new TerminalUI()), level(new Level()) {
    ui->setController(this);

    // game start
    ui->draw(level);
}
DungeonCrawler::~DungeonCrawler() {
    delete ui;
    delete level;
}

Level *DungeonCrawler::getLevel() const { return level; }

void DungeonCrawler::directionToDelta(int movingDir, int& dr, int& dc) {
    // numpad layout
    // 7 8 9
    // 4 5 6
    // 1 2 3
    dr = 0; dc = 0;
    switch (movingDir) {
        case 7: dr = -1; dc = -1; break;
        case 8: dr = -1; dc =  0; break;
        case 9: dr = -1; dc = +1; break;
        case 4: dr =  0; dc = -1; break;
        case 5: dr =  0; dc =  0; break;
        case 6: dr =  0; dc = +1; break;
        case 1: dr = +1; dc = -1; break;
        case 2: dr = +1; dc =  0; break;
        case 3: dr = +1; dc = +1; break;
        default: dr = 0; dc = 0; break;
    }
}

void DungeonCrawler::turn(int movingDir) {
    if (movingDir == 0) return; // end

    Character* who = level->getPlayer();
    if (!who || !who->getTile()) {
        ui->draw(level);
        return;
    }

    int dr, dc;
    directionToDelta(movingDir, dr, dc);

    int r = who->getTile()->getRow();
    int c = who->getTile()->getColumn();
    int nr = r + dr;
    int nc = c + dc;

    Tile* current = who->getTile();
    Tile* destination = level->getTile(nr, nc);

    if (destination) {
        current->moveTo(destination, who);
    }
    // out of bounds -> no movement

    // draw new + next input
    ui->draw(level);
}


