#pragma once
#include "random.hpp"
#include "block.hpp"
#include "game_level.hpp"

struct Food {
    RandomPositions random_pos;
    FoodBlock food_block;
    public:
    Food() = default;
    Food(const GameArea& game_area) : random_pos(game_area) {}
    
    void spawn(const GameArea& game_area) {
        random_pos = RandomPositions(game_area);
        food_block = FoodBlock(random_pos());
    }
    
    void generate_new_food_block() {
        auto position = random_pos();
        food_block = FoodBlock(position);
    }

    FoodBlock& get_block() {
        return food_block;
    }
};