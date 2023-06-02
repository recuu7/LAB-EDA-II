# include "stdio.h"
# include "estructuras_y_funciones.h"

int end_program(){
    printf("\nGracias por usar nuestra aplicacion!\n");
    printf("Hecha por Sergi Panyos, Sergi Recuero, David Romero y Saul Ruiz.\n");
    return 0;
}

void menu_usuario(Lista_usuarios* lista){
    User* usuario = elegir_usuario(lista);
    if (usuario == NULL)
        return;

    int a = login(usuario);
    if (a != 1) {
        printf("Password incorrecto!\n");
        return;
    }

    int menu = 0;
    while (menu != 5) {
        printf("\n1) Enviar solicitudes de amistad.\n");
        printf("2) Gestionar las solicitudes pendientes.\n");
        printf("3) Realizar una publicacion.\n");
        printf("4) Listar las publicaciones de @%s.\n", usuario->nombre);
        printf("5) Volver al menu principal.\n");
        scanf("%d", &menu);

        if (menu == 1)
            enviar_solicitud_a_usuario(lista,usuario);
        else if (menu == 2)
            return;
        else if (menu == 3)
            return;
        else if (menu == 4)
            return;
        else if (menu == 5)
            return;
        else
            printf("Respuesta invalida.\n\n");
    }
}

void mostrar_menu(Lista_usuarios* lista){
    printf("BIENVENIDO!\n\n");
    int menu = 0;
    while (menu != 4) {
        printf("Que desea hacer?\n");
        printf("1) Insertar un nuevo usuario.\n");
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
        else if (menu == 4) {
            end_program();
        }
        else
            printf("Respuesta invalida.\n");
    }
}

int main() {
    Lista_usuarios lista;
    iniciar_lista(&lista);

    mostrar_menu(&lista);
}