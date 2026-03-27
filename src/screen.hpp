#pragma once
#include "block.hpp"
#include "game_level.hpp"

struct ScreenSize {
    int width;
    int height;
};

class Screen {
    public:
    Screen();
    void update();
    void draw_block(const Block&);
    void draw_border(const GameArea&);
    ScreenSize get_size() const;
    void close();
};