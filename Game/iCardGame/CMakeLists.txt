cmake_minimum_required(VERSION 3.16)
project(iCardGame)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(iCardGame iCardGame.cpp iCardGame.h) # Создали статическую библиотеку

target_include_directories(iCardGame PUBLIC .) #Добавления путей поиска заголовков