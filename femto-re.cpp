#include <iostream>
#include <fstream>
#include <sstream>
#include "femto-re.h"
#include "token.h"
#include "parse.h"
#include "bmp.h"
#include "util.h"

int main() {
    debug("Hello, World!");
    Tokenizer tokenizer;
    std::istringstream str("<html><head></head><body><div>ABC</div></body></html>");
    Parser parser(tokenizer, str);
    parser.parse();
    std::cout << "parse finished" << std::endl;
    parser.document.body->paint();

    return 0;
}
