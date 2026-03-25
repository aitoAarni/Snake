#include "block.hpp"

Block::Block(int x, int y, char sym) : x_pos(x), y_pos(y), symbol(sym) {}

int Block::get_x() const { return x_pos;}
int Block::get_y() const { return y_pos;}
char Block::get_symbol() const { return symbol;}

SnakeBlock::SnakeBlock(int x, int y, char sym, Direction dir) :
    Block(x, y, sym), direction(dir) {}

void SnakeBlock::move_rel(int x, int y) {
    x_pos += x;
    y_pos += y;
}
