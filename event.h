//
// Created by koji on 3/3/22.
//

#ifndef FEMTO_RE_EVENT_H
#define FEMTO_RE_EVENT_H


#include <string>
#include <utility>

class Event {
public:
    virtual ~Event() {}
};

class ShowTextEvent: public Event {
public:
    ShowTextEvent(std::string text, int x, int y): text{std::move(text)}, x{x}, y{y} {};
//    ShowTextEvent(std::string text, int x, int y, int width, int height): text{std::move(text)} {};
    std::string text;
    int x;
    int y;
};


#endif //FEMTO_RE_EVENT_H
