#ifndef LAB_EDA_II_FUNCIONES_MAIN_H
#define LAB_EDA_II_FUNCIONES_MAIN_H

#include <stdlib.h>

typedef struct {
    char name[100];
    int age;
    char email[100];
    char location[100];
    char like[5][100];
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
void nuevo_usuario(User* usuario);
void poner_lista(Lista_usuarios* lista, User* usuario);




#endif //LAB_EDA_II_FUNCIONES_MAIN_H
