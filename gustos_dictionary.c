#include "estructuras_y_funciones.h"
#include "string.h"

Diccionario* crear_diccionario(Diccionario diccionario[]) {
    diccionario->elemento = NULL;
    diccionario->size = 0;
    return diccionario;
}

void actualizar_fichero(Diccionario diccionario[]) {
    FILE* f = fopen("dictionary.txt", "w");
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < diccionario->size; i++)
        fprintf(f, "%s %d\n", diccionario[i].elemento->gusto, diccionario[i].elemento->count);
    fclose(f);
}

void actualizar_valor(Diccionario diccionario[], char* key) {
    for (int i = 0; i < diccionario->size; i++) {
        if (strcmp(diccionario[i].elemento->gusto, key) == 0) {
            diccionario[i].elemento->count++;
            return;
        }
    }
    strcpy(diccionario[diccionario->size].elemento->gusto, key);
    diccionario[diccionario->size].elemento->count = 1;
    diccionario->size ++;
    actualizar_fichero(diccionario);
}

void leer_diccionario(Diccionario diccionario[]) {
    FILE* f = fopen("dictionary.txt","r");
    char gusto[100]; int count;
    while (fscanf(f,"%s %d",gusto,&count) != EOF) {
        actualizar_valor(diccionario,gusto);
    }
}

void bubbleSort(Diccionario diccionario[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (diccionario[j].elemento->count < diccionario[j+1].elemento->count) {
                Diccionario temporal = diccionario[j];
                diccionario[j] = diccionario[j+1];
                diccionario[j+1] = temporal;
            }
        }
    }
}

void top3_imprimir(Diccionario diccionario[]) {
    int j = 1;
    bubbleSort(diccionario,diccionario->size);
    printf("Los gustos mas comunes son:\n");
    for(int i = 0; i < 3; i++) {
        printf("%d. %s (%d veces repetido).\n",j,diccionario[i].elemento->gusto,diccionario[i].elemento->count);
    }
}