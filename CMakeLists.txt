cmake_minimum_required(VERSION 3.13)
project(Projet_C_epidemie C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_C_epidemie
        main.c
        zombie.c
        zombie.h)
