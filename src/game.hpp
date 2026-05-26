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
    std::atomic<int>& game_state;
    std::atomic<Direction>& direction;
    GameArea game_area;  
    Food food;
    Position middle;
    
    void handle_snake_food_collision();
    void game_over();
    void initialize_new_game();

    public:
    Game(Screen&, Snake&, std::atomic<int>&, std::atomic<Direction>&);
    void loop();
};