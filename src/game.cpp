#include "game.hpp"
#include <chrono>
#include <thread>
#include "config.hpp"

Game::Game(
    Screen &sc,
    Snake &snk,
    std::atomic<bool> &ir,
    std::atomic<Direction> &dir) : screen(sc), snake(snk), is_running(ir), direction(dir)
{
    auto screen_size{screen.get_size()};
    int middle_x = screen_size.width / 2;
    int middle_y = screen_size.height / 2;

    game_area.right = middle_x + GAME_ARE_WIDTH;
    game_area.left = middle_x - GAME_ARE_WIDTH;
    game_area.top = middle_y - GAME_ARE_HEIGHT / 2;
    game_area.bottom = middle_y + GAME_ARE_HEIGHT / 2;

    snake.spawn(middle_x / 2, middle_y);
    food.spawn(game_area);
}

void Game::handle_snake_food_collision() {
    if (snake.get_head_pos() == food.get_block().get_position()) {
        snake.grow();
        food.generate_new_food_block();
    }
}

void Game::loop()
{
    screen.draw_border(game_area);
    while (is_running.load())
    {
        auto next_frame_time{std::chrono::steady_clock::now() +
                             std::chrono::milliseconds(500)};

        handle_snake_food_collision();
        snake.move_snake(direction.load(), game_area);
        snake.print_body([this](const Block &b)
                         { screen.draw_block(b); });

        screen.draw_block(food.get_block());
        screen.update();
        std::this_thread::sleep_until(next_frame_time);
    }
    screen.close();
    return;
}