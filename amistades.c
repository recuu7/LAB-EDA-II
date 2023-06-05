#include "estructuras_y_funciones.h"

void iniciar_cola(Cola_usuarios* cola) {
    cola->ultimo = NULL;
    cola->primero = NULL;
}

void poner_usuario_en_cola(User* usuario, Cola_usuarios* cola) {
    Node_cola* nodeCola = (Node_cola*) malloc(sizeof(Node_cola));
    nodeCola->usuario = usuario;
    nodeCola->siguiente = NULL;

    if (cola->ultimo == NULL) {
        cola->primero = nodeCola;
        cola->ultimo = nodeCola;
    }
    else {
        cola->ultimo->siguiente = nodeCola;
        cola->ultimo = nodeCola;
    }
}

int cola_vacia(Cola_usuarios* cola) {
    if (cola->primero == NULL)
        return 1;
    else
        return 2;
}

User* buscar_usuario_cola(Cola_usuarios* cola, char* nombre) {
    Node_cola* nodeCola = cola->primero;
    while (nodeCola != NULL) {
        if (nodeCola->usuario->nombre == nombre)
            return nodeCola->usuario;
        nodeCola = nodeCola->siguiente;
    }
    return NULL;
}

void agregar_usuario_amistades(User* usuario, User* usuario_solicitud) {
    if (buscar_usuario_cola(&usuario->solicitudes, usuario_solicitud->nombre) == NULL) {
        poner_usuario_en_cola(usuario, &usuario->solicitudes);
    }
}