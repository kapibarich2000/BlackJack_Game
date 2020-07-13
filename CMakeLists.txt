cmake_minimum_required(VERSION 3.16)
project(BlackJack)

SET(CMAKE_CXX_STANDARD 11) # Установили стандарт языка с++ 11

add_subdirectory(Game)

add_executable(BlackJack main.cpp)

target_link_libraries(BlackJack Game) #Линкуемся