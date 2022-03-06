//
// Created by koji on 1/9/22.
//

#include <cassert>
#include <iostream>
#include "parse.h"
#include "render.h"

void Parser::parse() {
    token = tokenizer.tokenize(istream);

    parse_at_initial();
}

void Parser::parse_at_initial() {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-initial-insertion-mode
    assert(insertion_mode == MD_INITIAL);
    insertion_mode = MD_BEFORE_HTML;

    return parse_at_before_html();
}

void Parser::parse_at_before_html() {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-before-html-insertion-mode
    assert(insertion_mode == MD_BEFORE_HTML);

    // https://html.spec.whatwg.org/multipage/parsing.html#create-an-element-for-the-token
    auto html = std::make_shared<HTMLHtmlElement>();
//    auto html = HTMLHtmlElement{};
//    html->parent_node = &html;
    document.document_element = html;
    stack_of_open_elements.push_back(html);
    render_root = std::make_shared<RenderObject>(html);
    latest_render_object = render_root;
//    render_root->

    insertion_mode = MD_BEFORE_HEAD;

    token = token->next;

    auto head = parse_at_before_head();
    document.head = &head;

    auto body = parse_at_after_head();
    document.body = body;

    return;
}

HTMLHeadElement Parser::parse_at_before_head() {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-before-head-insertion-mode
    assert(insertion_mode == MD_BEFORE_HEAD);
    if (token->kind == TK_START_TAG && token->start_tag.value().name == "head") {
        auto head_element = HTMLHeadElement{};
        head_element_pointer = std::make_shared<Element>(head_element);
        insert_html_element_for_the_token(head_element_pointer);
        insertion_mode = MD_IN_HEAD;

        token = token->next;
        parse_at_in_head(head_element);
        return head_element;
    }
}

void Parser::parse_at_in_head(HTMLHeadElement &head_element) {
    // https://html.spec.whatwg.org/multipage/parsing.html#parsing-main-inhead
    assert(insertion_mode == MD_IN_HEAD);

    if (token->kind == TK_START_TAG && token->start_tag.value().name == "head") {
        stack_of_open_elements.pop_back();
        insertion_mode = MD_AFTER_HEAD;

        token = token->next;
        return;
    }
}

std::shared_ptr<HTMLBodyElement> Parser::parse_at_after_head() {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-after-head-insertion-mode
    assert(insertion_mode == MD_AFTER_HEAD);

    if (token->kind == TK_START_TAG && token->start_tag.value().name == "body") {
        auto body_element = HTMLBodyElement{};
        auto body_element_pointer = std::make_shared<HTMLBodyElement>(body_element);
        insert_html_element_for_the_token(body_element_pointer);
        insertion_mode = MD_IN_BODY;
        token = token->next;
        parse_at_in_body(body_element_pointer);

        return body_element_pointer;
    }
}

void Parser::parse_at_in_body(std::shared_ptr<HTMLBodyElement> body_element_pointer) {
    // https://html.spec.whatwg.org/multipage/parsing.html#parsing-main-inbody
    assert(insertion_mode == MD_IN_BODY);

    if (token->kind == TK_START_TAG && token->start_tag.value().start_or_end == TAG_START &&
        token->start_tag.value().name == "div") {
//        auto div_element = HtmlDivElement{};
        auto div_element = std::make_shared<HtmlDivElement>();
        auto render_object = std::make_shared<RenderObject>(div_element);
        insert_html_element_for_the_token(div_element);
//        if (latest_render_object->node == div_element->parent) {
//            latest_render_object->children.push_back(render_object);
//        } else {
//            auto parent = latest_render_object->node->parent;
//            auto render_parent = latest_render_object;
//            while(div_element->parent != parent) {
//                parent = parent->parent;
//                render_parent = render_parent->parent;
//            }
//            render_parent->children.push_back(render_object);
//        }
        latest_render_object = render_object;

        token = token->next;
        return parse_at_in_body(body_element_pointer);
    }
    if (token->kind == TK_CHAR) {
        // https://www.w3.org/TR/2011/WD-html5-20110113/tokenization.html#insert-a-character

        auto current = current_node();
        if (current->child_nodes.size() == 0) {
            auto text = Text{};
            text.data = token->c.value();
            current->child_nodes.push_back(std::make_shared<Text>(text));
        } else if (current->child_nodes.size() == 1) {
            auto child = current->child_nodes[0];
            if (child->kind == ND_TEXT) {
                auto text = std::static_pointer_cast<Text>(child);
                text->data = text->data + token->c.value();
            } else {
                throw std::runtime_error("chilid node must be ND_TEXT to process char token");
            }
        } else {
            throw std::runtime_error("child node size must be under 1 when insert char");
        }
        token = token->next;
        return parse_at_in_body(body_element_pointer);
    }
    if (token->kind == TK_START_TAG && token->start_tag.value().start_or_end == TAG_END &&
        token->start_tag.value().name == "div") {
        stack_of_open_elements.pop_back();

        token = token->next;
        return parse_at_in_body(body_element_pointer);
    }
    if (token->kind == TK_START_TAG && token->start_tag.value().start_or_end == TAG_END &&
        token->start_tag.value().name == "body") {
        insertion_mode = MD_AFTER_BODY;
        token = token->next;
        return parse_at_after_body();
    }
}

void Parser::parse_at_after_body() {
    // https://html.spec.whatwg.org/multipage/parsing.html#parsing-main-afterbody
    assert(insertion_mode == MD_AFTER_BODY);

    if (token->kind == TK_START_TAG && token->start_tag.value().start_or_end == TAG_END &&
        token->start_tag.value().name == "html") {
        insertion_mode = MD_AFTER_AFTER_BODY;
        token = token->next;
        return parse_at_after_after_body();
    }
}

void Parser::parse_at_after_after_body() {
    // https://html.spec.whatwg.org/multipage/parsing.html#the-after-after-body-insertion-mode
    assert(insertion_mode == MD_AFTER_AFTER_BODY);

    if (token->kind == TK_EOF) {}
}

void Parser::insert_html_element_for_the_token(std::shared_ptr<Element> element) {
    // https://www.w3.org/TR/2011/WD-html5-20110113/tokenization.html#insert-an-html-element
    element->parent = current_node();
    current_node()->child_nodes.push_back(element);
    stack_of_open_elements.push_back(element);
}

std::shared_ptr<Node> Parser::current_node() {
    return stack_of_open_elements[stack_of_open_elements.size() - 1];
}

