cmake_minimum_required(VERSION 3.27)
project(BugsLife_CA2_Mariela_Machuca_Palmeros)

set(CMAKE_CXX_STANDARD 17)

add_executable(BugsLife_CA2_Mariela_Machuca_Palmeros main.cpp
        Bug.h
        Bug.cpp
        Hopper.h
        Crawler.h
        Crawler.cpp
        Hopper.cpp
        Board.h
        Board.cpp)

set(SFML_DIR /opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML)


find_package(SFML COMPONENTS system graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(BugsLife_CA2_Mariela_Machuca_Palmeros sfml-system sfml-window sfml-graphics sfml-audio)