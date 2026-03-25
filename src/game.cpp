#include "game.hpp"

Game::Game(
    Screen sc,
    Snake snk,
    std::atomic<bool>& ir,
    std::atomic<Direction>& dir
    ) : screen(sc), snake(snk), is_running(ir), direction(dir) {}

void Game::loop() {

    while (is_running.load()) {
        snake.print_body([this](const Block& b) {
            screen.draw_block(b);
        });
        screen.update();
    }
    screen.close();
    return;
}