cmake_minimum_required(VERSION 3.16)
project(Dealer)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_library(Dealer Dealer.cpp Dealer.h) # Создали статическую библиотеку

target_include_directories(Dealer PUBLIC .) #Добавления путей поиска заголовков