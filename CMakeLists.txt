cmake_minimum_required(VERSION 3.27)
project(c_algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(challanges-c/2_challange6_C)

add_executable(c_algorithms
        challanges-c/2_challange6_C/global.c
        challanges-c/2_challange6_C/global.h
        challanges-c/2_challange6_C/register-challange.c
        challanges-c/2_challange6_C/enunciado/registro-aluno-c.jpg)
