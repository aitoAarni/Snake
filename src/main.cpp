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
    // 0 = quit, 1 = game_on, 2 = game_over 
    std::atomic<int> game_state {1};
    Snake snake;
    Screen screen;

    Game game(screen, snake, game_state, direction);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::jthread input_t(input_thread, std::ref(direction), std::ref(game_state));
    game.loop();
    input_t.join();
    return 0;
}