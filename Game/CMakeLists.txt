cmake_minimum_required(VERSION 3.16)
project(Game)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Game Game.cpp Game.h) # Создали статическую библиотеку

target_include_directories(Game PUBLIC .) #Добавления путей поиска заголовков

#add_subdirectory(Cards)
#add_subdirectory(Dealer)
#add_subdirectory(Hand)
#add_subdirectory(Player)
#add_subdirectory(iCardGame)

add_library(Cards Cards.cpp Cards.h) # Создали статическую библиотеку
target_include_directories(Cards PUBLIC .) #Добавления путей поиска заголовков

add_library(Dealer Dealer.cpp Dealer.h) # Создали статическую библиотеку
target_include_directories(Dealer PUBLIC .) #Добавления путей поиска заголовков


add_library(Hand Hand.cpp Hand.h) # Создали статическую библиотеку
target_include_directories(Hand PUBLIC .) #Добавления путей поиска заголовков

add_library(Player Player.cpp Player.h)
target_include_directories(Player PUBLIC .)

add_library(iCardGame iCardGame.cpp iCardGame.h) # Создали статическую библиотеку
target_include_directories(iCardGame PUBLIC .) #Добавления путей поиска заголовков


target_link_libraries(Dealer Cards)
target_link_libraries(Cards iCardGame)
target_link_libraries(Game Cards) #Линкуемся
target_link_libraries(Game Dealer)
target_link_libraries(Game Hand)
target_link_libraries(Game Player)
target_link_libraries(Game iCardGame)