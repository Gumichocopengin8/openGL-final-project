cmake_minimum_required(VERSION 3.10)
project(project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")

add_executable(
        project
        main.cpp
        mouse/mouse.cpp
        mouse/mouse.h
        keyboard/keyboard.cpp
        keyboard/keyboard.h
        block/Block.cpp
        block/Block.h
        camera/Camera.cpp
        camera/Camera.h
        main.h
        window/Window.cpp
        window/Window.h
        player/Player.cpp
        player/Player.h
        chunk/Chunk.cpp
        chunk/Chunk.h
        region/Region.cpp
        region/Region.h
        world/World.cpp
        world/World.h
        world/SkyBox.cpp
        world/SkyBox.h
        texture/Texture.h
        texture/Texture.cpp
        light/Light.cpp
        light/Light.h
        block/types_of_block.h
        structures/Tree.cpp
        structures/Tree.h
        chunk/types_of_biome.h)
