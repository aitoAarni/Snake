#pragma once
#include <random>
#include "game_level.hpp"
#include "block.hpp"

// TODO: add later so can't land on the snake
class RandomPositions
{
private:
    std::mt19937 rng;
    std::uniform_int_distribution<int> x_axel;
    std::uniform_int_distribution<int> y_axel;

public:
    RandomPositions() = default;
    RandomPositions(const GameArea &game_area) : rng(std::random_device{}()),
                                                 x_axel(game_area.left + 1, game_area.right - 1),
                                                 y_axel(game_area.top + 1, game_area.bottom - 1) {}

    Position operator()()
    {
        Position random_pos{x_axel(rng)/2, y_axel(rng)};
        return random_pos;
    }
};
