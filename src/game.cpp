#include "game.hpp"
#include <chrono>
#include <thread>
#include "config.hpp"

Game::Game(
    Screen &sc,
    Snake &snk,
    std::atomic<int> &ir,
    std::atomic<Direction> &dir) : screen(sc), snake(snk), game_state(ir), direction(dir)
{
    auto screen_size{screen.get_size()};
    int middle_x = screen_size.width / 2;
    int middle_y = screen_size.height / 2;
    middle = Position{middle_x, middle_y};

    game_area.right = middle_x + GAME_ARE_WIDTH;
    game_area.left = middle_x - GAME_ARE_WIDTH;
    game_area.top = middle_y - GAME_ARE_HEIGHT / 2;
    game_area.bottom = middle_y + GAME_ARE_HEIGHT / 2;

}

void Game::handle_snake_food_collision()
{
    if (snake.get_head_pos() == food.get_block().get_position())
    {
        snake.grow(game_area);
        food.generate_new_food_block();
    }
}

void Game::game_over()
{
    game_state.store(2);
    screen.draw_game_over_screen(game_area);
    screen.update();
    while (game_state.load() == 2) {

    }

}

void Game::initialize_new_game() {
        clear();
        refresh();

        screen.draw_border(game_area);
        snake.spawn(middle.x / 2, middle.y);
        food.spawn(game_area);
}

void Game::loop()
{
    while (game_state.load())
    {
        initialize_new_game();
        while (game_state.load())
        {
            auto next_frame_time{std::chrono::steady_clock::now() +
                                 std::chrono::milliseconds(300)};
            if (snake.eats_own_tail())
            {
                break;
            }
            handle_snake_food_collision();
            snake.move_snake(direction.load(), game_area);
            snake.print_body([this](const Block &b)
                             { screen.draw_block(b); });

            if (!food.food_drawn)
            {
                screen.draw_block(food.get_block());
                food.set_food_to_drawn();
            }
            screen.update();
            std::this_thread::sleep_until(next_frame_time);
        }
        game_over();
    }

    screen.close();
    return;
}