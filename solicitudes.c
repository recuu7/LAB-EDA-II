#include "estructuras_y_funciones.h"

void iniciar_pila(Pila_usuarios* pila) {
    pila->top = NULL;
}

void siguiente_usuario(Pila_usuarios* pila, User* usuario) {
    Node_pila* nodePila = (Node_pila*) malloc(sizeof(Node_pila));
    nodePila->usuario = usuario;
    nodePila->siguiente = pila->top;
    pila->top = nodePila;
}

void agregar_amigo_solicitud_amistad(User* usuario, User* usuario_solicitud) {

}

void menu_solicitudes(User* usuario, Lista_usuarios* lista) {
    char nombre[100];

    printf("A quien quieres enviarle una solicitud de amistad?\n");
    scanf("%s", nombre);

    User* friend = buscar_usuario(nombre,lista);
    if (friend == NULL) {
        printf("Usuario no encontrado en los usuarios registrados!\n");
        return;
    }

    User* newuser = buscar_usuario_cola(usuario->amistades, nombre);
    if (newuser == NULL) {
        poner_usuario_en_cola(newuser,usuario->amistades);
        printf("Se ha enviado una solicitud de amistad a %s!\n", newuser->nombre);
    }
    else {
        printf("%s ya pertenece a tus amistades.\n", newuser->nombre);
    }
}

void gestionar_solicitudes_pendientes(Cola_usuarios* cola, User* usuario) {
    Node_cola* nodeCola = usuario->amistades;
    if (usuario->solicitudes == NULL) {
        printf("No tienes ninguna solicitud pendiente!\n");
        return;
    }

    Node_pila* nodePila = usuario->solicitudes;

    printf("Solicitudes de amistad recicibidas por:\n");
    while (usuario->solicitudes != NULL) {
        printf("- %s", usuario->solicitudes);
    }
}