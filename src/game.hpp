#pragma once
#include "screen.hpp"
#include "snake.hpp"

class Game {
    Screen screen;
    Snake snake;
    public:
    Game(Screen, Snake);
    void loop();
};