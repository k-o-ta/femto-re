//
// Created by koji on 3/3/22.
//

#ifndef FEMTO_RE_COMMAND_H
#define FEMTO_RE_COMMAND_H


#include <string>

class Command {
};

class ShowTextCommand: public Command {
public:
    ShowTextCommand(std::string text);
};


#endif //FEMTO_RE_COMMAND_H
