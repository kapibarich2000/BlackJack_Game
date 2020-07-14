cmake_minimum_required(VERSION 3.16)
project(Game)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Game Game.cpp Game.h) # Создали статическую библиотеку

target_include_directories(Game PUBLIC .) #Добавления путей поиска заголовков

add_subdirectory(Cards)
add_subdirectory(Dealer)
add_subdirectory(Hand)
add_subdirectory(Player)

target_link_libraries(Game Cards) #Линкуемся
target_link_libraries(Game Dealer)
target_link_libraries(Game Hand)
target_link_libraries(Game Player)