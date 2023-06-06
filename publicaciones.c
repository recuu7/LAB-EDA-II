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
    printf("Timeline for @%s:\n", user->nombre);
    while (currentPublicacion != NULL) {
        printf("- %s\n", currentPublicacion->content);
        currentPublicacion = currentPublicacion->next;
    }
}

void escribir_publication(User* user) {
    char content[MAX_PUBLICATION_LENGTH + 1];
    printf("Escribe la publicacion (hasta %d caracteres):\n", MAX_PUBLICATION_LENGTH);
    fgets(content, sizeof(content), stdin);

    size_t len = strlen(content);
    if (len > 0 && content[len - 1] == '\n') {
        content[len - 1] = '\0';
    }

    publicar_post_perfil(user, content);

    printf("Publicacion enviada correctamente!\n");
}
