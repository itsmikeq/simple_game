cmake_minimum_required(VERSION 3.17)
project(simple_game)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_TESTING "build tests")

add_executable(simple_game main.cpp Player.cpp Player.h Weapon.cpp Weapon.h Defense.cpp Defense.h Game.cpp Game.h utils.hpp Scene.cpp Scene.h utils.cpp Serializer.cpp serializer.h)

if (BUILD_TESTING)
    enable_testing()
    add_executable(serialization_test serialization_test.cpp Serializer.cpp)
    add_test(serialization serialization_test)
endif ()