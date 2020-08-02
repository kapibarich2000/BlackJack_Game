cmake_minimum_required(VERSION 3.16)
project(BlackJack)

add_subdirectory(Game)

add_executable(BlackJack main.cpp)

set_target_properties(
        BlackJack PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(BlackJack Game)