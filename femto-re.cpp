#include <iostream>
#include "token.h"
#include "parse.h"
#include "window.h"
#include "util.h"

#include <sigc++/sigc++.h>
#include <thread>

int main() {
    Tokenizer tokenizer;
    std::istringstream str("<html><head></head><body><div>ABC</div></body></html>");
    Parser parser(tokenizer, str);

    auto app = Gtk::Application::create();
    Window window(320, 240);
    auto server = std::make_shared<Server>();

    server->m_signal_on_receive.connect(sigc::mem_fun(window.m_area, &MyArea::on_receive_event));

    std::thread t([&]{
        parser.parse(server);

        parser.render_root->layout();
        parser.render_root->paint();
    });

   return app->run(window);
}
