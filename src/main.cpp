#include <atomic>
#include <ncurses.h>
#include "game.hpp"
#include "controls.hpp"
#include <thread>
#include "screen.hpp"
#include "snake.hpp"
#include <chrono>

int main() {

    std::atomic<Direction> direction;
    std::atomic<bool> is_running {true};
    Snake snake;
    Screen screen;

    Game game(screen, snake, is_running, direction);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::jthread input_t(input_thread, std::ref(direction), std::ref(is_running));
    game.loop();
    input_t.join();
    return 0;
}