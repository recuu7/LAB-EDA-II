#include "estructuras_y_funciones.h"
Cola_usuarios* createQueue() {
    Cola_usuarios* queue = (Cola_usuarios*)malloc(sizeof(Cola_usuarios));
    queue->primero = NULL;
    queue->ultimo = NULL;
    return queue;
}

void enqueue(Cola_usuarios* queue, User* usuario) {
    Node_cola* newNode = (Node_cola*)malloc(sizeof(Node_cola));
    newNode->usuario = usuario;
    newNode->siguiente = NULL;

    if (queue->ultimo == NULL) {
        queue->primero = newNode;
        queue->ultimo = newNode;
    } else {
        queue->ultimo->siguiente = newNode;
        queue->ultimo = newNode;
    }
}

void enviarSolicitudAmistad(User* sender, User* receiver) {
    if (sender == NULL || receiver == NULL) {
        printf("El usuario o el destinatario no existen.\n");
        return;
    }

    // Crear una solicitud de amistad
    FriendRequest* solicitud = malloc(sizeof(FriendRequest));
    solicitud->sender = sender;
    solicitud->receiver = receiver;
    solicitud->accepted = false;

    // Agregar la solicitud a la cola de solicitudes del receptor
    enqueue(receiver->solicitudes, sender);

    printf("Solicitud de amistad enviada de %s a %s.\n", sender->nombre, receiver->nombre);
}


