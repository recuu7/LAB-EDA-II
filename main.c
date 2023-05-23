
# include "stdio.h"
# include "funciones_main.h"

int end_program(){
    return 0;
}

void menu_usuario(Lista_usuarios* lista){
    int menu = 0;
    while (menu != 5) {
        printf("\n1) Enviar solicitudes de amistad.\n");
        printf("2) Gestionar las solicitudes pendientes.\n");
        printf("3) Realizar una publicación.\n");
        printf("4) Listar las publicaciones del usuario seleccionado.\n");
        printf("5) Volver al menu principal.\n");
        scanf("%d", &menu);

        if (menu == 1)
            ;
        else if (menu == 2)
            ;
        else if (menu == 3)
            ;
        else if (menu == 4)
            ;
        else if (menu == 5)
            ;
        else
            printf("Respuesta invalida.\n\n");
    }
}

void mostrar_menu(Lista_usuarios* lista){
    int menu = 0;
    while (menu != 4) {
        printf("\n1) Insertar un nuevo usuario.\n");
        printf("2) Listar todos los usuarios existentes.\n");
        printf("3) Operar con un usuario especifico.\n");
        printf("4) Salir.\n");
        scanf("%d", &menu);

        if (menu == 1)
            nuevo_usuario(lista);
        else if (menu == 2)
            lista_todos_usuarios(lista);
        else if (menu == 3)
            menu_usuario(lista);
        else if (menu == 4){
            printf("\nGracias por usar nuestra aplicacion!\n");
            printf("Hecha por Sergi Panyos, Sergi Recuero, David Romero y Saul Ruiz.\n");
            end_program();
        }
        else
            printf("Respuesta invalida.\n\n");
    }
}

int main() {
    Lista_usuarios lista;
    iniciar_lista(&lista);
    FILE* f = fopen("usuarios.txt","r");
    leer_nombres_fichero(f);
    mostrar_menu(&lista);
}