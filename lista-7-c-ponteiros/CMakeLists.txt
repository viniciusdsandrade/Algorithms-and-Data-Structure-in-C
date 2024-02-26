cmake_minimum_required(VERSION 3.27)
project(lista_7_c_ponteiros C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lista_7_c_ponteiros
        exe07.c
        global.c
        global.h)
