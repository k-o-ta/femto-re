#include <iostream>
#include "token.h"
#include "parse.h"
#include "window.h"
#include "util.h"

#include <sigc++/sigc++.h>
#include <thread>

class Server2
{
public:
    Server2();
    virtual ~Server2();

    void do_something();

    //signal accessor:
    typedef sigc::signal<void, std::string, int, int, int, int> type_signal_something2;
    type_signal_something2 signal_something2();

protected:
    type_signal_something2 m_signal_something;
};

class Client2 : public sigc::trackable
{
public:
    Client2();
    virtual ~Client2();

    //Signal handler:
    void on_server_something(std::string text, int a, int b, int c, int d);
};

Server2::Server2()
{
}

Server2::~Server2()
{
}

Server2::type_signal_something2 Server2::signal_something2()
{
    return m_signal_something;
}

void Server2::do_something()
{
    m_signal_something.emit("foobarbuzz", 0, 5, 10, 15);
}

Client2::Client2()
{
}

Client2::~Client2()
{
}

void Client2::on_server_something(std::string text, int a, int b, int c, int d)
{
    std::cout << "Client::on_server_something() called with these parameters: "
              << text << a << ", " << b << std::endl;
}



int main() {
    debug("Hello, World!");

    Server2 server2;
    Client2 client2;
    //Connect a Server signal to the signal handler in Client.
//    server2.signal_something2().connect(sigc::mem_fun(client2,
//                                                    &Client2::on_server_something) );

    std::cout << "Before Server::do_something()" << std::endl;

    //Tell the server to do something that will eventually cause it to emit the
    //"something" signal.
    server2.do_something();    // Client::on_server_something() will run before
    // Server::do_something() has completed.

    std::cout << "After Server::do_something()" << std::endl;


    Tokenizer tokenizer;
    std::istringstream str("<html><head></head><body><div>ABC</div></body></html>");
    Parser parser(tokenizer, str);

    auto app = Gtk::Application::create();
    Window window(320, 240);
//    MyArea myArea;
//    Gtk::DrawingArea myArea;
//    auto w = myArea.get_window();
//    auto w2 = window.get_window();
    auto server = std::make_shared<Server>();

//    Client client{};
    server->m_signal_something.connect(sigc::mem_fun(window.m_area, &MyArea::on_server_something));

    std::thread t([&]{
        sleep(1);
        parser.parse(server);
        std::cout << "parse finished" << std::endl;

        parser.render_root->layout();
        parser.render_root->paint();

    });
//    parser.document.body->paint();

    std::cout << "print foo" << std::endl;
//    Cairo::RefPtr<Cairo::Context> my_context = window.m_area.get_window()->create_cairo_context();
    app->run(window);
//    std::cout << "print bar" << std::endl;
   return 0;
}
