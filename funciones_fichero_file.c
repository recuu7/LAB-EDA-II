#include <string.h>
#include <stdio.h>
#include "estructuras_y_funciones.h"

void usuarios_fichero(Lista_usuarios* lista) { // funcion para poner los usuarios leidos de users.txt
    FILE* f = fopen("users.txt","r"); // abrimos el fichero en modo read

    if (f == NULL)
        printf("No se ha encontrado el fichero!\n"); // si el fichero es nulo, printeamos que no lo encuentra

    while (!feof(f)) { // mientras que el fichero no acabe:
        User* usuario = leer_usuarios(f); // lee el usuario del fichero
        if (usuario != NULL) // si el usuario no es nulo:
            poner_lista(lista,usuario); // lo pone en la lista de usuarios registrados
    }
}

User* leer_usuarios(FILE* f) { // funcion para leer los usuarios de un fichero
    User* usuario = (User*) malloc(sizeof(User)); // hacemos espacio mediante memoria dinamica
    iniciar_usuario(usuario); // iniciamos el usuario

    // escaneamos todos los datos del usuario y los guardamos en usuario, que es una estructura User*
    int a = fscanf(f,"%s %d %s %s %s %s %s %s %s %s", usuario->nombre, &usuario->edad, usuario->email, usuario->ubicacion, usuario->gustos1, usuario->gustos2, usuario->gustos3, usuario->gustos4, usuario->gustos5, usuario->password);
    if (a == 0) // si el scan es nulo:
        return NULL; // devuelve null
    else // si no es nulo:
        return usuario; // devuelve el usuario
}

void agregar_usuario_lista(User* usuario) { // funcion para escribir un usuario a la lista users.txt
    FILE* f = fopen("users.txt","a"); // abrimos el fichero en modo append

    if (f == NULL) // si el fichero es nulo:
        printf("No se ha encontrado el fichero!\n"); // printeamos que no se ha encontrado el fichero
    else // si no es nulo: lo escribe en el documento
        fprintf(f,"\n%s %d %s %s %s %s %s %s %s %s", usuario->nombre, usuario->edad, usuario->email, usuario->ubicacion, usuario->gustos1, usuario->gustos2, usuario->gustos3, usuario->gustos4, usuario->gustos5, usuario->password);
}