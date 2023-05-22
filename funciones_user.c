#include <string.h>
#include <stdio.h>
#include "funciones_user.h"
#include "funciones_main.h"

User* buscar_usuario(char* nombre_a_buscar, Lista_usuarios* lista){
    Node_lista* nodeLista = lista->primero;
    while (nodeLista != NULL){
        if (strcmp(nodeLista->usuario->name, nombre_a_buscar) == 0)
            return nodeLista->usuario;
        nodeLista = nodeLista->siguiente;
    }
    return NULL;
}

User* seleccion_usuario(Lista_usuarios* lista){
    char nombre[100];
    scanf("%s", nombre);

    User* usuario = buscar_usuario(nombre, lista);
    if (usuario->name == nombre)
        return usuario;
    else
        return NULL;
}

User* usuario_definitivo(Lista_usuarios* lista){
    User* usuario = seleccion_usuario(lista);
    if (usuario == NULL)
        return NULL;
    else
        return usuario;
}