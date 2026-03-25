#pragma once
#include <atomic>

enum class Direction {UP, RIGHT, DOWN, LEFT};


void input_thread(std::atomic<Direction>&, std::atomic<bool>&);