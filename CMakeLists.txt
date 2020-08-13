cmake_minimum_required(VERSION 3.16)
project(BlackJack)

add_subdirectory(Game)
add_subdirectory(contrib/googletest)

add_executable(BlackJack main.cpp)

add_executable(Cards_tests Game/Tests/Cards_tests.cpp Game/Cards.cpp Game/Cards.h)
target_include_directories(Cards_tests PRIVATE Game)
target_link_libraries(Cards_tests PRIVATE gtest gtest_main)

add_executable(Hand_tests Game/Tests/Hand_tests.cpp Game/Cards.cpp Game/Hand.cpp Game/Hand.h)
target_include_directories(Hand_tests PRIVATE Game)
target_link_libraries(Hand_tests PRIVATE gtest gtest_main)

set_target_properties(
        BlackJack PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(BlackJack Game)