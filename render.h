//
// Created by koji on 3/4/22.
//

#ifndef FEMTO_RE_RENDER_H
#define FEMTO_RE_RENDER_H


#include <memory>
#include <vector>
#include "node.h"

class RenderObject {
public:
    std::vector<std::shared_ptr<RenderObject>> children;
    std::shared_ptr<RenderObject> parent;
    std::shared_ptr<Node> node;
    void layout();
    int x{};
    int y{};
    int width{};
    int height{};
    bool done;

//    explicit RenderObject();
    explicit RenderObject(std::shared_ptr<Node>): node{node}, done(false) {};
};


#endif //FEMTO_RE_RENDER_H
