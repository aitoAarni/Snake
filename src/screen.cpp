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

void Screen::draw_vertical_border(const GameArea& game_area) {
    for (int i = game_area.top; i <= game_area.bottom; i++) {
        mvaddch(i, game_area.left, '|');
        mvaddch(i, game_area.right, '|');
    }
}

void Screen::draw_border(const GameArea& game_area) {
    std::string horizontal_string(GAME_ARE_WIDTH * 2, '-');
    mvaddstr(game_area.top, game_area.left, horizontal_string.c_str());
    mvaddstr(game_area.bottom, game_area.left, horizontal_string.c_str());
    draw_vertical_border(game_area); 
}

void Screen::draw_block(const Block& block) {
    mvaddch(block.get_y(), block.get_x()*2, block.get_symbol());
    mvaddch(block.get_y(), block.get_x()*2+1, block.get_symbol());
}

ScreenSize Screen::get_size() const {
    return {COLS, LINES};
}
void Screen::draw_game_over_screen(const GameArea& game_area) {
    std::string text {"Game Over... press r for retry and q for quit"};
    int align_text_x = game_area.left + GAME_ARE_WIDTH - text.size() / 2;
    mvaddstr(game_area.top + 1, align_text_x, text.c_str());
    
}

void Screen::close() {
    endwin();
}