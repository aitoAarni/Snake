#include "block.hpp"
#include <ncurses.h>
#include <string>

Block::Block(int x, int y, char sym) : x_pos(x), y_pos(y), symbol(sym) {}

int Block::get_x() const { return x_pos; }
int Block::get_y() const { return y_pos; }
char Block::get_symbol() const { return symbol; }
void Block::set_x(int new_x) { x_pos = new_x; }
void Block::set_y(int new_y) { y_pos = new_y; }
void Block::set_symbol(char new_symbol) { symbol = new_symbol; }

SnakeBlock::SnakeBlock(int x, int y, char sym, Direction dir) : Block(x, y, sym), direction(dir) {}

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
        y_pos -= 1;
    else if (direction == RIGHT)
        x_pos += 1;
    else if (direction == DOWN)
        y_pos += 1;
    else if (direction == LEFT)
        x_pos -= 1;
}

void SnakeBlock::set_direction(Direction new_direciton)
{
    direction = new_direciton;
}

void SnakeBlock::keep_inside_game_area(const GameArea& game_area) {

    mvaddstr(1, 1, "    ");
    mvaddstr(1, 1, std::to_string(get_y()).c_str());
    mvaddstr(1, 7, "    ");
    mvaddstr(1, 7, std::to_string(game_area.top).c_str());
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


FoodBlock::FoodBlock(int width, int height) : Block(width, height, ' ') {};
void FoodBlock::get_random_location() {}