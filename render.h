//
// Created by koji on 3/4/22.
//

#ifndef FEMTO_RE_RENDER_H
#define FEMTO_RE_RENDER_H


#include <memory>
#include <vector>
#include "node.h"
#include "event.h"
#include <sigc++/sigc++.h>

class Server {
public:
    typedef sigc::signal<void, std::string , int, int, int, int> type_signal_something;
    type_signal_something m_signal_something;
    typedef sigc::signal<void, std::shared_ptr<Event>> type_signal_on_receive;
    type_signal_on_receive m_signal_on_receive;
    void draw_text(std::string text, int x, int y, int width, int height);
    void draw_text2(std::string text, int x, int y, int width, int height);
    Server();
};

class RenderObject {
public:
    std::shared_ptr<Server> server;
    std::vector<std::shared_ptr<RenderObject>> children;
    std::shared_ptr<RenderObject> parent;
    std::shared_ptr<Node> node;
    void layout();
    void paint();
    int x{};
    int y{};
    int width{};
    int height{};
    bool done;

//    explicit RenderObject();
    RenderObject(std::shared_ptr<Node>);
};


#endif //FEMTO_RE_RENDER_H
