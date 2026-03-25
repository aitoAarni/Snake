#include <ncurses.h>
#include "screen.hpp"
#include "block.hpp"

int main() {
    Screen screen;
    Block b1(10, 10, '-');
    Block b2(10, 11, '|');
    Block b3(10, 12, '-');
    Block b4(10, 10, 'A');
    screen.draw_block(b1);
    screen.draw_block(b2);
    // screen.update();
    auto ch = getch();
    screen.draw_block(b3);
    auto ch2 = getch();
    screen.draw_block(b4);
    auto ch3 = getch();
    screen.close();
    return 0;
}