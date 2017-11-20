#include <stdio.h>
#include <cstring>
#include "Frame.h"
#include "global.h"

Frame::Frame() {
    pixels = new byte[W * H * 3];
}

Frame::~Frame() {
    delete pixels;
}

void Frame::setPixel(int x, int  y, byte r, byte g, byte b) {
    pixels[y * W * 3 + x * 3 + 0] = r;
    pixels[y * W * 3 + x * 3 + 1] = g;
    pixels[y * W * 3 + x * 3 + 2] = b;
}

void Frame::clear() {
    memset(pixels, 0, H * W * 3);
}

bool Frame::isOutside(double *x, double *y) const {
    return *x < 0 || *x >= W || *y < 0 || *y >= H;
}

void Frame::write(FILE * file) const {
    fwrite(pixels, 3, W * H, file);
}

void Frame::clamp(double *x, double *y) {
    if (*x < 0) *x = 0; else if (*x >= W) *x = W - 1;
    if (*y < 0) *y = 0; else if (*y >= H) *y = H - 1;
}

