#pragma once
#include <random>
#include "game_level.hpp"
#include "block.hpp"

// TODO: add later so can't land on the snake
class RandomPositions
{
private:
    std::uniform_int_distribution<int> x_axel;
    std::uniform_int_distribution<int> y_axel;
    std::random_device dev;
    std::mt19937 rng;

public:
    RandomPositions(const GameArea &game_area) : rng(dev()),
                                                 x_axel(game_area.left + 1, game_area.right - 1),
                                                 y_axel(game_area.top + 1, game_area.bottom - 1) {}

    Position operator()()
    {
        Position random_pos{x_axel(rand), y_axel(rand)};
        return random_pos;
    }
};
