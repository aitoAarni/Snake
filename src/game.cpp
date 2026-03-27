#include "game.hpp"
#include <chrono>
#include <thread>
#include "config.hpp"

Game::Game(
    Screen sc,
    Snake snk,
    std::atomic<bool>& ir,
    std::atomic<Direction>& dir
    ) : screen(sc), snake(snk), is_running(ir), direction(dir) {
        auto screen_size {screen.get_size()};
        int middle_x = screen_size.width / 2;
        int middle_y = screen_size.height / 2;

        game_area.right = middle_x + GAME_ARE_WIDTH / 2;
        game_area.left = middle_x - GAME_ARE_WIDTH / 2;
        game_area.top = middle_y - GAME_ARE_HEIGHT / 2;
        game_area.bottom = middle_y + GAME_ARE_HEIGHT / 2;

    }



void Game::loop() {

    while (is_running.load()) {
        auto next_frame_time {std::chrono::steady_clock::now() +
            std::chrono::milliseconds(500)};

        
        snake.move_snake(direction.load());
        snake.print_body([this](const Block& b) {
            screen.draw_block(b);
        });
        screen.update();
        std::this_thread::sleep_until(next_frame_time);
    }
    screen.close();
    return;
}