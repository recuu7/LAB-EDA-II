#include "estructuras_y_funciones.h"

Diccionario* crear_diccionario(int n) {
    Diccionario* d = (Diccionario*) malloc(sizeof(Diccionario));
    d->size = n;
    d->elemento = NULL;
    return d;
}

int buscar_gusto_diccionario(Diccionario* d, char gusto, FILE* f){
    fscanf(f,"%s %d", d->elemento->gusto, &d->elemento->count);

    if (d->elemento->gusto == &gusto)
        return 1;
    else
        return 2;
}

Diccionario* agregar_palabra_diccionario(char gusto, Diccionario* d) {
    FILE* f = fopen("dictionary.txt","a");
    int a = buscar_gusto_diccionario(d,gusto,f);

    if (a != 1) {
        d->elemento->gusto[0] = gusto;
    }

}

Diccionario* leer_diccionario(FILE* f){
    Diccionario* d = crear_diccionario(100);

    int a = fscanf(f,"%s %d",d->elemento->gusto,&d->elemento->count);
    if (a == 0)
        return NULL;
    else
        return d;
}

void top_3_dictionary(Diccionario* d) {
    FILE* f = fopen("dictionary.txt","r");

    while (!feof(f)) {
        d = leer_diccionario(f);

    }
}