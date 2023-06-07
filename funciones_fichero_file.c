#include <string.h>
#include <stdio.h>
#include "estructuras_y_funciones.h"

void usuarios_fichero(Lista_usuarios* lista) { // funcion para poner los usuarios leidos de users.txt
    FILE* f = fopen("users.txt","r"); //

    if (f == NULL)
        printf("No se ha encontrado el fichero!\n");

    while (!feof(f)) {
        User* usuario = leer_usuarios(f);
        if (usuario != NULL)
            poner_lista(lista,usuario);
    }
}

User* leer_usuarios(FILE* f) {
    User* usuario = (User*) malloc(sizeof(User));
    iniciar_usuario(usuario);

    int a = fscanf(f,"%s %d %s %s %s %s %s %s %s %s", usuario->nombre, &usuario->edad, usuario->email, usuario->ubicacion, usuario->gustos1, usuario->gustos2, usuario->gustos3, usuario->gustos4, usuario->gustos5, usuario->password);
    if (a == 0)
        return NULL;
    else
        return usuario;
}

void agregar_usuario_lista(User* usuario) {
    FILE* f = fopen("users.txt","a");

    if (f == NULL)
        printf("No se ha encontrado el fichero!\n");
    else
        fprintf(f,"\n%s %d %s %s %s %s %s %s %s %s", usuario->nombre, usuario->edad, usuario->email, usuario->ubicacion, usuario->gustos1, usuario->gustos2, usuario->gustos3, usuario->gustos4, usuario->gustos5, usuario->password);
}