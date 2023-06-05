#include "estructuras_y_funciones.h"

Diccionario* crear_diccionario(int n) {
    Diccionario* d = (Diccionario*) malloc(sizeof(Diccionario));
    d->size = n;
    d->elemento = NULL;
    return d;
}

int buscar_gusto_diccionario(Diccionario* d, char gusto, FILE* f) {
    while (!feof(f)) {
        fscanf(f,"%s %d", d->elemento->gusto, &d->elemento->count);
        if (d->elemento->gusto == &gusto)
            return 1;
    }
    return 2;
}

Diccionario* agregar_palabra_diccionario(char gusto, Diccionario* d) {
    FILE* f = fopen("dictionary.txt","a");
    int a = buscar_gusto_diccionario(d,gusto,f);

    if (a != 1) {
        d->elemento = (Elementos*) malloc(sizeof(Elementos));
        d->elemento->gusto[0] = gusto;
        d->elemento->count = 1;
        d->size += 1;
        fprintf(f,"\n%s %d", d->elemento->gusto, d->elemento->count);
    }
    else {
        d->elemento->count += 1;
    }

    return d;
}

Diccionario* leer_diccionario(FILE* f) {
    int i = 0;
    while (!feof(f)) { i++; }
    Diccionario* d = crear_diccionario(i);

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