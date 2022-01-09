//
// Created by koji on 1/8/22.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "token.h"


Token Tokenizer::tokenize(std::istream &istream) {
    char c;
    std::vector<char> acc;
    switch (state) {
        case ST_DATA:
            istream >> c;
            if (c == '<') {
                state = ST_TAG_OPEN;
                return tokenize(istream);
            }
            if (std::isalnum(c) || std::isspace(c)) {
                return Token(c);
            }
            break;
        case ST_TAG_OPEN:
            c = consume(istream);
            if (c == '/') {
                state = ST_END_TAG_OPEN;
                return tokenize(istream);
            }
            if (std::isalnum(c)) {
                StartOrEndTag start_tag{TAG_START};
                state = ST_TAG_NAME;
                return reconsume_tag_name_state(istream, start_tag, c);
            }
        case ST_END_TAG_OPEN:
            c = consume(istream);
            if (std::isalnum(c)) {
                StartOrEndTag end_tag{TAG_END};
                state = ST_TAG_NAME;
                return reconsume_tag_name_state(istream, end_tag, c);
            }
    }
}

char Tokenizer::consume(std::istream &istream) {
    char c;
    while (istream >> c) {
        if (!std::isspace(c))
            return c;
    }
    return 0;
}


char Tokenizer::re_consume(std::istream &istream, unsigned int size) {
    return false;
}

bool Tokenizer::can_tokenize(std::string str) {
    if (str == "<") {
        return true;
    }
    if (str == ">") {
        return true;
    }
    if (str == "/") {
        return true;
    }

    return false;
}

Token Tokenizer::reconsume_tag_name_state(std::istream &istream, StartOrEndTag start_tag, char current_char) {
    assert(state == ST_TAG_NAME);
    char c = current_char;
    std::vector<char> acc;
    acc.push_back(tolower(c));
    while (c) {
        switch (c) {
            case '>':
                state = ST_DATA;
                start_tag.name = std::string (acc.begin(), acc.end());
                return Token(start_tag);
            default:
                acc.push_back(tolower(c));
                break;
        }
        c = consume(istream);
    }


}

Token TokenFactory::createStartTagToken() {
    StartOrEndTag startTag{};
    return Token(startTag);
}