#include "estructuras_y_funciones.h"

void iniciar_solicitudes (User* usuario) {
    Solicitudes* solicitudes = (Solicitudes*) malloc(sizeof(Solicitudes));
    solicitudes->size = 0;
    solicitudes->usuario_solicitado = usuario;
    solicitudes->primera = 0;
    solicitudes->ultima = 0;
    usuario->solicitudes = solicitudes;
}

void iniciar_amistades (User* usuario) {
    Amistades* amistades = (Amistades*)malloc(sizeof(Amistades));
    amistades->size = 0;
    amistades->primero = NULL;
    usuario->amistades = amistades;
}

void enviar_solicitud_a_usuario(Lista_usuarios* lista, User* usuario_solicitud){
    char nombre[100];
    printf("A que usuario desea enviarle una solicitud de amistad?\n");
    scanf("%s", nombre);

    User* usuario = buscar_usuario(nombre, lista);
    if (usuario_solicitud == NULL) {
        printf("Usuario no encontrado!\n");
        return;
    }
    else {
        agregar_solicitud_a_usuario(usuario_solicitud->solicitudes, usuario);
    }
}

Solicitudes* agregar_solicitud_a_usuario(Solicitudes* cola, User* usuario){
    if (cola->size == 0) {
        printf("No hay ningun usuario en la cola de las solicitudes.\n");
        return NULL;
    }

    cola->usuario_solicitado[cola->ultima] = *usuario;
    cola->ultima += 1;
    cola->size += 1;

    return cola;
}