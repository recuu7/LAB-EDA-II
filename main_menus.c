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
    else
        printf("Password correcto!\n");

    int menu = 0;
    while (menu != 5) {
        printf("\n1) Enviar solicitudes de amistad.\n");
        printf("2) Gestionar las solicitudes pendientes.\n");
        printf("3) Realizar una publicacion.\n");
        printf("4) Listar las publicaciones de @%s.\n", usuario->nombre);
        printf("5) Volver al menu principal.\n");
        scanf("%d", &menu);

        if (menu == 1) {
            menu_solicitudes_enviar(usuario,lista);
            break; }
        else if (menu == 2) {
            break; }
        else if (menu == 3) {
            escribir_publication(usuario);
            break; }
        else if (menu == 4) {
            mirar_publicaciones_usuario(usuario);
            break; }
        else if (menu == 5) return;
        else
            printf("Respuesta invalida.\n\n");
    }
}

void menu_usuarios_existentes(Lista_usuarios* lista) {
    int menu = 0;
    while (menu != 4) {
        printf("\n1) Mostrar todos los usuarios registrados.\n");
        printf("2) Mostrar el ranking de gustos mas comunes.\n");
        printf("3) Mostrar la edad promedio de los usuarios registrados.\n");
        printf("4) Volver al menu principal.\n");
        scanf("%d",&menu);

        if (menu == 1) {
            lista_todos_usuarios(lista);
            break; }
        else if (menu == 2) {
            top_3_dictionary();
            break; }
        else if (menu == 3)
            break;
        else if (menu == 4) return;
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
        printf("2) Interactuar con usuarios existentes.\n");
        printf("3) Operar con un usuario especifico.\n");
        printf("4) Salir.\n");
        scanf("%d", &menu);

        if (menu == 1)
            nuevo_usuario(lista);
        else if (menu == 2)
            menu_usuarios_existentes(lista);
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

    usuarios_fichero(&lista);

    mostrar_menu(&lista);
}