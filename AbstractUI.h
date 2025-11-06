#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

class Level;
class DungeonCrawler;

class AbstractUI {
protected:
    DungeonCrawler* controller = nullptr;

public:
    virtual ~AbstractUI() = default;
    virtual void draw(Level* level) = 0;

    // back reference so that UI turn(dir) can call controller
    void setController(DungeonCrawler* c) { controller = c; }
};



#endif //ABSTRACTUI_H
