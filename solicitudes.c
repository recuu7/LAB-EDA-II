#include "estructuras_y_funciones.h"

Stack_usuarios* iniciar_pila(Stack_usuarios* pila) {
    pila->top = NULL;
    return pila;
}

int stack_vacio(Stack_usuarios* pila) {
    if (pila->top == NULL) return 1;
    else return 2;
}

User* primer_usuario_stack(Stack_usuarios* pila) {
    if (stack_vacio(pila) == 1) return NULL;
    else return pila->top->usuario;
}

void actualizar_stack(User* usuario_que_envia, User* usuario_que_recibe, Stack_usuarios* pila) {
    Node_stack* solicitud = (Node_stack*) malloc(sizeof(Node_stack));
    solicitud->usuario = usuario_que_envia;
    solicitud->usuario_recividor = usuario_que_recibe;

    solicitud->siguiente = pila->top;
    pila->top = solicitud;
}

void enviar_solicitud(User* usuario_que_envia, User* usuario_que_recibe, Stack_usuarios* pila) {
    Node_stack* solicitud = pila->top;

    while (solicitud != NULL) {
        if ((solicitud->usuario->nombre == usuario_que_envia->nombre) && (solicitud->usuario_recividor->nombre == usuario_que_recibe->nombre)) {
            printf("Solicitud invalida!\n");
            return;
        }
        solicitud = solicitud->siguiente;
    }
    actualizar_stack(usuario_que_envia,usuario_que_recibe,pila);
    printf("Solicitud enviada correctamente a @%s.\n",usuario_que_recibe->nombre);
}

User* eliminar_usuario_stack_solicitudes(Stack_usuarios* pila) {
    if (stack_vacio(pila) != 1) {
        Node_stack* nodeStack = pila->top;
        pila->top = nodeStack->siguiente;
        User* usuario = nodeStack->usuario;
        free(nodeStack);
        return usuario;
    }
    return NULL;
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

    User* temporal = buscar_usuario_amistades(&usuario->amistades, usuario_a_enviar);
    if (temporal != NULL) {
        printf("El usuario ya pertenece a tus amistades.\n");
        return;
    }

    enviar_solicitud(usuario,usuario_envia,&usuario_envia->solicitudes);

}

void aceptar_solicitud_amistad(User* usuario) {
    User* amigo = eliminar_usuario_stack_solicitudes(&usuario->solicitudes);
    if (amigo != NULL) {
        agregar_amigo_amistades(&usuario->amistades,amigo);
        agregar_amigo_amistades(&amigo->amistades,usuario->nombre);
    }
    printf("Solicitud de amistad aceptada a @%s!\n",amigo->nombre);
}

void rechazar_solicitud_amistad(User* usuario) {
    User* amigo = eliminar_usuario_stack_solicitudes(&usuario->solicitudes);
    printf("Solicitud de amistad rechada a @%s\n!",amigo->nombre);
}

User* siguiente_solicitud(User* usuario){
    return (primer_usuario_stack(&usuario->solicitudes));
}


void menu_solicitudes_recibidas(User* usuario) {
    int a = stack_vacio(&usuario->solicitudes);
    if (a != 1) {
        Stack_usuarios* pila = (Stack_usuarios *) &usuario->solicitudes;
        Node_stack* nodeStack = pila->top;
        while (nodeStack != NULL) {
            User* temporal = siguiente_solicitud(usuario);

            int opcion = 0;
            while (opcion == 0) {
                printf("\nSolicitud de amistad de @%s.\n",temporal->nombre);
                printf("\n1) Acepctar solicitud de amistad.\n2) Rechazar solicitud de amistad.\n");
                scanf("%d", &opcion);
                if (opcion == 1) {
                    aceptar_solicitud_amistad(usuario);
                }
                else if (opcion == 2) {
                    rechazar_solicitud_amistad(usuario);
                }
                else { printf("Respuesta invalida.\n"); }
            }
            nodeStack = nodeStack->siguiente;
        }
    }
    else{
        printf("No tienes ninguna solicitud de amistad.\n");
        return;
    }
}