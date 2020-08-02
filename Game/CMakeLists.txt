cmake_minimum_required(VERSION 3.16)
project(Game)

add_library(Game Game.cpp Game.h)

set_target_properties(
        Game PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(Game PUBLIC .)

#_______________________________________________________________________________________#

add_library(Cards Cards.cpp Cards.h)
target_include_directories(Cards PUBLIC .)

add_library(Dealer Dealer.cpp Dealer.h)
target_include_directories(Dealer PUBLIC .)


add_library(Hand Hand.cpp Hand.h)
target_include_directories(Hand PUBLIC .)

add_library(Player Player.cpp Player.h)
target_include_directories(Player PUBLIC .)

add_library(iCardGame iCardGame.cpp iCardGame.h)
target_include_directories(iCardGame PUBLIC .)

#_______________________________________________________________________________________#

target_link_libraries(Dealer Cards)
target_link_libraries(Cards iCardGame)
target_link_libraries(Dealer iCardGame)
target_link_libraries(Player iCardGame)
target_link_libraries(Game Cards)
target_link_libraries(Game Hand)
target_link_libraries(Game Player)
target_link_libraries(Game iCardGame)

#_______________________________________________________________________________________#
