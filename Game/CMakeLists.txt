cmake_minimum_required(VERSION 3.16)
project(Game)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Game Game.h Game.cpp ) # Создали статическую библиотеку

target_include_directories(Game PUBLIC .) #Добавления путей поиска заголовков