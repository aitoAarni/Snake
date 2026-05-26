#pragma once
#include <atomic>
#include <ncurses.h>

enum class Direction {UP, RIGHT, DOWN, LEFT};


void input_thread(std::atomic<Direction>&, std::atomic<int>&);