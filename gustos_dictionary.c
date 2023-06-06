#include "estructuras_y_funciones.h"
#include "string.h"

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
    if (f == NULL) {
        printf("No se ha encontrado el fichero!\n");
        return NULL;
    }

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

Diccionario* ordenar_gustos_por_count(Diccionario d[], int num) {
    for (int i = 0; i < num-1; i++) {
        for (int j = 0; j < num-i-1; j++) {
            if (d[j].elemento->count < d[j+1].elemento->count) {
                Diccionario new_dic = d[j];
                d[j] = d[j+1];
                d[j+1] = new_dic;
            }
        }
    }
    return d;
}

void top_3_dictionary() {
    FILE* f = fopen("dictionary.txt","r");
    if (f == NULL) {
        printf("No se ha encontrado el archivo!\n");
        return;
    }

    Diccionario d[25];
    int i = 0;
    char buffer[100];

    while (fgets(buffer,sizeof(buffer),f) != NULL) {
        char gusto[100];
        int num_veces_gusto;
        scanf(buffer,"%s %d",gusto,&num_veces_gusto);
        strcpy(d[i].elemento->gusto,gusto);
        d[i].elemento->count = num_veces_gusto;
        i++;
    }

    fclose(f);

    ordenar_gustos_por_count(d, 25);

    printf("Top 3 trendic topics:\n");
    int a = 1;
    for (int j = 0; j < 3; j++) {
        printf("%d. %s (%d).\n",a,d[j].elemento->gusto,d[j].elemento->count);
    }
}