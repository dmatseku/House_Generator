cmake_minimum_required(VERSION 3.13)
project(House_Gen)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Ofast")

add_executable(House_Gen main.cpp House/House.cpp)