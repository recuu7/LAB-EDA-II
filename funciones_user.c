#include <string.h>
#include "estructuras_y_funciones.h"

User* elegir_usuario(Lista_usuarios* lista) {
    char nombre[100];
    printf("Que usuario quiere seleccionar?\n");
    scanf("%s", nombre);

    User *usuario = buscar_usuario(nombre, lista);
    if (usuario == NULL) {
        printf("Usuario no encontrado.\n\n");
        return NULL;
    } else
        return usuario;
}

User* buscar_usuario(char* nombre_a_buscar, Lista_usuarios* lista){
    Node_lista* nodeLista = lista->primero;
    while (nodeLista != NULL){
        if (strcmp(nodeLista->usuario->nombre, nombre_a_buscar) == 0) {
            return nodeLista->usuario;
        }
        nodeLista = nodeLista->siguiente;
    }
    return NULL;
}

char* nombre_usuario_a_buscar(User* usuario){
    return usuario->nombre;
}

