#include <iostream>
#include "Rectangle.h"
#include "global.h"

Rectangle::Rectangle(double h, double w, double x, double y, byte r, byte g, byte b): h(h), w(w), x(x), y(y), r(r), g(g), b(b) {}

void Rectangle::setVelocity(double dx, double dy) {
    this->dx = dx;
    this->dy = dy;
}

void Rectangle::update(double dt) {
    x += dx*dt;
    y += dy*dt;
}
void Rectangle::draw_rect(Frame &frame) {
    if (frame.isOutside(&x, &y)) return;
    double x0 = x;
    double x1 = x + w;
    double y0 = y;
    double y1 = y + h;
    frame.clamp(&x0, &y0);
    frame.clamp(&x1, &y1);
    for (double y = y0; y < y1; ++y) {
        for (double x = x0; x < x1; ++x) {
            frame.setPixel(x, y, r, g, b);
        }
    }
}

