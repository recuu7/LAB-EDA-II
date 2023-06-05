//
// Created by saulr on 05/06/2023.
//
#define MAX_PUBLICATION_LENGTH 120
#include <stdbool.h>
#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include "estructuras_y_funciones.h"
typedef struct Publicacion {
    char content[MAX_PUBLICATION_LENGTH + 1];
    struct Publicacion* next;
} Publicacion;

Publicacion* crearPublicacion(const char* content){
    Publicacion* nuevaPublicacion = (Publicacion*)malloc(sizeof(Publicacion));
    strncpy(nuevaPublicacion->content, content, MAX_PUBLICATION_LENGTH);
    nuevaPublicacion->next = NULL;
    return nuevaPublicacion;
}
void addPublicationToTimeline(User* user, const char* content) {
    Publicacion* nuevaPublicacion = crearPublicacion(content);

    if (user->timeline == NULL) {
        user->timeline = nuevaPublicacion;
    } else {
        Publicacion* currentPublicacion = user->timeline;
        while (currentPublicacion->next != NULL) {
            currentPublicacion = currentPublicacion->next;
        }
        currentPublicacion->next = nuevaPublicacion;
    }
}
void mirarTimeline(User* user) {
    Publicacion* currentPublicacion = user->timeline;
    printf("Timeline for @%s:\n", user->nombre);
    while (currentPublicacion != NULL) {
        printf("- %s\n", currentPublicacion->content);
        currentPublicacion = currentPublicacion->next;
    }
}
void writePublication(User* user) {
    char content[MAX_PUBLICATION_LENGTH + 1];
    printf("Escribe la publicacion (hasta %d caracteres):\n", MAX_PUBLICATION_LENGTH);
    fgets(content, sizeof(content), stdin);

    size_t len = strlen(content);
    if (len > 0 && content[len - 1] == '\n') {
        content[len - 1] = '\0';
    }

    addPublicationToTimeline(user, content);

    printf("Publicacion enviada correctamente!\n");
}
