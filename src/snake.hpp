#pragma once
#include "block.hpp"
#include <vector>

class Snake {
    std::vector<Block> body; 
    public:
    Snake();
    template <typename Callable>
    void print_body(const Callable& print_block) {
        for (const auto& block : body) {
            print_block(block);
        }
    }
    // void move();
    void add_block();

};