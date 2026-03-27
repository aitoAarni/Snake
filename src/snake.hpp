#pragma once
#include "block.hpp"
#include <vector>

class Snake {
    std::vector<SnakeBlock> body; 
    Block cleanup_symbol {-1, -1, ' '};
    public:
    Snake();
    template <typename Callable>
    void print_body(const Callable& print_block) {
        auto& head {body.front()};
        print_block(head);
        print_block(cleanup_symbol);

    }
    void add_block();
    void move_snake(const Direction direction);
};

bool legal_direction(const Direction d1, const Direction d2);