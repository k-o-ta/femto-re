//
// Created by koji on 1/9/22.
//

#include <cassert>
#include "parse.h"

Node Parser::parse(Tokenizer tokenizer, std::istream& istream) {
    auto token = tokenizer.tokenize(istream);

    auto html_element = parse_at_initial(token);


    // https://html.spec.whatwg.org/multipage/parsing.html#the-before-html-insertion-mode
    insertion_mode = MD_IN_BODY;
    while(token) {
        switch(token->kind) {
            case TK_START_TAG:
                if (token->start_tag.value().name == "div") {

                }
                break;

        }
        token = token->next;
    }
}

Node Parser::parse_at_initial(std::shared_ptr<Token> token) {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-initial-insertion-mode
    assert(insertion_mode == MD_INITIAL);
    insertion_mode = MD_BEFORE_HTML;

    return parse_at_before_html(token);
}

Node Parser::parse_at_before_html(std::shared_ptr<Token> token) {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-before-html-insertion-mode
    assert(insertion_mode == MD_BEFORE_HTML);

    // https://html.spec.whatwg.org/multipage/parsing.html#create-an-element-for-the-token
    auto html = Html {};
    html.parent_node = &html;
    document.document_element = std::make_shared<Element>(html);
    stack_of_open_elements.push_back(std::make_shared<Element>(html));

    insertion_mode = MD_BEFORE_HEAD;

    return parse_at_before_head(token);
}

Node Parser::parse_at_before_head(std::shared_ptr<Token> token) {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-before-head-insertion-mode
    assert(insertion_mode == MD_BEFORE_HEAD);
    if (token->kind == TK_START_TAG && token->start_tag.value().name == "head") {
        auto head_element = Element{"head"};
        head_element_pointer = std::make_shared<Element>(head_element);
        insert_html_element_for_the_token(head_element_pointer);
        insertion_mode = MD_IN_HEAD;

        token = token->next;
        return parse_at_in_head(token);
    }
}

Node Parser::parse_at_in_head(std::shared_ptr<Token> token) {
    // https://html.spec.whatwg.org/multipage/parsing.html#parsing-main-inhead
    assert(insertion_mode == MD_IN_HEAD);

    if (token->kind == TK_START_TAG && token->start_tag.value().name == "head") {
        stack_of_open_elements.pop_back();
        insertion_mode = MD_AFTER_HEAD;

        token = token->next;
        return parse_at_after_head(token);
    }

}

Node Parser::parse_at_after_head(std::shared_ptr<Token> token) {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-after-head-insertion-mode
    assert(insertion_mode == MD_AFTER_HEAD);

    if (token->kind == TK_START_TAG && token->start_tag.value().name == "body") {
       auto body_element = Element{"body"};
       auto body_element_pointer = std::make_shared<Element>(body_element);
       insert_html_element_for_the_token(body_element_pointer);
       insertion_mode = MD_IN_BODY;
       token =  token->next;
       return parse_at_in_body(token);
    }
}

Node Parser::parse_at_in_body(std::shared_ptr<Token> token) {
    // https://html.spec.whatwg.org/multipage/parsing.html#parsing-main-inbody
    assert(insertion_mode == MD_IN_BODY);

}

void Parser::insert_html_element_for_the_token(std::shared_ptr<Element> element) {
    // https://www.w3.org/TR/2011/WD-html5-20110113/tokenization.html#insert-an-html-element
    current_node()->child_nodes.push_back(element);
    stack_of_open_elements.push_back(element);
}

std::shared_ptr<Node> Parser::current_node() {
    return stack_of_open_elements[stack_of_open_elements.size() - 1];
}

