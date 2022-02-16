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
    ND_DOCUMENT,
    ND_HTML,
    ND_HEAD,
    ND_BODY,
    ND_DIV,
    ND_CHARACTER_DATA,
    ND_TEXT
};

//class Hoo {
//public:
//    std::vector<std::shared_ptr<int>> bar;
//    void print();
//    virtual ~Hoo(void) {
//        std::cout << "destructure Hoo" << std::endl;
//    }
//};

class HTMLHeadElement;
class HTMLBodyElement;

class Node {
public:
    std::vector<std::shared_ptr<Node>> child_nodes;
    NodeKind kind;
    explicit Node(NodeKind kind): kind(kind) {}
    void paint();
    virtual ~Node(void) {}
};
class Element: public Node {
public:
    std::optional<Node*> parent_node;
    std::string tag_name;
    explicit Element(std::string tag_name, NodeKind kind): tag_name(std::move(tag_name)), Node(kind) {}
};

// https://html.spec.whatwg.org/multipage/dom.html#the-document-object
// https://dom.spec.whatwg.org/#interface-document
// https://developer.mozilla.org/ja/docs/Web/API/Document
// https://dom.spec.whatwg.org/#introduction-to-the-dom
// https://html.spec.whatwg.org/multipage/dom.html#document
class Document: public Node {
public:
    std::shared_ptr<Element> document_element;
    explicit Document(): Node{ND_DOCUMENT} {}
    HTMLHeadElement *head;
    std::shared_ptr<HTMLBodyElement> body;
};

class HtmlElement: public Element {
public:
    explicit HtmlElement(std::string tag_name, NodeKind kind): Element{tag_name, kind} {}
};

// https://html.spec.whatwg.org/multipage/semantics.html#the-html-element
class HTMLHtmlElement: public HtmlElement {
public:
    explicit HTMLHtmlElement(): HtmlElement("html", ND_HTML) {}
};
// https://html.spec.whatwg.org/multipage/semantics.html#the-head-element
class HTMLHeadElement: public HtmlElement {
public:
    explicit HTMLHeadElement(): HtmlElement("head", ND_HEAD) {}
};
// https://html.spec.whatwg.org/multipage/sections.html#the-body-element
class HTMLBodyElement: public HtmlElement {
public:
    explicit HTMLBodyElement(): HtmlElement{"body", ND_BODY} {}
};

class HtmlDivElement: public HtmlElement {
public:
    explicit HtmlDivElement(): HtmlElement{"div", ND_DIV} {}
};
class Body: public Node {};
class Div: public Node {};

class CharacterData: public Node {
public:
    std::string data;
    explicit CharacterData(): Node { ND_CHARACTER_DATA} {}
    explicit CharacterData(NodeKind kind): Node { kind} {}

    void paint();
};
class Text: public CharacterData {
public:
//    int v;
    explicit Text(): CharacterData{ND_TEXT} {}

    void paint();
};

#endif //FEMTO_RE_NODE_H
