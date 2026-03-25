#pragma once

class Block {
    int x_pos;
    int y_pos;
    char symbol;
    public:
    Block(int, int, char);
    int get_x() const;
    int get_y() const;
    char get_symbol() const;
};