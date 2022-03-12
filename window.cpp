//
// Created by koji on 3/3/22.
//

#include "window.h"
#include "util.h"
#include <iostream>
#include <typeinfo>

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

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    std::cout << "on_draw" << std::endl;

    for(auto event: m_draw_events) {
        if (true) {
            std::cout << "on_draw inner" << std::endl;
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
//            Event& event_first = event.first;
            const std::type_info& event_type = typeid(event.first);
            const std::type_info& other = typeid(ShowTextEvent);
            if (typeid(ShowTextEvent) == other) {
//                auto show_txt_event = static_cast<ShowTextEvent&>(event.first);
                auto show_txt_event = std::dynamic_pointer_cast<ShowTextEvent>(event.first);
//                auto result = draw_text2(show_txt_event);
                draw_text(cr, rectangle_width, rectangle_height, show_txt_event->text);
            }
        }
    }

    return true;
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

void MyArea::on_receive_event(std::shared_ptr<Event> event) {
    const std::type_info& event_type = typeid(*event);
    std::cout << event_type.name() << std::endl;
    if (event_type == typeid(ShowTextEvent)) {
        auto show_txt_event = std::dynamic_pointer_cast<ShowTextEvent>(event);
        m_draw_events.emplace_back(show_txt_event, false);
        queue_draw();
    }
    std::cout << "on receive finish" << std::endl;
}
