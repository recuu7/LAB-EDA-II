
# include "stdio.h"
# include "funciones_main.h"

void mostrar_menu(){
    printf("1) Insertar un nuevo usuario.\n");
    printf("2) Listar todos los usuarios existentes.\n");
    printf("3) Operar con un usuario especifico.\n");
    printf("4) Salir.\n");
}

void menu_usuario(){
    printf("1) Enviar solicitudes de amistad.\n");
    printf("2) Gestionar las solicitudes pendientes.\n");
    printf("3) Realizar una publicación.\n");
    printf("4) Listar las publicaciones del usuario seleccionado.\n");
    printf("5) Volver al menu principal.\n");
}

int main() {
    Lista_usuarios lista;
    iniciar_lista(&lista);

    mostrar_menu();
    int menu, operar_usuario, bucle = 0;
    scanf("%d", &menu);
    while (bucle != 1) {
        while (menu != 4) {
            if (menu == 1)
                nuevo_usuario(&lista);
            else if (menu == 2)
                lista_todos_usuarios(&lista);
            else if (menu == 3) {
                menu_usuario();
                scanf("%d", &operar_usuario);
                if (operar_usuario == 1)
                    return 0;
                else if (operar_usuario == 2)
                    return 0;
                else if (operar_usuario == 3)
                    return 0;
                else if (operar_usuario == 4)
                    return 0;
                else if (operar_usuario == 5)
                    main();
                else {
                    printf("Introduce una opcion valida.\n");
                    scanf("%d", &operar_usuario);
                }
            } else {
                printf("Introduce una opcion valida.\n");
                scanf("%d", &menu);
            }
            mostrar_menu();
            scanf("%d", &menu);
        }
        printf("Gracias por usar nuestra aplicacion!\n");
        printf("Hecha por Sergi Panyos, Sergi Recuero, David Romero y Saul Ruiz.\n");
        bucle = 1;
    }
}