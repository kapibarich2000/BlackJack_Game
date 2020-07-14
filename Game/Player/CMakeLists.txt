cmake_minimum_required(VERSION 3.16)
project(Player)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Player Player.cpp Player.h) # Создали статическую библиотеку

target_include_directories(Player PUBLIC .) #Добавления путей поиска заголовков