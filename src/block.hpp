#pragma once
#include "game_level.hpp"
#include "controls.hpp"

struct Position {
    int x;
    int y;
};

bool operator==(const Position& p1, const Position& p2);

class Block {
    protected:
    Position position;
    char symbol;
    public:
    Block(int, int, char);
    Block(Position&, char);
    int get_x() const;
    int get_y() const;
    char get_symbol() const;
    void set_x(int new_x);
    void set_y(int new_x);
    void set_symbol(char new_symbol);
    const Position& get_position() const;
};

bool operator==(const Block& b1, const Block& b2);

class SnakeBlock : public Block {
    Direction direction;
    public:
    SnakeBlock(int, int, char, Direction);
    SnakeBlock( Position, char, Direction);
    Direction get_direction() const {
        return direction;
    }
    void set_direction(Direction new_direciton); 
    void move();
    void keep_inside_game_area(const GameArea& game_area);
    const Direction& get_direction();
};

class FoodBlock : public Block {
    public:
    FoodBlock(Position position);
    FoodBlock();
};