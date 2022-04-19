cmake_minimum_required(VERSION 3.16)
project(Game)

set(SOURCES
        Game.cpp
        Cards.cpp
        Hand.cpp
        RealPlayer.cpp
        AIPlayer.cpp
        iCardGame.cpp
        Dealer.cpp
        UsefulFunctions.cpp)

set(HEADERS
        Game.h
        Cards.h
        Hand.h
        RealPlayer.h
        AIPlayer.h
        iCardGame.h
        Dealer.h
        UsefulFunctions.h)

add_library(Game ${SOURCES}  ${HEADERS})

set_target_properties(
        Game PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(Game PUBLIC .)

