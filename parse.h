//
// Created by koji on 1/9/22.
//

#ifndef FEMTO_RE_PARSE_H
#define FEMTO_RE_PARSE_H

#include <vector>
#include "token.h"
#include "node.h"

enum InsertionMode {
    MD_INITIAL,
    MD_BEFORE_HTML,
    MD_BEFORE_HEAD,
    MD_IN_HEAD,
    MD_AFTER_HEAD,
    MD_IN_BODY
};

class Parser {
public:
    Document document;
    // https://html.spec.whatwg.org/multipage/parsing.html#the-insertion-mode
    InsertionMode insertion_mode = {MD_INITIAL};
    Node parse(Tokenizer tokenizer, std::istream& istream);
    std::shared_ptr<Element> head_element_pointer;

private:
    std::vector<std::shared_ptr<Element>> stack_of_open_elements;
    Node parse_at_initial(std::shared_ptr<Token> token);
    Node parse_at_before_html(std::shared_ptr<Token> token);
    Node parse_at_before_head(std::shared_ptr<Token> token);
    Node parse_at_in_head(std::shared_ptr<Token> token);
    Node parse_at_after_head(std::shared_ptr<Token> token);
    Node parse_at_in_body(std::shared_ptr<Token> token);
    std::shared_ptr<Node> current_node();
    void insert_html_element_for_the_token(std::shared_ptr<Element> element);
};

#endif //FEMTO_RE_PARSE_H
