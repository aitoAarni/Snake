#pragma once
#include "game_level.hpp"
#include "controls.hpp"

struct Position {
    int x;
    int y;
};

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
    void set_x(int new_x);
    void set_y(int new_x);
    void set_symbol(char new_symbol);
};

bool operator==(const Block& b1, const Block& b2);

class SnakeBlock : public Block {
    Direction direction;
    public:
    SnakeBlock(int, int, char, Direction);
    Direction get_direction() const {
        return direction;
    }
    void set_direction(Direction new_direciton); 
    void move();
    void keep_inside_game_area(const GameArea& game_area);
};

class FoodBlock : public Block {
    public:
    FoodBlock(Position position);
    FoodBlock();
};