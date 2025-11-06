cmake_minimum_required(VERSION 3.31)
project(Dungeon_Crawler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dungeon_Crawler main.cpp
        Tile.cpp
        Tile.h
        Floor.cpp
        Floor.h
        Wall.cpp
        Wall.h
        Portal.cpp
        Portal.h
        Character.cpp
        Character.h
        Level.cpp
        Level.h
        DungeonCrawler.cpp
        DungeonCrawler.h
        AbstractUI.cpp
        AbstractUI.h
        TerminalUI.cpp
        TerminalUI.h)
