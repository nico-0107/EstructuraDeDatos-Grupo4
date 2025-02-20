cmake_minimum_required(VERSION 3.30)
project(EstructuraDeDatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(EstructuraDeDatos main.cpp
        cmake-build-debug/Listadoblementeenlazada.cpp
        cmake-build-debug/Listadoblementeenlazada.h
        BusquedaBinaria.cpp)
