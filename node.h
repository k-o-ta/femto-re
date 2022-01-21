//
// Created by koji on 1/9/22.
//

#ifndef FEMTO_RE_NODE_H
#define FEMTO_RE_NODE_H

#include <memory>
#include <optional>
#include <utility>
#include <vector>

enum NodeKind {
    ND_BODY,
    ND_DIV,
    ND_TEXT
};

class Node {
public:
    std::vector<std::shared_ptr<Node>> child_nodes;
};
class Element: public Node {
public:
    std::optional<Node*> parent_node;
    std::string tag_name;
    explicit Element(std::string tag_name): tag_name(std::move(tag_name)) {}
};

// https://html.spec.whatwg.org/multipage/dom.html#the-document-object
// https://dom.spec.whatwg.org/#interface-document
class Document: Node {
public:
    std::shared_ptr<Element> document_element;
};

class Html: public Element {};
class Body: public Node {};
class Div: public Node {};
class Text: public Node {};
#endif //FEMTO_RE_NODE_H
