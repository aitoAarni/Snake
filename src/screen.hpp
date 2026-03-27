#pragma once
#include "block.hpp"

struct ScreenSize {
    int width;
    int height;
};

class Screen {
    public:
    Screen();
    void update();
    void draw_block(const Block&);
    ScreenSize get_size() const;
    void close();
};