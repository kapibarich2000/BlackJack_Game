cmake_minimum_required(VERSION 3.16)
project(Cards)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Cards Cards.cpp Cards.h) # Создали статическую библиотеку

target_include_directories(Cards PUBLIC .) #Добавления путей поиска заголовков