cmake_minimum_required(VERSION 3.1)
project(Projet_C_epidemie C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_C_epidemie
        main.c
        CreerGraph.c CreerGraph.h graphe.c graphe.h pFile.c pFile.h affichage.c affichage.h)
