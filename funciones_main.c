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
    Node_lista* nodeLista = (Node_lista*) malloc(sizeof(Node_lista)); // creamos espacio dinamicamente para poner el usuario en la lista
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

void leer_nombres_fichero(FILE* f){
    char nombre[100];
    int i = 1;
    int a = fscanf(f,"%s", nombre);
    while (a == 1){
        printf("%d. %s\n", i, nombre);
        i++;
        a = fscanf(f,"%s", nombre);
    }
}

void lista_usuarios_file(char* fichero, Lista_usuarios* lista){
    FILE* f = fopen(fichero,"w");
    if (f == NULL)
        printf("Fichero no encontrado\n");

    Node_lista* nodeLista = lista->primero;

    if (lista->primero == NULL){

    }

    else {

    }

    while (nodeLista != NULL){
        fprintf(f, "%s\n", nodeLista->usuario->name);
        nodeLista = nodeLista->siguiente;
    }

    fclose(f);
}

void nuevo_usuario(Lista_usuarios* lista){
    User* usuario = (User*) malloc(sizeof(User));
    iniciar_usuario(usuario);
    pedir_datos(usuario);
    poner_lista(lista, usuario);
    lista_usuarios_file("usuarios.txt", lista);
    printf("\nUsuario anadido correctamente!\n");
}

void lista_todos_usuarios(Lista_usuarios* lista){
    Node_lista* nodeLista = lista->primero;

    if (nodeLista == NULL)
        printf("No hay ningun usuario registrado.\n");
    else {
        printf("\nTodos los usuarios registrados son:\n");
        int i = 1;
        while (nodeLista != NULL) {
            printf("%d. %s\n", i, nodeLista->usuario->name);
            i++;
            nodeLista = nodeLista->siguiente;
        }
        printf("\n\n");
    }
}

