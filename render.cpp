//
// Created by koji on 3/4/22.
//

#include <iostream>
#include "render.h"

Server::Server() {

}

void Server::draw_text(std::string text, int x, int y, int width, int height) {
    m_signal_something.emit(text, x, y, width, height);
}

void Server::draw_text2(std::string text, int x, int y, int width, int height) {
    m_signal_on_receive.emit(std::make_shared<ShowTextEvent>(ShowTextEvent{text}));
}

RenderObject::RenderObject(std::shared_ptr<Node> node): node{node}, done{false} {
    std::cout << "constructor" << std::endl;
}
void RenderObject::layout() {
    if (done) {
        return;
    }

    int base_y = y;
    for(std::shared_ptr<RenderObject> child: children) {
        child->y = base_y;
        child->layout();
        height = height + child->height;
        base_y = child->y + child->height;
    }
    done = true;

//    if (node) {
//        for(std::shared_ptr<Node> n: node->child_nodes) {
//            RenderObject r{x, y};
//            r.layout();
//            height = r.y + r.height;
//        }
//    }
}

void RenderObject::paint() {
    switch(node->kind) {
        case ND_TEXT:
//            server->draw_text(std::dynamic_pointer_cast<Text>(node)->data, 0, 0, 100, 100);
            server->draw_text2(std::dynamic_pointer_cast<Text>(node)->data, 0, 0, 100, 100);
            break;
        default:
            for (auto child: children) {
                child->paint();
            }
            break;
    }
}
//RenderObject::RenderObject() {
//
//}
