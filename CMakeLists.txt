cmake_minimum_required(VERSION 3.10)

project(ConsoleSnake)

# Force the compiler to use modern C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Put the final executable in a 'bin' folder inside the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Tell CMake to build an executable named 'snake' from 'main.cpp'
add_executable(snake main.cpp)

# Link the ncurses library
target_link_libraries(snake ncurses)