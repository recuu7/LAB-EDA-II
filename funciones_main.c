#include <string.h>
#include <stdio.h>
#include "funciones_main.h"

void iniciar_usuario(User* usuario){
    usuario->name[0] = '\0';
    usuario->age = 0;
    usuario->email[0] = '\0';
    usuario->location[0] = '\0';
    int i = 0; while(i < 5){
        usuario->like[i][0] = '\0';
        i++;}
}

void pedir_datos(User* usuario){
    printf("Escriba el nombre de usuario:\n");
    scanf("%s", usuario->name);
    printf("Edad actual:\n");
    scanf("%d", &usuario->age);
    printf("Escriba su email:\n");
    scanf("%s", usuario->email);
    printf("Ubicación en la que reside:\n");
    scanf("%s", usuario->location);
    int i = 0; while(i < 5){
        printf("Preferencia %d:\n", i+1);
        scanf("%s", usuario->like[i]);
        i++;
    }
}

void nuevo_usuario(User* usuario){
    iniciar_usuario(usuario);
    pedir_datos(usuario);
}
