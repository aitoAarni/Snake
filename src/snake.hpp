#pragma once
#include "block.hpp"
#include <vector>

class Snake {
    std::vector<SnakeBlock> body; 
    public:
    Snake();
    template <typename Callable>
    void print_body(const Callable& print_block) {
        for (const auto& block : body) {
            print_block(block);
        }
    }
    void add_block();
    void move_snake(const Direction direction);
};

bool legal_direction(const Direction d1, const Direction d2);