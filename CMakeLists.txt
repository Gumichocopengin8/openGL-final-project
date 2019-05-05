cmake_minimum_required(VERSION 3.10)
project(project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")

add_executable(
        project
        main.cpp
        main.h
        mouse/mouse.cpp
        mouse/mouse.h
        keyboard/keyboard.cpp
        keyboard/keyboard.h
        block/Block.cpp
        block/Block.h
        block/types_of_block.h
        camera/Camera.cpp
        camera/Camera.h
        window/Window.cpp
        window/Window.h
        player/Player.cpp
        player/Player.h
        chunk/Chunk.cpp
        chunk/Chunk.h
        world/World.cpp
        world/World.h
        texture/Texture.cpp
        texture/Texture.h
        light/Light.cpp
        light/Light.h
        structures/Cloud.cpp
        structures/Cloud.h
        structures/Tree.cpp
        structures/Tree.h
        structures/Cactus.cpp
        structures/Cactus.h
        structures/SnowFlake.cpp
        structures/SnowFlake.h
        biome/BiomeType.h
        biome/Biome.cpp
        biome/Biome.h)
