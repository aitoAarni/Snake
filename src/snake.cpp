#include "snake.hpp"

constexpr char symb  {254u};

Snake::Snake() {
    body.emplace_back(10, 10, symb);
}

void Snake::add_block() {
    auto last {body.back()};
    body.emplace_back(last.get_y() ,last.get_x() - 1, symb);
}