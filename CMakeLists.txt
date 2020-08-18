cmake_minimum_required(VERSION 3.16)
project(BlackJack)

add_subdirectory(Game)
add_subdirectory(contrib/googletest)

add_executable(BlackJack main.cpp)

set_target_properties(
        BlackJack PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(BlackJack Game)

# GTests

SET(GTest_Startup
        Game/Tests/GTests_start.cpp
        )
SET(GTest_Tests
        Game/Tests/Cards_tests.cpp
        Game/Tests/Hand_tests.cpp
        )
SET(GTest_ForTesting
        Game/Cards.cpp
        Game/Hand.cpp
        )

add_executable(Google_Tests_run ${GTest_Startup} ${GTest_Tests} ${GTest_ForTesting})
target_include_directories(Google_Tests_run PRIVATE Game)
target_link_libraries(Google_Tests_run gtest gtest_main)