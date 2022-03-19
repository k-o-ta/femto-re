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

    m_area.show();
    add(m_area);

    show_all_children();
}

RendererArea::RendererArea() {}

RendererArea::~RendererArea() {}

bool RendererArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    debug("on_draw");
    Gtk::Allocation allocation = get_allocation();
    const int window_width = allocation.get_width();
    const int window_height = allocation.get_height();

    for (auto event: m_draw_events) {

        const int rectangle_width = window_width;
        const int rectangle_height = window_height / 2;

        cr->set_source_rgb(1.0, 1.0, 1.0);
//    cr->rectangle(0, 0, rectangle_width, rectangle_height);
//    cr->fill();

        cr->set_source_rgb(0.0, 0.0, 0.0);
        const std::type_info &event_type = typeid(event.first);
        const std::type_info &other = typeid(ShowTextEvent);
        if (typeid(ShowTextEvent) == other) {
            auto show_txt_event = std::dynamic_pointer_cast<ShowTextEvent>(event.first);
            draw_text(cr, rectangle_width, rectangle_height, show_txt_event);
        }
    }

    return true;
}

void RendererArea::draw_text(const Cairo::RefPtr<Cairo::Context> &cr,
                             int rectangle_width, int rectangle_height, std::shared_ptr<ShowTextEvent> show_text_event) {
    // http://developer.gnome.org/pangomm/unstable/classPango_1_1FontDescription.html
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);

    // http://developer.gnome.org/pangomm/unstable/classPango_1_1Layout.html
    auto layout = create_pango_layout(show_text_event->text);
    layout->set_font_description(font);

    int text_width;
    int text_height;

    //get the text dimensions (it updates the variables -- by reference)
    layout->get_pixel_size(text_width, text_height);

    cr->set_source_rgb(1.0, 1.0, 1.0);
    cr->rectangle(show_text_event->x, show_text_event->y, rectangle_width, text_height);
    cr->fill();

    cr->set_source_rgb(0.0, 0.0, 0.0);
    // Position the text in the middle
//    cr->move_to((rectangle_width - text_width) / 2, (rectangle_height - text_height) / 2);
    cr->move_to(show_text_event->x, show_text_event->y);

    layout->show_in_cairo_context(cr);
}

void RendererArea::on_receive_event(std::shared_ptr<Event> event) {
    const std::type_info &event_type = typeid(*event);
    debug(event_type.name());
    if (event_type == typeid(ShowTextEvent)) {
        auto show_txt_event = std::dynamic_pointer_cast<ShowTextEvent>(event);
        m_draw_events.emplace_back(show_txt_event, false);
        queue_draw();
    }
}
