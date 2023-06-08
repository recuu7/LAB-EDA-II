#include "estructuras_y_funciones.h"
#include "string.h"


void leer_gustos(Diccionario* diccionario) {
    FILE* f = fopen("dictionary.txt", "r");
    if (f == NULL) {
        printf("No se pudo abrir el fichero.\n");
        return;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        char gusto[100];
        int count;
        if (sscanf(buffer, "%99s %d", gusto, &count) == 2) {
            Elementos elemento;
            elemento.count = count;
            strncpy(elemento.gusto, gusto, sizeof(elemento.gusto) - 1);
            elemento.gusto[sizeof(elemento.gusto) - 1] = '\0';

            if (diccionario->size == diccionario->capacity) {
                diccionario->capacity *= 2;
                diccionario->elemento = realloc(diccionario->elemento, diccionario->capacity * sizeof(Elementos));
            }

            diccionario->elemento[diccionario->size] = elemento;
            diccionario->size++;
        }
    }

    fclose(f);
}
void actualizar_gusto(Diccionario* diccionario, char* nuevoGusto) {
    FILE *f = fopen("dictionary.txt", "a");
    if (f == NULL) {
        printf("No se pudo abrir el fichero.\n");
        return;
    }

    for (int i = 0; i < diccionario->size; i++) {
        if (strcmp(diccionario->elemento[i].gusto, nuevoGusto) == 0) {
            diccionario->elemento[i].count++;
            fprintf(f, "%s %d\n", diccionario->elemento[i].gusto, diccionario->elemento[i].count);
            fclose(f);
            return;
        }
    }

    Elementos nuevoElemento;
    nuevoElemento.count = 1;
    strncpy(nuevoElemento.gusto, nuevoGusto, sizeof(nuevoElemento.gusto));

    diccionario->elemento[diccionario->size] = nuevoElemento;
    diccionario->size++;

    fprintf(f, "%s %d\n", nuevoElemento.gusto, nuevoElemento.count);
    fclose(f);
}

void bubbleSort(Diccionario* diccionario) {
    for (int i = 0; i < diccionario->size - 1; i++) {
        for (int j = 0; j < diccionario->size - i - 1; j++) {
            if (diccionario->elemento[j].count < diccionario->elemento[j + 1].count) {
                Elementos temporal = diccionario->elemento[j];
                diccionario->elemento[j] = diccionario->elemento[j + 1];
                diccionario->elemento[j + 1] = temporal;
            }
        }
    }
}

void print_gustos(Diccionario* diccionario) {
    printf("Top 3 gustos mas repetidos:\n");
    for (int i = 0; i < 3 && i < diccionario->size; i++) {
        printf("%d. %s - %d veces\n", i + 1, diccionario->elemento[i].gusto, diccionario->elemento[i].count);
    }
}

void print_top3(){
    Diccionario diccionario;
    diccionario.size = 0;
    diccionario.capacity = 10;
    diccionario.elemento = malloc(diccionario.capacity * sizeof(Elementos));

    leer_gustos(&diccionario);
    bubbleSort(&diccionario);
    print_gustos(&diccionario);

    free(diccionario.elemento);


}