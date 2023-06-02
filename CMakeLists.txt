cmake_minimum_required(VERSION 3.24)
project(LAB_EDA_II)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB_EDA_II
        .idea/.gitignore
        .idea/LAB-EDA-II.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        main_menus.c
        funciones_main.c funciones_user.c "usuarios.txt" funciones_fichero_file.c estructuras_y_funciones.h solicitudes.c)
