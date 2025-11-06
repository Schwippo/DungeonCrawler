cmake_minimum_required(VERSION 3.31)
project(Dungeon_Crawler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dungeon_Crawler src/main.cpp
        src/Tile.cpp
        include/Tile.h
        src/Floor.cpp
        Floor.h
        src/Wall.cpp
        include/Wall.h
        src/Portal.cpp
        Portal.h
        src/Character.cpp
        include/Character.h
        src/Level.cpp
        include/Level.h
        src/DungeonCrawler.cpp
        include/DungeonCrawler.h
        src/AbstractUI.cpp
        include/AbstractUI.h
        src/TerminalUI.cpp
        include/TerminalUI.h)
