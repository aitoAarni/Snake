#include "block.hpp"

Block::Block(int x, int y, char sym) : x_pos(x), y_pos(y), symbol(sym) {}

int Block::get_x() const { return x_pos;}
int Block::get_y() const { return y_pos;}
char Block::get_symbol() const { return symbol;}
void Block::set_x(int new_x) {x_pos = new_x;}
void Block::set_y(int new_y) {y_pos = new_y;}
void Block::set_symbol(char new_symbol) {symbol = new_symbol;}

SnakeBlock::SnakeBlock(int x, int y, char sym, Direction dir) :
    Block(x, y, sym), direction(dir) {}

bool operator==(const Block& b1, const Block& b2) {
    return (
        b1.get_x() == b2.get_x() &&
        b1.get_y() == b2.get_y() &&
        b1.get_symbol() == b2.get_symbol()
        );
}

void SnakeBlock::move() {
    using enum Direction;
    if (direction == UP) y_pos -= 1;
    else if (direction == RIGHT) x_pos += 1;
    else if (direction == DOWN) y_pos += 1;
    else if (direction == LEFT) x_pos -= 1;
}

void SnakeBlock::set_direction(Direction new_direciton) {
    direction = new_direciton;
}