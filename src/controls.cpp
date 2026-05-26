
#include "controls.hpp"

void input_thread(std::atomic<Direction>& direction, std::atomic<int>& game_state) {
    char chr {};
    while (game_state.load()) {
        chr = getch();
        switch (chr) {
            case 'w' : 
            direction.store(Direction::UP);
            continue;

            case 'd' : 
            direction.store(Direction::RIGHT);
            continue;

            case 's' : 
            direction.store(Direction::DOWN);
            continue;

            case 'a' : 
            direction.store(Direction::LEFT);
            continue;

            case 'q' :
            game_state.store(0);
            continue;

            case 'r' :
            game_state.store(1);
        }
    }
}