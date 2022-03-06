//
// Created by koji on 1/9/22.
//

#ifndef FEMTO_RE_PARSE_H
#define FEMTO_RE_PARSE_H

#include <vector>
#include "token.h"
#include "node.h"
#include "render.h"

enum InsertionMode {
    MD_INITIAL,
    MD_BEFORE_HTML,
    MD_BEFORE_HEAD,
    MD_IN_HEAD,
    MD_AFTER_HEAD,
    MD_IN_BODY,
    MD_AFTER_BODY,
    MD_AFTER_AFTER_BODY
};

class Parser {
public:
    Document document;
    // https://html.spec.whatwg.org/multipage/parsing.html#the-insertion-mode
    InsertionMode insertion_mode = {MD_INITIAL};
    void parse();
    std::shared_ptr<Element> head_element_pointer;
    explicit Parser(Tokenizer tokenizer, std::istream& istream): tokenizer(tokenizer), istream(istream) {}
    std::shared_ptr<RenderObject> render_root;
    std::shared_ptr<RenderObject> latest_render_object;

private:
    Tokenizer tokenizer;
    std::istream& istream;
    std::shared_ptr<Token> token;
    std::vector<std::shared_ptr<Element>> stack_of_open_elements;
    void parse_at_initial();
    void parse_at_before_html();
    HTMLHeadElement parse_at_before_head();
    void parse_at_in_head(HTMLHeadElement& head_element);
    std::shared_ptr<HTMLBodyElement> parse_at_after_head();
    void parse_at_in_body(std::shared_ptr<HTMLBodyElement> body_element_pointer);
    void parse_at_after_body();
    void parse_at_after_after_body();
    std::shared_ptr<Node> current_node();
    void insert_html_element_for_the_token(std::shared_ptr<Element> element);

};

#endif //FEMTO_RE_PARSE_H
