#include <string.h>
#include "estructuras_y_funciones.h"

User* elegir_usuario(Lista_usuarios* lista) {
    char nombre[100];
    printf("Que usuario quiere seleccionar?\n");
    scanf("%s", nombre);

    User* usuario = buscar_usuario(nombre, lista);
    if (usuario == NULL) {
        printf("Usuario no encontrado.\n\n");
        return NULL;
    }
    else {
        printf("\nBienvenido de nuevo @%s!\n", usuario->nombre);
        return usuario;
    }
}

User* buscar_usuario(char* nombre_a_buscar, Lista_usuarios* lista) {
    Node_lista* nodeLista = lista->primero;
    while (nodeLista != NULL){
        int a = strcmp(nodeLista->usuario->nombre, nombre_a_buscar);
        if (a == 0) {
            return nodeLista->usuario;
        }
        nodeLista = nodeLista->siguiente;
    }
    return NULL;
}

int login(User* usuario) {
    char password[100];
    printf("Introduzca el password de @%s:\n", usuario->nombre);
    scanf("%s",password);

    if (strcmp(password, usuario->password) == 0)
        return 1;
    else
        return -1;
}