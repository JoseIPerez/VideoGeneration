#pragma once
#include <vector>
#include "Frame.h"
#include "global.h"

class Rectangle {
public:
    Rectangle(double h, double w, double x, double y, byte r, byte g, byte b);
    void draw_rect(Frame &frame);
    void setVelocity(double dx, double dy);
    void update(double dt);
private:
    byte r, g, b;
    double h, w, x, y, dx, dy;
    
};
