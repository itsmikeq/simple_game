cmake_minimum_required(VERSION 3.17)
project(simple_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(simple_game main.cpp Player.cpp Player.h Weapon.cpp Weapon.h Defense.cpp Defense.h Game.cpp Game.h utils.hpp Scene.cpp Scene.h AirplaneHanger.cpp AirplaneHanger.h AirplaneCabin.cpp AirplaneCabin.h utils.cpp)