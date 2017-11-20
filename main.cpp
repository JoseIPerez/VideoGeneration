#include <iostream>
#include <stdio.h>
#include <cstring>
#include "global.h"
#include "Frame.h"
#include "Rectangle.h"
#include <vector>

using namespace std;

Frame frame;
int main(int argc, char * argv[]) {
    const char * cmd =
    "ffmpeg              "
    "-y                  "
    "-hide_banner        "
    "-f rawvideo         " // input to be raw video data
    "-pixel_format rgb24 "
    "-video_size 720x480 "
    "-r 60               " // frames per second
    "-i -                " // read data from the standard input stream
    "-pix_fmt yuv420p    " // to render with Quicktime
    "-vcodec mpeg4       "
    "-an                 " // no audio
    "-q:v 5              " // quality level; 1 <= q <= 32
    "output.mp4          ";
    
#ifdef _WIN32
    FILE * pipe = _popen(cmd, "wb");
#else
    FILE * pipe = popen(cmd, "w");
#endif
    if (pipe == 0) {
        cout << "error: " << strerror(errno) << std::endl;
        return 1;
    }
    
    vector<Rectangle>rect;
    
    Rectangle r1 (30, 55, 0, 0, 255, 0, 0);
    r1.setVelocity(5, 3);
    
    Rectangle r2 (30, 55, 150, 150, 0, 255, 0);
    r2.setVelocity(5, 5);
    
    Rectangle r3(30, 55, 200, 200, 255, 255, 255);
    r3.setVelocity(5, 4);
    
    rect.push_back(r1);
    rect.push_back(r2);
    rect.push_back(r3);
    
    int num_frames = duration_in_seconds * frames_per_second;
    for (int i = 0; i < num_frames; ++i) {
        double dt = i / frames_per_second;
        frame.clear();
        for (int j = 0; j < rect.size(); ++j) {
            rect[j].draw_rect(frame);
            rect[j].update(dt);
        }
        frame.write(pipe);
    }
    
    fflush(pipe);
#ifdef _WIN32
    _pclose(pipe);
#else
    pclose(pipe);
#endif
    std::cout << "num_frames: " << num_frames << std::endl;
    std::cout << "Done." << std::endl;
    return 0;
}
