cmake_minimum_required(VERSION 3.29)
project(Ascii3D)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ascii3D main.cpp
        AsciiCanvas.cpp
        AsciiCanvas.h
        ConsoleUtils.cpp
        ConsoleUtils.h
        Matrix.h
        shape3D.cpp
        shape3D.h
        Matrix.cpp
        MatrixTransformations.h
        Renderer3D.cpp
        Renderer3D.h
)
