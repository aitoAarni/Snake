# 1. Define the minimum CMake version required. 
# Ubuntu 22.04+ usually has 3.22 or higher.
cmake_minimum_required(VERSION 3.20)

# 2. Name your project and specify the language (CXX means C++)
project(ConsoleSnake CXX)

# 3. Force the compiler to use modern C++23. 
# This replaces the need to manually pass "-std=c++23" to g++.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disables compiler-specific extensions to keep code portable

# 4. Tell CMake to create an executable named 'snake' 
# using the source code found in 'src/main.cpp'
add_executable(snake src/main.cpp)

# 5. Link the ncurses library
target_link_libraries(snake ncurses)

# 6. (Optional but recommended) Turn on strict compiler warnings.
# This is the CMake equivalent of "-Wall -Wextra -Wpedantic"
target_compile_options(snake PRIVATE -Wall -Wextra -Wpedantic)