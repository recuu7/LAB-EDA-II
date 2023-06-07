#include "estructuras_y_funciones.h"

void iniciar_cola_amistades(Cola_usuarios* amigos) {
    amigos->primero = NULL;
    amigos->ultimo = NULL;
}

void agregar_amigo_amistades(Cola_usuarios* amigos, User* usuario) {
    Node_cola* nodeCola = (Node_cola*) malloc(sizeof(Node_cola));
    nodeCola->usuario = usuario;
    nodeCola->siguiente = NULL;

    if (amigos->ultimo == NULL) {
        amigos->primero = nodeCola;
        amigos->ultimo = nodeCola;
    }
    else {
        amigos->ultimo->siguiente = nodeCola;
        amigos->ultimo = nodeCola;
    }
}

User* buscar_usuario_amistades(Cola_usuarios* cola, const char* nombre) {
    Node_cola* nodeCola = cola->primero;
    while (nodeCola != NULL) {
        if (nombre == nodeCola->usuario->nombre) {
            return nodeCola->usuario;
        }
        nodeCola = nodeCola->siguiente;
    }
    return NULL;
}

void cola_amistades(Cola_usuarios* cola) {
    Node_cola* nodeCola = cola->primero;
    if (nodeCola == NULL)
        printf("No tienes ninguna amistad.\n\n");
    else {
        printf("Todas tus amistades son:\n");
        while (nodeCola != NULL) {
            printf("- %s.\n",nodeCola->usuario->nombre);
            nodeCola = nodeCola->siguiente;
        }
        printf("\n");
    }

}