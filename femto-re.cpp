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
    std::istringstream str("<html><head></head><body><div>ABC</div></body></html>");
    Parser parser(tokenizer, str);
    parser.parse();
    std::cout << "parse finished" << std::endl;
//    Hoo hoo{};
//    hoo.print();
    parser.document.paint();
//    tokenizer.tokenize(str);

    return 0;
}
