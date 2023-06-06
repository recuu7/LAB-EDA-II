#include <stdbool.h>
#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include "estructuras_y_funciones.h"

Publicacion* crear_publicacion(const char* content){
    Publicacion* nuevaPublicacion = (Publicacion*) malloc(sizeof(Publicacion));
    strncpy(nuevaPublicacion->content, content, MAX_PUBLICATION_LENGTH);
    nuevaPublicacion->next = NULL;
    return nuevaPublicacion;
}
void publicar_post_perfil(User* user, const char* content) {
    Publicacion* nuevaPublicacion = crear_publicacion(content);
    if (user->timeline == NULL)
        user->timeline = nuevaPublicacion;
    else {
        Publicacion* currentPublicacion = user->timeline;
        while (currentPublicacion->next != NULL) {
            currentPublicacion = currentPublicacion->next;
        }
        currentPublicacion->next = nuevaPublicacion;
    }
}
void mirar_publicaciones_usuario(User* user) {
    Publicacion* currentPublicacion = user->timeline;
    printf("Timeline de @%s:\n", user->nombre);
    while (currentPublicacion != NULL) {
        printf("- %s\n", currentPublicacion->content);
        currentPublicacion = currentPublicacion->next;
    }
}

void escribir_publication(User* user) {
    char content[MAX_PUBLICATION_LENGTH + 1];
    printf("Write your publication (up to %d characters):\n", MAX_PUBLICATION_LENGTH);
    scanf(" %[^\n]s", content);

    publicar_post_perfil(user, content);

    printf("Publication added successfully!\n");
}
