#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include "estructuras_y_funciones.h"

Publicacion* crear_publicacion(const char* content){ // funcion para crear una publicacion
    Publicacion* nuevaPublicacion = (Publicacion*) malloc(sizeof(Publicacion)); // creamos espacio para la publicacion
    strncpy(nuevaPublicacion->content, content, MAX_PUBLICATION_LENGTH); // copiamos el texto creado en las publicaciones del usuario
    nuevaPublicacion->next = NULL; // la siguiente publicacion es nula, porque aun no se ha hecho
    return nuevaPublicacion; // devolvemos la publicacion creada
}

void publicar_post_perfil(User* user, const char* content) { // funcion para publicar el post en el perfil
    Publicacion* nuevaPublicacion = crear_publicacion(content); // creamos el espacio para la publicacion
    if (user->timeline == NULL) // sino hay ninguna publicacion:
        user->timeline = nuevaPublicacion; // es la primera publicacion del timeline del usuario
    else { // sino:
        Publicacion* currentPublicacion = user->timeline; // empezamos desde la primera publicacion
        while (currentPublicacion->next != NULL) { // vamos pasando por todas hasta que la siguiente sea nula
            currentPublicacion = currentPublicacion->next;
        }
        currentPublicacion->next = nuevaPublicacion; // entonces guardamos la siguiente publicacion como la nueva
    }
}

void mirar_publicaciones_usuario(User* user) { // funcion para printear todas los posts de un usuario
    Publicacion* currentPublicacion = user->timeline; // empezamos desde la primera publicacion
    printf("Posts de @%s:\n", user->nombre);
    while (currentPublicacion != NULL) { // mientras que la publicacion no sea nula:
        printf("- %s\n", currentPublicacion->content); // imprimos la publicacion actual
        currentPublicacion = currentPublicacion->next; // pasamos a la siguiente publicacion
    }
}

void escribir_publication(User* user) { // funcion para escribir una publicacion para un usuario en concreto
    char content[MAX_PUBLICATION_LENGTH + 1]; // creamos la variable donde guardaremos el texto
    printf("Escibe el texto (maximo %d caracteres):\n", MAX_PUBLICATION_LENGTH);
    scanf(" %[^\n]s", content); // pedimos el post por pantalla

    publicar_post_perfil(user, content); // publicamos el post en nuestro perfil, guardandolo

    printf("Post publicado correctamente!\n");
}