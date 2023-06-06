#include "estructuras_y_funciones.h"

Stack_usuarios* iniciar_pila(Stack_usuarios* pila) {
    pila->top = NULL;
    return pila;
}

int stack_vacio(Stack_usuarios* pila) {
    if (pila->top == NULL) return 1;
    else return 2;
}

void actualizar_stack(char* usuario_que_envia, char* usuario_que_recibe, Stack_usuarios* pila) {
    Node_stack* solicitud = (Node_stack*) malloc(sizeof(Node_stack));
    solicitud->usuario = usuario_que_envia;
    solicitud->usuario_recividor = usuario_que_recibe;

    solicitud->siguiente = pila->top;
    pila->top = solicitud;
}

void enviar_solicitud(User* usuario_que_envia, User* usuario_que_recibe, Stack_usuarios* pila) {
    Node_stack* solicitud = pila->top;

    while (solicitud != NULL) {
        if ((solicitud->usuario == usuario_que_envia->nombre) && (solicitud->usuario_recividor == usuario_que_recibe->nombre)) {
            printf("Solicitud invalida!\n");
            return;
        }
        solicitud = solicitud->siguiente;
    }
    actualizar_stack(usuario_que_envia->nombre,usuario_que_recibe->nombre,pila);
    printf("Solicitud enviada correctamente a @%s.\n",usuario_que_recibe->nombre);
}

void menu_solicitudes_enviar(User* usuario, Lista_usuarios* lista) {
    char usuario_a_enviar[100];
    printf("A quien quieres enviarle una solicitud de amistad?\n");
    scanf("%s",usuario_a_enviar);

    User* usuario_envia = buscar_usuario(usuario_a_enviar,lista);
    if (usuario_envia == NULL) {
        printf("Usuario no encontrado.\n");
        return;
    }
    else {
        enviar_solicitud(usuario,usuario_envia,&usuario_envia->solicitudes);
    }
}