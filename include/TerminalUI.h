#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "../include/AbstractUI.h"

#include <iostream>
#include <string>


class TerminalUI : public AbstractUI {
public:
    void draw(Level* level) override;
    Input move() override;
};



#endif //TERMINALUI_H
