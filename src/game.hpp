#pragma once
#include "screen.hpp"
#include "snake.hpp"
#include "controls.hpp"
#include "game_level.hpp"
#include <atomic>
#include "food.hpp"

class Game {
    Screen& screen;
    Snake& snake;
    std::atomic<bool>& is_running;
    std::atomic<Direction>& direction;
    GameArea game_area;  
    Food food;
    void handle_snake_food_collision();


    public:
    Game(Screen&, Snake&, std::atomic<bool>&, std::atomic<Direction>&);
    void loop();
};