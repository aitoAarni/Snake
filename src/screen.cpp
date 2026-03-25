#include <ncurses.h>
#include <screen.hpp>

Screen::Screen() {
    initscr();
    clear();
    keypad(stdscr, true);
    raw();
    noecho();

}

// void Screen::draw() {

//     int num {0};
//     char ch {0} ;
//     int x = 0, y = 0;
//     while (ch != 'q') {
//         ch = getch();
//     }

// }

void Screen::update()  {
    refresh();
}

void Screen::draw_block(const Block& block) {
    mvaddch(block.get_y(), block.get_x(), block.get_symbol());
}

void Screen::close() {
    endwin();
}