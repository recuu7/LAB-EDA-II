#include <string.h>
#include <stdio.h>
#include "funciones_main.h"

void iniciar_lista(Lista_usuarios* lista){
    lista->size = 0;
    lista->ultimo = NULL;
    lista->primero = NULL;
}

void iniciar_usuario(User* usuario){
    usuario->name[0] = '0';
    usuario->age = 0;
    usuario->email[0] = '0';
    usuario->location[0] = '0';
    int i = 0; while (i < 5){
        usuario->like[i][0] = '0';
        i++;}
}

void pedir_datos(User* usuario){
    printf("\nEscriba el nombre de usuario:\n");
    scanf("%s", usuario->name);
    printf("Edad actual:\n");
    scanf("%d", &usuario->age);
    printf("Escriba su email:\n");
    scanf("%s", usuario->email);
    printf("Ubicacion en la que reside:\n");
    scanf("%s", usuario->location);
    int i = 0; while (i < 5){
        printf("Preferencia %d:\n", i+1);
        scanf("%s", usuario->like[i]);
        i++;
    }
}

void poner_lista(Lista_usuarios* lista, User* usuario){
    Node_lista* nodeLista = (Node_lista*) malloc(sizeof(Node_lista));
    nodeLista->usuario = usuario;
    nodeLista->siguiente = NULL;

    if(lista->primero == NULL){ // miramos si hay algun usuario en la lista, si no solo tendremos este usuario en la lista.
        lista->primero = nodeLista;
        lista->ultimo = nodeLista;
        nodeLista->previo = NULL;
    }
    else{ // si ya hay algun usuario en la lista entonces no es el primero.
        lista->ultimo->siguiente = nodeLista;
        nodeLista->previo = lista->ultimo;
        lista->ultimo = nodeLista;
    }

    lista->size++;
}

void nuevo_usuario(Lista_usuarios* lista){
    User* usuario = (User*) malloc(sizeof(User));
    iniciar_usuario(usuario);
    pedir_datos(usuario);
    poner_lista(lista, usuario);
    printf("\nUsuario anadido correctamente!\n\n");
}

void lista_todos_usuarios(Lista_usuarios* lista){
    printf("\nTodos los usuarios registrados son:\n");
    Node_lista* nodeLista = lista->primero;
    int i = 1;
    while (nodeLista != NULL){
        printf("%d. %s\n", i, nodeLista->usuario->name);
        i++;
        nodeLista = nodeLista->siguiente;
    }
    printf("\n\n");
}

void lista_usuarios_file(FILE* f){

}

