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
    usuario->gustos1[0] = '0';
    usuario->gustos2[0] = '0';
    usuario->gustos3[0] = '0';
    usuario->gustos4[0] = '0';
    usuario->gustos5[0] = '0';
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
    printf("Gusto 1:\n");
    scanf("%s", usuario->gustos1);
    printf("Gusto 2:\n");
    scanf("%s", usuario->gustos2);
    printf("Gusto 3:\n");
    scanf("%s", usuario->gustos3);
    printf("Gusto 4:\n");
    scanf("%s", usuario->gustos4);
    printf("Gusto 5:\n");
    scanf("%s", usuario->gustos5);
    printf("Introduzca su password:\n");
    scanf("%s",usuario->password);
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

void nuevo_usuario(Lista_usuarios* lista){
    User* usuario = (User*) malloc(sizeof(User));
    iniciar_usuario(usuario);
    pedir_datos(usuario);
    poner_lista(lista, usuario);
    agregar_usuario_lista(usuario);
    iniciar_solicitudes(usuario);
    iniciar_amistades(usuario);
    printf("\nBienvenido por primera vez @%s!\n", usuario->nombre);
}

void lista_todos_usuarios(Lista_usuarios* lista){
    Node_lista* nodeLista = lista->primero;
    if (nodeLista == NULL)
        printf("No hay ningun usuario registrado.\n\n");
    else {
        printf("\nTodos los usuarios registrados son:\n");
        int i = 1;
        while (nodeLista != NULL) {
            printf("%d. %s\n", i, nodeLista->usuario->nombre);
            i++;
            nodeLista = nodeLista->siguiente;
        }
        printf("\n\n");
    }
}