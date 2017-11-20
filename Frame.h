#pragma once
#include "global.h"
#include <stdio.h>
#include <cstring>
class Frame {
public:
    Frame();
    ~Frame();
    void setPixel(int x, int y, byte r, byte g, byte blue);
    void clear();
    bool isOutside(double * x, double * y) const;
    void write(FILE * file) const;
    void clamp(double *x, double *y);
private:
    unsigned char *pixels;
};
