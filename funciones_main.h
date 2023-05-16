#ifndef LAB_EDA_II_FUNCIONES_MAIN_H
#define LAB_EDA_II_FUNCIONES_MAIN_H

#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char email[MAX_LENGTH];
    char location[MAX_LENGTH];
    char like[5][MAX_LENGTH];
} User;

void iniciar_usuario(User* usuario);
void pedir_datos(User* usuario);
void nuevo_usuario(User* usuario);



#endif //LAB_EDA_II_FUNCIONES_MAIN_H
