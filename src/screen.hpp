#pragma once
#include "block.hpp"

class Screen {
    public:
    Screen();
    void update();
    void draw_block(const Block&);
    void close();
};