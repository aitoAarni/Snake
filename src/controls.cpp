#include <ncurses.h>
#include "controls.hpp"

void input_thread(std::atomic<Direction>& direction, std::atomic<bool>& is_running) {
    char chr {};
    while (is_running.load()) {
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
            is_running.store(false);
            continue;
        }
    }
}