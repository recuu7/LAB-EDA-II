# LAB-EDA-II

void menu(){
  printf("a) Insertar un nuevo usuario.\n");
  printf("b) Listar todos los usuarios existentes.\n");
  printf("c) Operar con un usuario especifico.\n");
  printf("d) Salir.\n"); }
  
void menu_usuario(){
  printf("a) Enviar solicitudes de amistad.\n");
  printf("b) Gestionar las solicitudes pendientes.\n");
  printf("c) Realizar una publicación.\n");
  printf("d) Listar las publicaciones del usuario seleccionado.\n");
  
int exit(){
  return 0; }

void main(){
  menu();
  char menu, operar_usuario;
  scanf("%c", menu);
  
  if(menu == 'a'){
    nuevo_usuario(); }
  else if(menu == 'b'){
    lista_usuarios(); }
  else if(menu == 'c'){
    menu_usuario();
    scanf("%c", operar_usuario);
    if(operar_usuario == 'a'){
      enviar_solicitud(); }
    else if(operar_usuario == 'b'){
      
    
    


  
  
