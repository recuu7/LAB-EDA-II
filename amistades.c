#include "estructuras_y_funciones.h"

void iniciar_cola_amistades(Cola_usuarios* amigos) { // funcion para iniciar la cola de amigos
    amigos->primero = NULL; // iniciamos la cola de amigos poniendo null al primero y al ultimo, ya que no hay ningun amigo
    amigos->ultimo = NULL;
}

void agregar_amigo_amistades(Cola_usuarios* amigos, User* usuario) { // funcion para poner un amigo en la cola de amistades de un usuario
    Node_cola* nodeCola = (Node_cola*) malloc(sizeof(Node_cola)); // creamos espacio para el nodecola que tiene la estructura Node_cola*
    nodeCola->usuario = usuario; // igualamos el usuario del node      // y nos permite ir al siguente usuario de la cola
    nodeCola->siguiente = NULL; // el siguiente usuario no existe

    if (amigos->ultimo == NULL) { // si el ultimo amigo es nulo, es decir que no existe ningun amigo:
        amigos->primero = nodeCola; // el amigo es el primero y el ultimo
        amigos->ultimo = nodeCola;
    }
    else { // si ya existe un amigo:
        amigos->ultimo->siguiente = nodeCola; // el siguiente amigo es el usuario que entramos mediante User* usuario
        amigos->ultimo = nodeCola; // el ulitmo amigo es el usuario de nodecola
    }
}

User* buscar_usuario_amistades(Cola_usuarios* cola, const char* nombre) { // funcion para buscar si un amigo ya esta en nuestras amistades
    Node_cola* nodeCola = cola->primero; // empezamos con el primer usuario de la cola
    while (nodeCola != NULL) { // mientras que los nodos de la cola no sean nulos:
        if (nombre == nodeCola->usuario->nombre) { // si el nombre que buscamos = al nombre del usuario de un nodo:
            return nodeCola->usuario; // devolvemos el usuario
        }
        nodeCola = nodeCola->siguiente; // sino pasamos al siguiente usuario en la cola
    }
    return NULL; // sino lo encontramos, devolvemos null
}

void cola_amistades(Cola_usuarios* cola) { // funcion para imprimir la cola de amistades de un usuario
    Node_cola* nodeCola = cola->primero; // empezamos con el primer usuario de la cola
    if (nodeCola == NULL) // si el primero es nulo: no hay ninguna amistad
        printf("No tienes ninguna amistad.\n\n");
    else { // si no es nulo:
        printf("Todas tus amistades son:\n");
        while (nodeCola != NULL) { // mientras que no sea nulo la amistad:
            printf("- %s.\n",nodeCola->usuario->nombre); // printea el nombre de la amistad en la que se encuentra nodecola
            nodeCola = nodeCola->siguiente; // pasamos al siguiente usuario de la cola
        }
        printf("\n");
    }
}