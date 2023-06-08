#include "estructuras_y_funciones.h"
#include "string.h"


void leer_gustos(Diccionario* diccionario) { // funcion para leer los gusto
    FILE* f = fopen("dictionary.txt", "r"); // abrimos el archivo
    if (f == NULL) {
        printf("No se pudo abrir el fichero.\n");
        return; // si es nulo salimos de la funcion
    }

    char buffer[100]; // declaramos el buffer
    while (fgets(buffer, sizeof(buffer), f) != NULL) { // mientras podamos leer una línea del archivo y asignarlo a buffer:
        char gusto[100]; // variable gusto
        int count; // variable count
        if (sscanf(buffer, "%99s %d", gusto, &count) == 2) { // si leemos los valores correctamente:
            Elementos elemento; // creamos una variable elemento con estructura Elementos
            elemento.count = count; // asignamos el valor de 'count' al campo 'count' de 'elemento'
            strncpy(elemento.gusto, gusto, sizeof(elemento.gusto) - 1); // copiamos los caracteres de 'gusto' al campo 'gusto' de 'elemento'
            elemento.gusto[sizeof(elemento.gusto) - 1] = '\0'; // ponemos un caracter nulo al final

            if (diccionario->size == diccionario->capacity) { // si el tamaño del diccionario es el mismo que el de la capacidad
                diccionario->capacity *= 2; // duplicamos la capacidad del diccionario
                diccionario->elemento = realloc(diccionario->elemento, diccionario->capacity * sizeof(Elementos)); // ponemos nueva memoria dinamica
            }

            diccionario->elemento[diccionario->size] = elemento; // asignamos 'elemento' en la posición 'size' del arreglo de elementos del diccionario
            diccionario->size++; // aumentamos el tamaño del diccionario
        }
    }
    fclose(f); // cerramos el archivo
}

void bubbleSort(Diccionario* diccionario) { // funcion bubblesort para ordenar un array
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

void print_gustos(Diccionario* diccionario) { // funcion para imprimir gustos
    printf("Top 3 gustos mas repetidos:\n");
    for (int i = 0; i < 3 && i < diccionario->size; i++) { // para cada array ya ordenado con bubblesort:
        printf("%d. %s - %d veces\n", i + 1, diccionario->elemento[i].gusto, diccionario->elemento[i].count); // imprimos el top 3 de gustos mas comunes
    }
}

void print_top3(){ // funcion para el top 3 de gustos
    Diccionario diccionario; // creamos una variable diccionario con la estructura Diccionario*
    diccionario.size = 0;
    diccionario.capacity = 10;
    diccionario.elemento = malloc(diccionario.capacity * sizeof(Elementos)); // le damos valores a sus elementos

    leer_gustos(&diccionario); // leemos los gustos del archivo "dictionary.txt"
    bubbleSort(&diccionario); // lo ordenamos por orden decreciente de mas comun a menos comun
    print_gustos(&diccionario); // imprmimos el top 3

    free(diccionario.elemento); // liberamos la memoria
}