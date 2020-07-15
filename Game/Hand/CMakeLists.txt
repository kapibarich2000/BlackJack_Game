cmake_minimum_required(VERSION 3.16)
project(Hand)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Hand Hand.cpp Hand.h) # Создали статическую библиотеку

target_include_directories(Hand PUBLIC .) #Добавления путей поиска заголовков
target_link_libraries(Hand iCardGame)