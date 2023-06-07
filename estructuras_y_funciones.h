#ifndef LAB_EDA_II_ESTRUCTURAS_Y_FUNCIONES_H
#define LAB_EDA_II_ESTRUCTURAS_Y_FUNCIONES_H

#include <stdbool.h>
#include "stdlib.h"
#include "stdio.h"
#define MAX_PUBLICATION_LENGTH 120

typedef struct {
    char nombre[100];
    char password[100];
    int edad;
    char email[100];
    char ubicacion[100];
    char gustos1[100];
    char gustos2[100];
    char gustos3[100];
    char gustos4[100];
    char gustos5[100];
    struct Stack_usuarios* solicitudes;
    struct Cola_usuarios* amistades;
    struct Publicacion* timeline;
} User;

typedef struct {
    User* usuario;
    struct Node_lista* siguiente;
    struct Node_lista* previo;
} Node_lista;

typedef struct {
    int size;
    Node_lista* primero;
    Node_lista* ultimo;
} Lista_usuarios;

typedef struct {
    User* usuario;
    User* usuario_recividor;
    struct Node_stack* siguiente;
} Node_stack ;

typedef struct {
    Node_stack* top;
    int solicitudes;
} Stack_usuarios ;

typedef struct {
    int count;
    char gusto[100];
} Elementos;

typedef struct {
    Elementos* elemento;
    int size;
} Diccionario;

typedef struct {
    char content[MAX_PUBLICATION_LENGTH + 1];
    struct Publicacion* next;
} Publicacion;

typedef struct {
    User* usuario;
    struct Node_cola* siguiente;
} Node_cola ;

typedef struct {
    Node_cola* primero;
    Node_cola* ultimo;
} Cola_usuarios ;

void iniciar_lista(Lista_usuarios* lista);
void iniciar_usuario(User* usuario);
void pedir_datos(User* usuario);
void nuevo_usuario(Lista_usuarios* lista);
void poner_lista(Lista_usuarios* lista, User* usuario);
void lista_todos_usuarios(Lista_usuarios* lista);
User* buscar_usuario(char* nombre_a_buscar, Lista_usuarios* lista);
User* elegir_usuario(Lista_usuarios* lista);
void enviar_solicitud_a_usuario(Lista_usuarios* lista, User* usuario_solicitud);
void iniciar_amistades(User* usuario);
void iniciar_solicitudes(User* usuario);
int login(User* usuario);
User* leer_usuarios(FILE* f);
void usuarios_fichero(Lista_usuarios* lista);
void agregar_usuario_lista(User* usuario);
void top_3_dictionary();
void escribir_publication(User* user);
void mirar_publicaciones_usuario(User* user);
void enviar_solicitud(User* usuario_que_envia, User* usuario_que_recibe, Stack_usuarios* pila);
int stack_vacio(Stack_usuarios* pila);
Stack_usuarios* iniciar_pila(Stack_usuarios* pila);
void menu_solicitudes_enviar(User* usuario, Lista_usuarios* lista);
void edad_promedio();
void agregar_amigo_amistades(Cola_usuarios* amigos, User* usuario);
void menu_solicitudes_recibidas(User* usuario);
void iniciar_cola_amistades(Cola_usuarios* amigos);





#endif //LAB_EDA_II_ESTRUCTURAS_Y_FUNCIONES_H