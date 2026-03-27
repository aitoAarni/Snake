#pragma once

/**
 * @brief Represent the perimeter of the playable are. 
 * The member variables are lines and columns on the cli
 */
struct GameArea {
    int top {0};
    int right {0};
    int bottom {0};
    int left {0};
};
