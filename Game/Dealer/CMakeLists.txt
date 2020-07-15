cmake_minimum_required(VERSION 3.16)
project(Dealer)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Dealer Dealer.cpp Dealer.h) # Создали статическую библиотеку
#add_subdirectory(../Player)

target_include_directories(Dealer PUBLIC .) #Добавления путей поиска заголовков
target_link_libraries(Dealer Player)
target_link_libraries(Dealer iCardGame)