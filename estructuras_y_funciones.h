#ifndef LAB_EDA_II_ESTRUCTURAS_Y_FUNCIONES_H
#define LAB_EDA_II_ESTRUCTURAS_Y_FUNCIONES_H
#include "stdlib.h"
#include "stdio.h"

typedef struct {
    char nombre[100];
    int edad;
    char email[100];
    char ubicacion[100];
    char gustos[5][100];
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

void iniciar_lista(Lista_usuarios* lista);
void iniciar_usuario(User* usuario);
void pedir_datos(User* usuario);
void nuevo_usuario(Lista_usuarios* lista);
void poner_lista(Lista_usuarios* lista, User* usuario);
void lista_todos_usuarios(Lista_usuarios* lista);
User* buscar_usuario(char* nombre_a_buscar, Lista_usuarios* lista);
User* seleccion_usuario(Lista_usuarios* lista);
User* usuario_definitivo(Lista_usuarios* lista);
void lista_usuarios_file(char* fichero);
void leer_nombres_fichero(FILE* f);
void escribir_file_usuario(char* fichero, User* usuario);
char* nombre_usuario_a_buscar(User* usuario);
User* elegir_usuario(Lista_usuarios* lista);

#endif //LAB_EDA_II_ESTRUCTURAS_Y_FUNCIONES_H
