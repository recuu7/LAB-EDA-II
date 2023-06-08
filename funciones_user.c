#include <string.h>
#include "estructuras_y_funciones.h"

User* elegir_usuario(Lista_usuarios* lista) { // funcion para elegir un usuario de la lista
    char nombre[100]; // declaramos la variable nombre
    printf("Que usuario quiere seleccionar?\n");
    scanf("%s", nombre); // pedimos por pantalla el nombre a buscar

    User* usuario = buscar_usuario(nombre, lista); // buscamos si el usuario esta en la lista de usuarios registrados
    if (usuario == NULL) { // si no esta registrado returnea null
        printf("Usuario no encontrado.\n\n");
        return NULL;
    }
    else { // si esta registrado:
        return usuario; // devuelve el usuario
    }
}

User* buscar_usuario(char* nombre_a_buscar, Lista_usuarios* lista) { // funcion para buscar un usuario en la lista de usuario registrados
    Node_lista* nodeLista = lista->primero; // empezamos con el primer usuario de la lista
    while (nodeLista != NULL){ // mientras que no sea nulo:
        int a = strcmp(nodeLista->usuario->nombre, nombre_a_buscar); // comparamos el nombre a buscar con el usuario en la posicion actual de la lista
        if (a == 0) { // si es el mismo nombre:
            return nodeLista->usuario; // devolvemos el usuario
        }
        nodeLista = nodeLista->siguiente; // sino lo encontramos, pasamos al siguiente usuario en la lista
    }
    return NULL; // sino lo encontramos, returneamos null
}

int login(User* usuario) { // funcion para iniciar sesion en un usuario
    char password[100]; // declaramos la variable password
    printf("Introduzca el password de @%s:\n", usuario->nombre);
    scanf("%s",password); // pedimos el password por pantalla

    if (strcmp(password, usuario->password) == 0) // si el password por pantalla es el mismo que el password del usuario
        return 1; // devolvemos un 1
    else
        return -1; // sino devolvemos un -1
}

void edad_promedio() { // funcion para imprimir la edad promedio de los usuarios registrados
    int edad = 0, total_usuarios = 0; // declaramos las variables locales que usaremos en la funcion
    int mediana;
    FILE* f = fopen("users.txt","r"); // abrimos el fichero en modo lectura
    if (f == NULL) { // si el fichero es null no returneamos nada pero salimos de la funcion
        printf("No se ha encontrado el archivo.\n");
        return;
    }

    while (!feof(f)) { // mientras que el fichero no se acabe:
        User* temporal = leer_usuarios(f); // leemos el usuario y lo guardamos en un temporal con estructura User*
        edad += temporal->edad; // vamos guardando la suma de las edades en la variable edad
        total_usuarios++;  // la variable total usuarios augmenta 1
    }

    mediana = (edad/total_usuarios); // calculamos la edad mediana
    printf("La edad mediana de los usuarios registrados es %d a%cos.\n\n",mediana,164); // la printeamos
}