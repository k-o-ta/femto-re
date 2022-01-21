//
// Created by koji on 1/8/22.
//

#ifndef FEMTO_RE_TOKEN_H
#define FEMTO_RE_TOKEN_H

#include <optional>
#include <memory>

enum TokenKind {
    // TK_TAGにrename
    TK_START_TAG,
    TK_CHAR
};

enum StartOrEnd {
    TAG_START,
    TAG_END
};

class StartOrEndTag {
public:
    StartOrEnd start_or_end;
    std::string name;
};

class Token {
public:
    TokenKind kind;
    // TODO: start_or_end_tagにrenameする
    std::optional<StartOrEndTag> start_tag;
    std::optional<char> c;
    std::shared_ptr<Token> next;

    explicit Token(StartOrEndTag start_tag): kind(TK_START_TAG), start_tag(start_tag) {}
    explicit Token(char c): kind(TK_CHAR), c(c) {}
//    std::optional<Token*> next;
};


enum TokenizationState {
    ST_DATA,
    ST_TAG_OPEN,
    ST_TAG_NAME,
    ST_END_TAG_OPEN,
};

class Tokenizer {
public:
    std::shared_ptr<Token> tokenize(std::istream& istream);
private:
    Token reconsume_tag_name_state(std::istream &istream, StartOrEndTag start_tag, char current_char);
    bool can_tokenize(std::string str);
    char re_consume(std::istream& istream, unsigned int size = 1);
    Token generate_tag_token(std::istream& istream);
    TokenizationState state {ST_DATA};
    char consume(std::istream& istream);
};

class TokenFactory {
public:
    static Token createStartTagToken();
};

#endif //FEMTO_RE_TOKEN_H
