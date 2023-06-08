# include "stdio.h"
# include "estructuras_y_funciones.h"

int end_program(){ // funcion usada como creditos al finalizar el programa
    printf("\nGracias por usar nuestra aplicacion!\n");
    printf("Hecha por Sergi Panyos, Sergi Recuero, David Romero y Saul Ruiz.\n");
    return 0;
}

void menu_usuario(Lista_usuarios* lista){ // con la lista de usuarios ya creada en el main pasamos al menu de la opcion 3) Operar con un usuario especifico.
    User* usuario = elegir_usuario(lista); // elegimos el usuario con el que operar
    if (usuario == NULL)
        return; // si no esta en lista devuelve error y volvemos al inicio, sino ya tenemos el usuario con el que operar

    int a = login(usuario); // iniciamos sesion con el password, si la funcion login devuelve 1 es correcto, sino incorrecto
    if (a != 1) {
        printf("Password incorrecto!\n");
        return;
    }
    else
        printf("Password correcto!\n");

    int menu = 0; // iniciamos la opcion menu con 0 para que no se acabe el bucle
    while (menu != 6) { // mientras que menu sea distinto a 6 se realiza el bucle
        printf("\n1) Enviar solicitudes de amistad.\n");
        printf("2) Gestionar las solicitudes pendientes.\n");
        printf("3) Realizar una publicacion.\n");
        printf("4) Listar las publicaciones de @%s.\n", usuario->nombre);
        printf("5) Listar todos los amigos de @%s.\n", usuario->nombre);
        printf("6) Volver al menu principal.\n");
        scanf("%d", &menu); // escanamos la opcion entrada por pantalla

        if (menu == 1) // si menu = 1 realiza:
            menu_solicitudes_enviar(usuario,lista); // abre el menu de envio de solicitudes de amistad
        else if (menu == 2) // si menu = 2 realiza:
            menu_solicitudes_recibidas(usuario); // abre el menu de las solicitudes recibidas
        else if (menu == 3) // si menu = 3 realiza:
            escribir_publication(usuario); // escribe una publicacion para el usuario seleccionado
        else if (menu == 4) // si menu = 4 realiza:
            mirar_publicaciones_usuario(usuario); // imprime por pantalla todas las publicaciones de un usuario en concreto
        else if (menu == 5) // si menu = 5 realiza:
            cola_amistades(&usuario->amistades); // imprime por pantalla todas las amistades de un usuario en concreto
        else if (menu == 6) return; // si menu = 6 vuelve al menu
        else
            printf("Respuesta invalida.\n\n"); // vuelve a escanear la opcion menu
    }
}

void menu_usuarios_existentes(Lista_usuarios* lista) {
    int menu = 0; // iniciamos la opcion menu con 0 para que no se acabe el bucle
    while (menu != 4) { // mientras que menu sea distinto a 4 se realiza el bucle
        printf("\n1) Mostrar todos los usuarios registrados.\n");
        printf("2) Mostrar el ranking de gustos mas comunes.\n");
        printf("3) Mostrar la edad promedio de los usuarios registrados.\n");
        printf("4) Volver al menu principal.\n");
        scanf("%d",&menu); // escanamos la opcion entrada por pantalla

        if (menu == 1) // si menu = 1 realiza:
            lista_todos_usuarios(lista); // imprime por pantalla todos los usuarios registrados
        else if (menu == 2) { // si menu = 2 realiza:
            Diccionario diccionario;
            crear_diccionario(&diccionario);
            top3_imprimir(&diccionario);
            } // imprime por pantalla el top 3 de gustos mas comunes entre los usuarios registrados
        else if (menu == 3) // si menu = 3 realiza:
            edad_promedio(); // imprime por pantalla la edad promedio de todos los usuarios registrados
        else if (menu == 4) return; // si menu = 4 vuelve al menu principal
        else
            printf("Respuesta invalida.\n\n"); // vuelve a escanear la opcion menu
    }
}

void mostrar_menu(Lista_usuarios* lista){
    printf("BIENVENIDO!\n\n");
    int menu = 0; // iniciamos la opcion menu con 0 para que no se acabe el bucle
    while (menu != 4) { // mientras que menu sea distinto a 4 se realiza el bucle
        printf("Que desea hacer?\n");
        printf("1) Insertar un nuevo usuario.\n");
        printf("2) Interactuar con usuarios existentes.\n");
        printf("3) Operar con un usuario especifico.\n");
        printf("4) Salir.\n");
        scanf("%d", &menu); // escanamos la opcion entrada por pantalla

        if (menu == 1) // si menu = 1 realiza:
            nuevo_usuario(lista); // insertar un nuevo usuario y lo guarda en users.txt
        else if (menu == 2) // si menu = 2 realiza:
            menu_usuarios_existentes(lista); // abre el menu de usuarios existentes
        else if (menu == 3) // si menu = 3 realiza:
            menu_usuario(lista); // abre el menu de un usuario especifico
        else if (menu == 4) { // si menu = 4 realiza:
            end_program(); // finaliza el programa
        }
        else
            printf("Respuesta invalida.\n"); // vuelve a escanear la opcion menu
    }
}

int main() {
    Lista_usuarios lista;
    iniciar_lista(&lista); // iniciamos la lista de los usuarios
    usuarios_fichero(&lista); // una vez iniciada, la llenamos con los usuarios registrados en el fichero users.txt

    mostrar_menu(&lista); // mostramos el menu por pantalla
}