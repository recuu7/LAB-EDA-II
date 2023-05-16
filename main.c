# LAB_EDA_II
# include "stdio.h"
# include "funciones_main.h"

void menu(){
    printf("a) Insertar un nuevo usuario.\n");
    printf("b) Listar todos los usuarios existentes.\n");
    printf("c) Operar con un usuario especifico.\n");
    printf("d) Salir.\n");
}

void menu_usuario(){
    printf("a) Enviar solicitudes de amistad.\n");
    printf("b) Gestionar las solicitudes pendientes.\n");
    printf("c) Realizar una publicación.\n");
    printf("d) Listar las publicaciones del usuario seleccionado.\n");
    printf("e) Volver al menu principal.\n");
}

int end_program(){
    return 0;
}

int main() {
    menu();
    char menu, operar_usuario;
    User usuarios;
    scanf("%c", &menu);

    if (menu == 'a')
        nuevo_usuario(&usuarios);
    else if (menu == 'b')
        lista_usuarios();
    else if (menu == 'c') {
        menu_usuario();
        scanf("%c", &operar_usuario);
        if (operar_usuario == 'a')
            enviar_solicitud();
        else if (operar_usuario == 'b')
            gestionar_solicitudes();
        else if (operar_usuario == 'c')
            publicar();
        else if (operar_usuario == 'd')
            publicaciones_usuario();
        else if (operar_usuario == 'e')
            main();
        else {
            printf("Introduce una opcion valida.\n");
            scanf("%c", &operar_usuario);
        }}
    else if (menu == 'd')
        end_program();
    else {
        printf("Introduce una opcion valida.\n");
        scanf("%c", &menu);
    }
}