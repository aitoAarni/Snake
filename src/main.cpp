#include <atomic>
#include <ncurses.h>
#include "game.hpp"
#include "controls.hpp"
#include <thread>
#include "screen.hpp"
#include "snake.hpp"

int main() {

    std::atomic<Direction> direction;
    std::atomic<bool> is_running {true};
    Snake snake;
    Screen screen;

    std::jthread input_t(input_thread, std::ref(direction), std::ref(is_running));
    Game game(screen, snake, is_running, direction);
    game.loop();
    input_t.join();
    return 0;
}