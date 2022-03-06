//
// Created by koji on 2/20/22.
//

#ifndef FEMTO_RE_UTIL_H
#define FEMTO_RE_UTIL_H

#include <iostream>
#include <fstream>

#define debug(m) debug_message(m, __FILE__, __LINE__)
void debug_message(std::string message, const char *file, int line);
#endif //FEMTO_RE_UTIL_H
