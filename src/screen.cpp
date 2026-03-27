#include <ncurses.h>
#include <screen.hpp>

Screen::Screen() {
    initscr();
    clear();
    keypad(stdscr, true);
    raw();
    curs_set(0);
    noecho();
}


void Screen::update()  {
    refresh();
}

void Screen::draw_block(const Block& block) {
    mvaddch(block.get_y(), block.get_x()*2, block.get_symbol());
    mvaddch(block.get_y(), block.get_x()*2+1, block.get_symbol());
}

void Screen::close() {
    endwin();
}