#include "snake.hpp"

constexpr char symb { static_cast<char>(254u) };

Snake::Snake() {
    body.emplace_back(10, 10, symb, Direction::RIGHT);
}

void Snake::add_block() {
    auto last {body.back()};
    body.emplace_back(last.get_y() ,last.get_x() - 1, symb, last.get_direction());
}

void Snake::move_snake(const Direction direction) {
    auto& head {body.front()};

    cleanup_symbol.set_x(body.back().get_x());
    cleanup_symbol.set_y(body.back().get_y());

    for (auto it {body.rbegin()}; head != *it; it++) {
        it->set_direction((it+1)->get_direction());
        it->move();
    }
    if (legal_direction(head.get_direction(), direction)) {
        head.set_direction(direction);
    }
    head.move();
    return;
}

bool legal_direction(const Direction d1, const Direction d2) {
    using enum Direction;
    if (d1 == UP && d2 == DOWN) return false;
    else if (d1 == RIGHT && d2 == LEFT) return false;
    else if (d1 == DOWN && d2 == UP) return false;
    else if (d1 == LEFT && d2 == RIGHT) return false;
    return true;
}