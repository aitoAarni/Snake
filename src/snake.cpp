#include "snake.hpp"

constexpr char symb { static_cast<char>(254u) };

void Snake::move_snake(const Direction direction, const GameArea& game_area) {
    auto& head {body.front()};
    cleanup_symbol.set_x(body.back().get_x());
    cleanup_symbol.set_y(body.back().get_y());

    for (auto it {body.rbegin()}; head != *it; it++) {
        it->set_direction((it+1)->get_direction());
        it->move();
        it->keep_inside_game_area(game_area);
    }
    if (legal_direction(head.get_direction(), direction)) {
        head.set_direction(direction);
    }
    head.move();
    head.keep_inside_game_area(game_area);
    return;
}


void Snake::spawn(int start_x, int start_y) {
    body.clear();
    body.emplace_back(start_x, start_y, symb, Direction::RIGHT);
}

void Snake::grow(const GameArea& game_area) {
    auto& tail = body.back();
    Position new_tail_pos = tail.get_position();

    switch (tail.get_direction()) {
        case Direction::UP : 
            new_tail_pos.y++;
            break;
        case Direction::RIGHT :
            new_tail_pos.x--;
            break;
        case Direction::DOWN : 
            new_tail_pos.y--;
            break;
        case Direction::LEFT :
            new_tail_pos.x++;
            break;
    }
    SnakeBlock new_tail(new_tail_pos, symb, tail.get_direction());
    new_tail.keep_inside_game_area(game_area);
    body.push_back(new_tail);
}

Position Snake::get_head_pos() {
    return body.front().get_position();
}

bool Snake::eats_own_tail() {
    auto head_pos = get_head_pos();
    for (int i {1}; i < body.size(); i++) {
        if (head_pos == body[i].get_position()) return true;
    }
    return false;
}

bool legal_direction(const Direction d1, const Direction d2) {
    using enum Direction;
    if (d1 == UP && d2 == DOWN) return false;
    else if (d1 == RIGHT && d2 == LEFT) return false;
    else if (d1 == DOWN && d2 == UP) return false;
    else if (d1 == LEFT && d2 == RIGHT) return false;
    return true;
}
