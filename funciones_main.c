#include <string.h>
#include <stdio.h>
#include "estructuras_y_funciones.h"

void iniciar_lista(Lista_usuarios* lista){ // funcion para iniciar la lista de usuarios
    lista->size = 0;
    lista->ultimo = NULL;
    lista->primero = NULL; // le damos 0 a los numeros y null a los usuarios
}

void iniciar_usuario(User* usuario) { // funcion para iniciar un usuario
    usuario->nombre[0] = '0';
    usuario->edad = 0;
    usuario->email[0] = '0';
    usuario->ubicacion[0] = '0';
    usuario->gustos1[0] = '0';
    usuario->gustos2[0] = '0';
    usuario->gustos3[0] = '0';
    usuario->gustos4[0] = '0';
    usuario->gustos5[0] = '0';
    iniciar_pila(&usuario->solicitudes);
    iniciar_cola_amistades(&usuario->amistades);
    // le damos 0 a los numeros, '0' a las strings i iniciamos la pila de solicitudes y la cola de amistades del usuario en concreto
}

void pedir_datos(User* usuario){ // funcion para pedir los datos de un usuario en concreto
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
    // pedimos todos los valores mediante scanf y los guardamos directamente en el usuario
}

void poner_lista(Lista_usuarios* lista, User* usuario){ // funcion para poner en la lista de usuarios un usuario en concreto
    Node_lista* nodeLista = (Node_lista*) malloc(sizeof(Node_lista)); // creamos espacio dinamicamente para poner el usuario en la lista
    nodeLista->usuario = usuario; // igualamos el usuario de la lista al usuario dado por la funcion
    nodeLista->siguiente = NULL; // el siguiente usuario es nulo, porque no existe

    if(lista->primero == NULL){ // miramos si hay algun usuario en la lista, si no solo tendremos este usuario en la lista
        lista->primero = nodeLista; // tanto el ultimo como el primer usuario es el mismo
        lista->ultimo = nodeLista;
        nodeLista->previo = NULL; // el usuario previo es nulo
    }
    else{ // si ya hay algun usuario en la lista entonces no es el primero.
        lista->ultimo->siguiente = nodeLista; // el siguiente usuario en la lista es el usuario dado por la funcion
        nodeLista->previo = lista->ultimo; // el usuario previo es el ultimo en la lista
        lista->ultimo = nodeLista; // el ultimo usuario es el usuario dado por la funcion
    }
    lista->size++; // aumentamos el tamaño de la lista de usuarios
}

void nuevo_usuario(Lista_usuarios* lista){ // funcion para crear un nuevo usuario
    User* usuario = (User*) malloc(sizeof(User)); // creamos espacio para el usuario
    iniciar_usuario(usuario); // iniciamos el usuario
    pedir_datos(usuario); // pedimos los datos
    poner_lista(lista, usuario); // lo ponemos en la lista
    agregar_usuario_lista(usuario); // lo ponemos en el fichero users.txt
    printf("\nBienvenido por primera vez @%s!\n", usuario->nombre);
}

void lista_todos_usuarios(Lista_usuarios* lista){ // funcion para listar todos los usuarios
    Node_lista* nodeLista = lista->primero; // empezamos por el primer usuario de la lista
    if (nodeLista == NULL) // si es nulo: no hay ningun usuario
        printf("No hay ningun usuario registrado.\n\n");
    else { // sino es nulo
        printf("\nTodos los usuarios registrados (ordenados por fecha de registro) son:\n");
        int i = 1;
        while (nodeLista != NULL) { // mientras que el usuario de la lista no sea nulo:
            printf("%d. %s\n", i, nodeLista->usuario->nombre); // imprimos el usuario
            i++;
            nodeLista = nodeLista->siguiente; // pasamos al siguiente usuario
        }
        printf("\n");
    }
}