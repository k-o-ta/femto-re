#include <iostream>
#include <fstream>
#include <sstream>
#include "femto-re.h"
#include "token.h"
#include "parse.h"

int main() {
    debug("Hello, World!");
    BMP bmp;
    bmp.generate("ABC");
    Tokenizer tokenizer;
//    std::string input = "ABC";
    std::istringstream str("<html><head></head><body>ABC</body></html>");
    Parser parser;
    parser.parse(tokenizer, str);
//    tokenizer.tokenize(str);

    return 0;
}
