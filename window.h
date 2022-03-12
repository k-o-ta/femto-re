//
// Created by koji on 3/3/22.
//

#ifndef FEMTO_RE_WINDOW_H
#define FEMTO_RE_WINDOW_H

#include <gtkmm.h>
#include <sigc++/sigc++.h>
#include "event.h"

class Client {};

class MyArea : public Gtk::DrawingArea
{
public:
    MyArea();
    virtual ~MyArea();
    void on_receive_event(std::shared_ptr<Event> event);

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
    void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height, std::string text);
    std::vector<std::pair<std::shared_ptr<Event>, bool>> m_draw_events;

};

class Window : public Gtk::Window {
public:
    Window(int width, int height);
    virtual ~Window() = default;
//    Gtk::Button m_button;
    MyArea m_area;
//    Client client;
};

class MyWindow {
public:
    MyWindow(int width, int height);
    Gtk::Window& get_window();
private:
    Gtk::Window window;
//    MyArea area;
};

#endif //FEMTO_RE_WINDOW_H
