//
// Created by koji on 1/1/22.
//


#ifndef FEMTO_RE_ALPHABETS_H
#define FEMTO_RE_ALPHABETS_H

#include <vector>
#include <iostream>
#include <fstream>

#define debug(m) debug_message(m, __FILE__, __LINE__)
void debug_message(std::string message, const char *file, int line) {
    std::cout << message << " at" << file << ":" << line << std::endl;
}

#endif //FEMTO_RE_ALPHABETS_H
