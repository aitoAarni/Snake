#include "block.hpp"

Block::Block(int x, int y, char sym) : x_pos(x), y_pos(y), symbol(sym) {}

int Block::get_x() const { return x_pos;}
int Block::get_y() const { return y_pos;}
char Block::get_symbol() const { return symbol;}
