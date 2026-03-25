#include <ncurses.h>
#include <chrono>

int main() {
    initscr();
    keypad(stdscr, true);
    raw();
    noecho();
    char ch {0} ;
    while (ch != 'q') {
        ch = getch();
        addch(ch);
    }
    endwin();

    return 0;
}