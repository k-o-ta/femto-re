//
// Created by koji on 2/20/22.
//

#include <string>
#include <iostream>

void debug_message(std::string message, const char *file, int line) {
    std::cout << message << " at" << file << ":" << line << std::endl;
}
