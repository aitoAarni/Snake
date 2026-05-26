#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include "config.hpp"
#include "block.hpp"
#include "game_level.hpp"

struct ScreenSize {
    int width;
    int height;
};

class Screen {
    private:
    void draw_vertical_border(const GameArea&);
    public:
    Screen();
    void update();
    void draw_block(const Block&);
    void draw_border(const GameArea&);
    void draw_game_over_screen(const GameArea&);
    ScreenSize get_size() const;
    void close();
};