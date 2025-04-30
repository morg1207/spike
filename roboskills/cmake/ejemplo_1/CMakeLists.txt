# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MiProyectoCpp)

# Estándar de C++ a usar
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# Crear el ejecutable
add_executable(programa_cpp main.cpp utils.cpp utils.h)