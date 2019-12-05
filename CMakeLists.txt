cmake_minimum_required(VERSION 3.13)
project(House_Gen)

set(CMAKE_CXX_STANDARD 17)
# -Wall -Wextra -Werror -Wpedantic
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(House_Gen main.cpp House/House.cpp)