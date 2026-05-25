#include "block.hpp"
#include <ncurses.h>
#include <string>

bool operator==(const Position& p1, const Position& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

Block::Block(int x, int y, char sym) : position(x, y), symbol(sym) {}
Block::Block(Position& pos, char sym) : position(pos), symbol(sym) {}

int Block::get_x() const { return position.x; }
int Block::get_y() const { return position.y; }
char Block::get_symbol() const { return symbol; }
void Block::set_x(int new_x) { position.x = new_x; }
void Block::set_y(int new_y) { position.y = new_y; }
const Position& Block::get_position() const {return position;}
void Block::set_symbol(char new_symbol) { symbol = new_symbol; }

SnakeBlock::SnakeBlock(int x, int y, char sym, Direction dir) : Block(x, y, sym), direction(dir) {}
SnakeBlock::SnakeBlock(Position pos, char sym, Direction dir) : Block(pos, sym), direction(dir) {}

bool operator==(const Block &b1, const Block &b2)
{
    return (
        b1.get_x() == b2.get_x() &&
        b1.get_y() == b2.get_y() &&
        b1.get_symbol() == b2.get_symbol());
}

void SnakeBlock::move()
{
    using enum Direction;
    if (direction == UP)
        position.y -= 1;
    else if (direction == RIGHT)
        position.x += 1;
    else if (direction == DOWN)
        position.y += 1;
    else if (direction == LEFT)
        position.x -= 1;
}

void SnakeBlock::set_direction(Direction new_direciton)
{
    direction = new_direciton;
}

void SnakeBlock::keep_inside_game_area(const GameArea& game_area) {

    if (get_x() * 2 <= game_area.left) {
        set_x( (game_area.right / 2) - 1);
    } else if ((get_x()) * 2 + 1 >= game_area.right) {
        set_x((game_area.left / 2) + 1);
    } else if (get_y() <= game_area.top) {
        set_y(game_area.bottom-1);
    } else if (get_y() >= game_area.bottom) {
        set_y(game_area.top+1);
    }
}

const Direction& SnakeBlock::get_direction() {
    return direction;
}



FoodBlock::FoodBlock(Position position) : Block(position.x, position.y, static_cast<char>(254u) ) {};
FoodBlock::FoodBlock() : Block(0, 0, static_cast<char>(254u)) {};