#include "estructuras_y_funciones.h"

Stack_usuarios* iniciar_pila(Stack_usuarios* pila) { // funcion para iniciar el stack
    pila->top = NULL; // el top del stack es nulo
    return pila; // devolvemos el stack
}

int stack_vacio(Stack_usuarios* pila) { // funcion para mirar si un stack esta vacio
    if (pila->top == NULL) return 1; // si esta vacio returnamos 1
    else return 2; // sino returneamos 2
}

User* primer_usuario_stack(Stack_usuarios* pila) { // funcion para mirar el primer usuario del stack
    if (stack_vacio(pila) == 1) return NULL; // si el stack esta vacio returnamos null
    else return pila->top->usuario; // sino returneamos el usuario
}

void actualizar_stack(User* usuario_que_envia, User* usuario_que_recibe, Stack_usuarios* pila) { // funcion para actualizar el stack de un usuario
    Node_stack* solicitud = (Node_stack*) malloc(sizeof(Node_stack)); // creamos espacio para la solicitud
    solicitud->usuario = usuario_que_envia; // igualamos las variables de la solicitud con las que trae la funcion
    solicitud->usuario_recividor = usuario_que_recibe;

    solicitud->siguiente = pila->top; // el usuario siguiente es el top del stack
    pila->top = solicitud; // el usuario mas arriba es el de la solicitud de amistad
}

void enviar_solicitud(User* usuario_que_envia, User* usuario_que_recibe, Stack_usuarios* pila) { // funcion para enviar una solicitud de amistad
    Node_stack* solicitud = pila->top; // empezamos mirando la primera solicitud de amistad del stack

    while (solicitud != NULL) { // mientras que la solicitud no sea nula:
        if ((solicitud->usuario->nombre == usuario_que_envia->nombre) && (solicitud->usuario_recividor->nombre == usuario_que_recibe->nombre)) {
            // miramos si coinciden los nombres con los de la solicitud:
            printf("Solicitud invalida!\n");
            return; // si coinciden returneamos porque la solicitud es invalida
        }
        solicitud = solicitud->siguiente; // pasamos a la siguiente solicitud
    }
    actualizar_stack(usuario_que_envia,usuario_que_recibe,pila); // actualizamos el stack
    printf("Solicitud enviada correctamente a @%s.\n",usuario_que_recibe->nombre);
}

User* eliminar_usuario_stack_solicitudes(Stack_usuarios* pila) { // funcion para eliminar un usuario del stack de solicitudes
    if (stack_vacio(pila) != 1) { // si el stack no esta vacio:
        Node_stack* nodeStack = pila->top; // el nodo es el top del stack
        pila->top = nodeStack->siguiente; // el top es el siguiente usuario del stack
        User* usuario = nodeStack->usuario;
        free(nodeStack); // liberamos el nodo
        return usuario; // returneamos el usuario liberado
    }
    return NULL; // si esta vacio el stack returnamos null
}

void menu_solicitudes_enviar(User* usuario, Lista_usuarios* lista) { // funcion para el menu de la solitudes a enviar
    char usuario_a_enviar[100]; // declaramos la variable del usuario
    printf("A quien quieres enviarle una solicitud de amistad?\n");
    scanf("%s",usuario_a_enviar); // recogemos por pantalla el usuario a enviar la solicitud

    User* usuario_envia = buscar_usuario(usuario_a_enviar,lista); // encontramos el usuario
    if (usuario_envia == NULL) {
        printf("Usuario no encontrado.\n");
        return; // si no lo encontramos salimos de la funcion
    }

    User* temporal = buscar_usuario_amistades(&usuario->amistades, usuario_a_enviar); // buscamos el usuario a enviar la solicitud por si ya lo tenemos en las amistades
    if (temporal != NULL) {
        printf("El usuario ya pertenece a tus amistades.\n");
        return;
    } // si no es null salimos de la funcion porque ya esta en nuestras amistades

    enviar_solicitud(usuario,usuario_envia,&usuario_envia->solicitudes); // enviamos la solitud al usuario
}

void aceptar_solicitud_amistad(User* usuario) { // funcion para aceptar solicitudes
    User* amigo = eliminar_usuario_stack_solicitudes(&usuario->solicitudes); // eliminamos el usuario del stack de solicitudes del amigo
    if (amigo != NULL) {
        agregar_amigo_amistades(&usuario->amistades,amigo); // agreamos a cada usuario en cada cola de amistades
        agregar_amigo_amistades(&amigo->amistades,usuario->nombre);
    }
    printf("Solicitud de amistad aceptada a @%s!\n",amigo->nombre);
}

void rechazar_solicitud_amistad(User* usuario) { // funcion para rechazar solicitudes
    User* amigo = eliminar_usuario_stack_solicitudes(&usuario->solicitudes); // eliminamos el usuario del stack de solicitudes del amigo
    printf("Solicitud de amistad rechada a @%s\n!",amigo->nombre);
}

User* siguiente_solicitud(User* usuario){ // funcion para ir al siguiente usuario
    return (primer_usuario_stack(&usuario->solicitudes)); // devolvemos el siguiente usuario
}


void menu_solicitudes_recibidas(User* usuario) { // funcion para el menu de gestion de solicitudes
    int a = stack_vacio(&usuario->solicitudes); // miramos si el stack esta vacio
    if (a != 1) { // si no esta vacio:
        Stack_usuarios* pila = (Stack_usuarios *) &usuario->solicitudes; // empezamos en la primera solicitud
        Node_stack* nodeStack = pila->top;
        while (nodeStack != NULL) { // mientras que las solicitudes no sean nulas:
            User* temporal = siguiente_solicitud(usuario); // vamos a la siguiente solicitud

            int opcion = 0;
            while (opcion == 0) {
                printf("\nSolicitud de amistad de @%s.\n",temporal->nombre);
                printf("\n1) Aceptar.\n2) Rechazar.\n");
                scanf("%d", &opcion); // pedimos si aceptamos o rechazamos la solicitud
                if (opcion == 1) {
                    aceptar_solicitud_amistad(usuario); // si opcion = 1 aceptamos
                }
                else if (opcion == 2) {
                    rechazar_solicitud_amistad(usuario); // si opcion = 2 rechazamos
                }
                else { printf("Respuesta invalida.\n"); }
            }
            nodeStack = nodeStack->siguiente; // vamos a la siguiente amistad
        }
    }
    else{ // si esta vacio salimos de la funcion
        printf("No tienes ninguna solicitud de amistad.\n");
        return;
    }
}