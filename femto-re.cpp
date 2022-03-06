#include <iostream>
#include "token.h"
#include "parse.h"
#include "window.h"
#include "util.h"

int main() {
    debug("Hello, World!");
    Tokenizer tokenizer;
    std::istringstream str("<html><head></head><body><div>ABC</div></body></html>");
    Parser parser(tokenizer, str);
    parser.parse();
    std::cout << "parse finished" << std::endl;
    parser.document.body->paint();

    auto app = Gtk::Application::create();
    Window window(320, 240);
    return app->run(window);
}
