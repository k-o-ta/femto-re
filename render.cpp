//
// Created by koji on 3/4/22.
//

#include <iostream>
#include "render.h"
#include "util.h"

void Server::draw_text(std::string text, int x, int y, int width, int height) {
    m_signal_on_receive.emit(std::make_shared<ShowTextEvent>(ShowTextEvent{text, x, y}));
}

void RenderObject::layout() {
    if (done) { return; }

    int base_y = y;
    for (std::shared_ptr<RenderObject> child: children) {
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
    switch (node->kind) {
        case ND_TEXT:
            debug(std::to_string(y));
            server->draw_text(std::dynamic_pointer_cast<Text>(node)->data, x, y, 100, 100);
            break;
        default:
            for (auto child: children) {
                child->paint();
            }
            break;
    }
}
