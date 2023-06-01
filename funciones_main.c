#include <string.h>
#include <stdio.h>
#include "estructuras_y_funciones.h"

void iniciar_lista(Lista_usuarios* lista){
    lista->size = 0;
    lista->ultimo = NULL;
    lista->primero = NULL;
}

void iniciar_usuario(User* usuario){
    usuario->nombre[0] = '0';
    usuario->edad = 0;
    usuario->email[0] = '0';
    usuario->ubicacion[0] = '0';
    int i = 0; while (i < 5){
        usuario->gustos[i][0] = '0';
        i++;}
}

void pedir_datos(User* usuario){
    printf("\nEscriba el nombre de usuario:\n");
    scanf("%s", usuario->nombre);
    printf("Edad actual:\n");
    scanf("%d", &usuario->edad);
    printf("Escriba su email:\n");
    scanf("%s", usuario->email);
    printf("Ubicacion en la que reside:\n");
    scanf("%s", usuario->ubicacion);
    int i = 0; while (i < 5){
        printf("Preferencia %d:\n", i+1);
        scanf("%s", usuario->gustos[i]);
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
    printf("Usuario añadido correctamente!\n\n");
}

void nuevo_usuario(Lista_usuarios* lista){
    User* usuario = (User*) malloc(sizeof(User));
    iniciar_usuario(usuario);
    pedir_datos(usuario);
    poner_lista(lista, usuario);
}

void lista_todos_usuarios(Lista_usuarios* lista){
    Node_lista* nodeLista = lista->primero;
    if (nodeLista == NULL)
        printf("No hay ningun usuario registrado.\n\n");
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