//
// Created by koji on 3/3/22.
//

#ifndef FEMTO_RE_WINDOW_H
#define FEMTO_RE_WINDOW_H

#include <gtkmm.h>



class MyArea : public Gtk::DrawingArea
{
public:
    MyArea();
    virtual ~MyArea();

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
    void draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
    void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height);

};

class Window : public Gtk::Window {
public:
    Window(int width, int height);
    virtual ~Window() = default;
//    Gtk::Button m_button;
    MyArea m_area;
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
