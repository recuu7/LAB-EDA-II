# ESTRUCTURA DE DATOS Y ALGORITMOS 2
Creación de una red social : (NOMBRE)

## NOMBRE Y NIA DE LOS ESTUDIANTES:
Sergi Paños ---- : 

Sergi Recuero Fonquerna : 269094

David Romero Garriga : 266572

Saül Ruíz Cazáñez :

### FECHA DE ENTREGA:
08-06-2023

#### INFORME DEL PROYECTO:
##### ÍNDICE:

1. Introducción

2. Objetivos del proyecto
      
    2.1 Objetivos obligatorios

    2.2 Objetivos deseables
    
    2.3 Objetivos de exploración
 
3. Solución

    3.1 Arquitectura del sistema
    
    3.2 Gestión de errores

    3.3 Diseño del modelo de datos
    
    3.4 Descripción y procesamiento del conjunto de datos


###### INTRODUCCIÓN

Al entrar en nuestras respectivas carreras universitarias,los miembros de nuestro grupo no sabíamos lo que nos esperaba y teníamos un cierto sentimiento de incertidumbre sobre nuestro futuro, sin embargo, nos encontramos rápidamente aprendiendo diversos lenguajes de programación desde cero (ninguno de nosotros había programado nunca). Hemos ido mejorando nuestras habilidades como programadores trimestre a trimestre, comenzando con lo más básico qué es Python y llegando hasta el inicio de nuestra práctica de EDA 2, teniendo delante nuestro el reto de crear nuestra propia red social desde cero. Comenzamos informándonos en Internet sobre la principal temática que trataría nuestra red social inspirándonos en varias páginas web, foros y vídeos que nos ayudaron a tomar nuestra decisión. Después de estar durante un largo tiempo pensando, un día decidimos reunimos todos los miembros del grupo y finalmente decidimos que en lugar de orientarla hacia un tema en concreto, haríamos una red social muy parecida a twitter, es decir una red social que alberga cualquier tema. Decidimos crear una nueva plataforma en la que se pudieran crear usuarios que pudieran: publicar imágenes, agregar amigos, gestionar las solicitudes de amistad y listar sus publicaciones. Para escoger qué tipo de actividad quieres hacer, en el inicio se te mostrará en pantalla un menú principal con un listado de opciones, dónde depende de lo que quieras hacer, deberás poner una cosa u otra. El motivo por el cual creímos que era mejor crear una red social que engloba cualquier tema, es porque pensamos que era más útil para los usuarios, porque pensamos que de esta manera más gente la usaría. En este informe hablaremos primero  sobre cómo hemos trabajado en estas funcionalidades, sobre el planteamiento que hemos tenido de cada una, su desarrollo, problemas encontrados mientras trabajabamos en ellas y las soluciones encontradas. Después de explicar los objetivos cumplidos e intentados, mostraremos nuestro producto final, como hemos controlado los errores, el diseño final, dónde hemos implementado cada objetivo, etc. El informe concluye con la bibliografía, donde citaremos todas las páginas web y libros que nos han ayudado durante la práctica.

#### OBJETIVOS DEL PROYECTO

#### OBJETIVOS OBLIGATORIOS

### Implementar funcionalmente uno de los algoritmos de búsqueda que se verán dentro del curso (LinearSearch o BinarySearch) 
Hemos decidido implementar funcionalmente el algoritmo de búsqueda Lineaearch ,que nos ha ayudado en el apartado de las listas de amigos, permitiéndonos buscar el nombre de algún amigo en concreto dentro de ellas. Este algoritmo de búsqueda lineal realiza una búsqueda secuencial en una lista de elementos comparando cada uno con el valor buscado hasta encontrar una coincidencia o hasta llegar al final de la lista. 

#### Variables
Las variables que hemos utilizado en este algoritmo son “cola_usuarios” y “nombre”. Las dos variables tienen un puntero delante por lo que significa que apuntan a una estructura de datos. En el caso de la primera, apuntan a una estructura llamada Cola, la cual se muestra a continuación: P O N ER L A I M A G E N. Como podemos observar, esta estructura llamada “Cola”, contiene 3 variables. En primer lugar la variable “size” la cual es un entero y que nos servirá para definir el tamaño de la array que utilizamos. En segundo lugar, vemos que tanto la segunda variable como la tercera tienen punteros a delante por lo que también sabemos que apuntan a otra estructura de datos. Estas dos últimas variables, básicamente sirven para saber identificar el primer y el último elemento de la cola, para así poder operar fácilmente con ellas. A continuación muestro la estructura de datos a a la cual apuntan las dos últimas variables de la estructura llamada “Cola”. P O N E R I M A G E N 

### Porque hemos escogido este algoritmo?
Hemos escogido este algoritmo de búsqueda porque creemos que es el más sencillo para aplicar a una lista y a una cola. 

### Funcionamiento 
Su comportamiento esperado es iterar la lista posición por posición (como indica su nombre, linealmente) hasta encontrar el nombre del amigo que el usuario quiere encontrar. La ejecución de la función termina cuando encontramos el nombre del amigo deseado o cuando iteramos toda la lista sin llegar a encontrarlo. 

### Complejidad del algoritmo
El algoritmo tiene una complejidad temporal de O(n), donde n es el número de elementos en la lista. Esto significa que el tiempo de ejecución aumenta de manera proporcional al tamaño de la lista. 

### Limitaciones y posibles soluciones 
La principal limitación de nuestro algoritmo de búsqueda es que al ser una búsqueda lineal es de los algoritmos de búsqueda más lentos y  que ejecuta un mayor número de veces que cualquier otro cuando nos encontramos en el peor de los casos, esto se puede ver reflejado en el tiempo de ejecución del mismo. Esta limitación se haría visible sobretodo en el caso de que tuviéramos que buscar un amigo en concreto dentro de un usuario con miles o incluso millones de amigos, que de momento no es el caso en nuestra red social. Para la creación de estas estrcuturas hemos tardado más o menos diez minutos por cada una, lo que suma un total de 20 minutos. El motivo de haber tardado este tiempo, es porque al principio teníamos muchas dudas sobre en que situaciones se tenían que usar punteros o simplemente variables. En cuanto a este algoritmo, no habría nada que mejorar, pero en cuanto a la red social en sí, sería más práctico sustituir nuestro algoritmo de búsqueda por uno del tipo BinarySearch por ejemplo, que reduciría el tiempo medio de búsqueda así como de el número de ejecuciones del algoritmo. 

**Ubicación del algoritmo:** La función se encuentra entre las líneas 23 y 31 del archivo *'amistades.c'*
   



