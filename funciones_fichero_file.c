#include <string.h>
#include <stdio.h>
#include "estructuras_y_funciones.h"

void leer_nombres_fichero(FILE* f){
    char nombre[100];
    int i = 1, a = fscanf(f,"%s", nombre);
    if (a == 0) printf("\nNo hay ningun usuario registrado.\n");

    printf("\nTodos los usuarios registrados:\n");
    while (a == 1){
        printf("%d. %s\n", i, nombre);
        i++;
        a = fscanf(f,"%s", nombre);
    }
}

void escribir_file_usuario(char* fichero, User* usuario){
    FILE* f = fopen(fichero,"w");
    if (f == NULL)
        printf("Fichero no encontrado.\n");
    leer_nombres_fichero(f);

    fprintf(f,"%s",usuario->name);

    fclose(f);

    printf("\nUsuario anadido correctamente!\n");
}

void lista_usuarios_file(char* fichero){
    FILE* f = fopen(fichero,"r");
    if (f == NULL)
        printf("Fichero no encontrado.\n");

    leer_nombres_fichero(f);
    fclose(f);
}