//
// Created by koji on 3/4/22.
//

#include "render.h"


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

//RenderObject::RenderObject() {
//
//}
