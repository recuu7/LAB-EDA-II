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
    struct Pila_usuarios* solicitudes;
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
    struct Node_cola* siguiente;
} Node_cola;

typedef struct {
    Node_cola* primero;
    Node_cola* ultimo;
} Cola_usuarios;

typedef struct {
    User* usuario;
    struct Node_pila* siguiente;
} Node_pila ;

typedef struct {
    Node_pila* top;
} Pila_usuarios ;

typedef struct {
    int count;
    char gusto[100];
} Elementos;

typedef struct {
    Elementos* elemento;
    int size;
} Diccionario;

typedef struct Publicacion {
    char content[MAX_PUBLICATION_LENGTH + 1];
    struct Publicacion* next;
} Publicacion;

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
User* buscar_usuario_cola(Cola_usuarios* cola, char* nombre);
void poner_usuario_en_cola(User* usuario, Cola_usuarios* cola);
void menu_solicitudes(User* usuario, Lista_usuarios* lista);
void iniciar_cola(Cola_usuarios* cola);
void iniciar_pila(Pila_usuarios* pila);
void top_3_dictionary();
int size_dictionary(FILE* f);
void escribir_publication(User* user);
void mirar_publicaciones_usuario(User* user);






#endif //LAB_EDA_II_ESTRUCTURAS_Y_FUNCIONES_H