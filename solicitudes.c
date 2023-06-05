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