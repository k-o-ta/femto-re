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
    ShowTextEvent(std::string text): text{std::move(text)} {};
//    ShowTextEvent(std::string text, int x, int y, int width, int height): text{std::move(text)} {};
    std::string text;
};


#endif //FEMTO_RE_EVENT_H
