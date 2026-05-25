#pragma once
#include "block.hpp"
#include <vector>
#include "game_level.hpp"

class Snake {
    std::vector<SnakeBlock> body; 
    Block cleanup_symbol {-1, -1, ' '};
    public:
    Snake() = default;
    template <typename Callable>
    void print_body(const Callable& print_block) {
        auto& head {body.front()};
        print_block(head);
        print_block(cleanup_symbol);

    }
    void add_block();
    void move_snake(const Direction direction, const GameArea& game_area);
    void spawn(int start_x, int start_y);
    void grow();
    Position get_head_pos();
};

bool legal_direction(const Direction d1, const Direction d2);