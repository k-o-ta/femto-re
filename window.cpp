//
// Created by koji on 3/3/22.
//

#include "window.h"
#include <iostream>

void Client::on_server_something(std::string text, int x, int y, int width, int height) {
    std::cout << "client handler" << text << std::endl;
}

Window::Window(int width, int height) {
    set_title("femto-re");
    set_default_size(width, height);

//    m_area.m_client = client;
    m_area.show();
    add(m_area);

    show_all_children();
}

MyArea::MyArea() {}

MyArea::~MyArea() {}

void MyArea::on_server_something(std::string text, int x, int y, int width, int height) {
    // windowが表示される前に実行すると落ちるので調査
    auto cairo_context = get_window()->create_cairo_context();
//    m_context = get_window()->create_cairo_context();
    std::cout << "myarea handler" << text << std::endl;
    if (cairo_context) {
        draw_text2(cairo_context, text, width, height);
    }
//    Cairo::RefPtr<Cairo::Context> my_context = get_window()->create_cairo_context();
//    draw_text2(my_context, text, width, height);
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    std::cout << "on_draw" << std::endl;
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    const int rectangle_width = width;
    const int rectangle_height = height / 2;

    // Draw a black rectangle
    cr->set_source_rgb(1.0, 0.0, 0.0);
//    draw_rectangle(cr, rectangle_width, rectangle_height);
//    cr->rectangle(0, 0, rectangle_width, rectangle_height);
//    cr->fill();

    // and some white text
    cr->set_source_rgb(0.0, 0.0, 0.0);
    draw_text(cr, rectangle_width, rectangle_height, "Hi there!");
//    draw_text(cr, rectangle_width, rectangle_height, "Hello World");

    // flip the image vertically
    // see http://www.cairographics.org/documentation/cairomm/reference/classCairo_1_1Matrix.html
    // the -1 corresponds to the yy part (the flipping part)
    // the height part is a translation (we could have just called cr->translate(0, height) instead)
    // it's height and not height / 2, since we want this to be on the second part of our drawing
    // (otherwise, it would draw over the previous part)
    Cairo::Matrix matrix(1.0, 0.0, 0.0, -1.0, 0.0, height);

    // apply the matrix
    cr->transform(matrix);

    // white rectangle
    cr->set_source_rgb(1.0, 1.0, 1.0);
//    draw_rectangle(cr, rectangle_width, rectangle_height);

    // black text
    cr->set_source_rgb(0.0, 0.0, 0.0);
    draw_text(cr, rectangle_width, rectangle_height, "Hi there!");

    return true;
}

void MyArea::draw_text2(const Cairo::RefPtr<Cairo::Context> &cr, std::string text,
                       int rectangle_width, int rectangle_height) {

    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    const int _rectangle_width = width;
    const int _rectangle_height = height / 2;

    cr->move_to(0, 0);
    cr->set_source_rgb(0.0, 0.0, 0.0);
//    draw_rectangle(cr, rectangle_width, rectangle_height);
//    cr->rectangle(0, 0, 100, 100);
    cr->rectangle(0, 0, _rectangle_width, _rectangle_height);
    cr->fill();

    cr->set_source_rgb(1.0, 1.0, 1.0);

    std::cout << "draw_text2"  << std::endl;
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);

    auto layout = create_pango_layout(text);

    layout->set_font_description(font);

    int text_width;
    int text_height;

    //get the text dimensions (it updates the variables -- by reference)
    layout->get_pixel_size(text_width, text_height);

    // Position the text in the middle
    cr->move_to((_rectangle_width - text_width) / 2, (_rectangle_height - text_height) / 2);

    layout->show_in_cairo_context(cr);

}
void MyArea::draw_text(const Cairo::RefPtr<Cairo::Context> &cr,
                       int rectangle_width, int rectangle_height, std::string text) {
    std::cout << "draw text" << std::endl;
    // http://developer.gnome.org/pangomm/unstable/classPango_1_1FontDescription.html
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);

    // http://developer.gnome.org/pangomm/unstable/classPango_1_1Layout.html
    auto layout = create_pango_layout(text);

    layout->set_font_description(font);

    int text_width;
    int text_height;

    //get the text dimensions (it updates the variables -- by reference)
    layout->get_pixel_size(text_width, text_height);

    // Position the text in the middle
    cr->move_to((rectangle_width - text_width) / 2, (rectangle_height - text_height) / 2);

    layout->show_in_cairo_context(cr);
}
