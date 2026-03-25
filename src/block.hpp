#pragma once
#include "controls.hpp"

class Block {
    protected:
    int x_pos;
    int y_pos;
    char symbol;
    public:
    Block(int, int, char);
    int get_x() const;
    int get_y() const;
    char get_symbol() const;
};

class SnakeBlock : public Block {
    Direction direction;
    public:
    SnakeBlock(int, int, char, Direction);
    Direction get_direction() const {
        return direction;
    }
    void set_direction(Direction new_direciton); 
    void move();
};