# 1. Define the minimum CMake version required. 
cmake_minimum_required(VERSION 3.20)

# 2. Name your project and specify the language
project(ConsoleSnake CXX)

# 3. Force the compiler to use modern C++23. 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 4. Tell CMake to create an executable named 'snake' 
add_executable(snake 
    src/main.cpp
    src/block.cpp
    src/screen.cpp
    src/game.cpp
    src/snake.cpp
    src/controls.cpp
)

# 5. Tell the compiler where to look for your header files (.hpp)
# This allows you to write `#include "block.hpp"` anywhere without errors.
target_include_directories(snake PRIVATE src)

# 6. Link the ncurses library
target_link_libraries(snake ncurses)

# 7. Turn on strict compiler warnings.
target_compile_options(snake PRIVATE -Wall -Wextra -Wpedantic)