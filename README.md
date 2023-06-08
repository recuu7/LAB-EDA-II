# LAB EDA 2
Creación de una red social : CREACIÓN DE UNA RED SOCIAL

## VIDEO DEL PROYECTO
https://youtu.be/1cMZsFbgbe0

## NOMBRE Y NIA DE LOS ESTUDIANTES:
Sergi Paños Garnica: 267895 

Sergi Recuero Fonquerna : 269094

David Romero Garriga : 266572

Saül Ruíz Cazáñez : 267887

## FECHA DE ENTREGA:
08-06-2023

## INFORME DEL PROYECTO:
#### ÍNDICE:

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


### INTRODUCCIÓN

Al entrar en nuestras respectivas carreras universitarias, los miembros de nuestro grupo no sabíamos lo que nos esperaba y teníamos un cierto sentimiento de incertidumbre sobre nuestro futuro, sin embargo, nos encontramos rápidamente aprendiendo diversos lenguajes de programación desde cero (ninguno de nosotros había programado nunca). Hemos ido mejorando nuestras habilidades como programadores trimestre a trimestre, comenzando con lo más básico qué es Python y llegando hasta el inicio de nuestra práctica de EDA 2, teniendo delante nuestro el reto de crear nuestra propia red social desde cero. 

Comenzamos informándonos en Internet sobre la principal temática que trataría nuestra red social inspirándonos en varias páginas web, foros y vídeos que nos ayudaron a tomar nuestra decisión. Después de estar durante un largo tiempo pensando, un día decidimos reunimos todos los miembros del grupo y finalmente decidimos que en lugar de orientarla hacia un tema en concreto, haríamos una red social muy parecida a twitter, es decir una red social que alberga cualquier tema. Decidimos crear una nueva plataforma en la que se pudieran crear usuarios que pudieran: publicar imágenes, agregar amigos, gestionar las solicitudes de amistad y listar sus publicaciones. Para escoger qué tipo de actividad quieres hacer, en el inicio se te mostrará en pantalla un menú principal con un listado de opciones, dónde depende de lo que quieras hacer, deberás poner una cosa u otra. 

El motivo por el cual creímos que era mejor crear una red social que engloba cualquier tema, es porque pensamos que era más útil para los usuarios, porque pensamos que de esta manera más gente la usaría. En este informe hablaremos primero  sobre cómo hemos trabajado en estas funcionalidades, sobre el planteamiento que hemos tenido de cada una, su desarrollo, problemas encontrados mientras trabajabamos en ellas y las soluciones encontradas. Después de explicar los objetivos cumplidos e intentados, mostraremos nuestro producto final, como hemos controlado los errores, el diseño final, dónde hemos implementado cada objetivo, etc. El informe concluye con la bibliografía, donde citaremos todas las páginas web y libros que nos han ayudado durante la práctica.

## OBJETIVOS DEL PROYECTO

## OBJETIVOS OBLIGATORIOS

## Implementar funcionalmente uno de los algoritmos de búsqueda que se verán dentro del curso (LinearSearch o BinarySearch) 
Hemos decidido implementar funcionalmente el algoritmo de búsqueda Lineaearch ,que nos ha ayudado en el apartado de las listas de amigos, permitiéndonos buscar el nombre de algún amigo en concreto dentro de ellas. Este algoritmo de búsqueda lineal realiza una búsqueda secuencial en una lista de elementos comparando cada uno con el valor buscado hasta encontrar una coincidencia o hasta llegar al final de la cola. 

#### Variables
Las variables que hemos utilizado en este algoritmo son “cola_usuarios” y “nombre”. Las dos variables tienen un puntero delante por lo que significa que apuntan a una estructura de datos. En el caso de la primera, apuntan a una estructura llamada Cola. Como podemos observar en nuestras líneas de código , esta estructura llamada “Cola”, contiene 3 variables. En primer lugar la variable “size” la cual es un entero y que nos servirá para definir el tamaño de la array que utilizamos. En segundo lugar, vemos que tanto la segunda variable como la tercera tienen punteros a delante por lo que también sabemos que apuntan a otra estructura de datos. Estas dos últimas variables apuntan a la estructura de datos llamada Node_Cola y básicamente sirven parapoder identificar el primer y el último elemento de la cola, para así poder operar fácilmente con ellas. 

#### Porque hemos escogido este algoritmo?
Hemos escogido este algoritmo de búsqueda porque creemos que es el más sencillo para aplicar a una lista y a una cola. 

#### Funcionamiento 
Su comportamiento esperado es iterar la lista posición por posición (como indica su nombre, linealmente) hasta encontrar el nombre del amigo que el usuario quiere encontrar. La ejecución de la función termina cuando encontramos el nombre del amigo deseado o cuando iteramos toda la lista sin llegar a encontrarlo. 

#### Complejidad del algoritmo
El algoritmo tiene una complejidad temporal de O(n), donde n es el número de elementos en la lista. Esto significa que el tiempo de ejecución aumenta de manera proporcional al tamaño de la lista. 

#### Limitaciones y posibles soluciones 
La principal limitación de nuestro algoritmo de búsqueda es que al ser una búsqueda lineal es de los algoritmos de búsqueda más lentos y  que ejecuta un mayor número de veces que cualquier otro cuando nos encontramos en el peor de los casos, esto se puede ver reflejado en el tiempo de ejecución del mismo. Esta limitación se haría visible sobretodo en el caso de que tuviéramos que buscar un amigo en concreto dentro de un usuario con miles o incluso millones de amigos, que de momento no es el caso en nuestra red social. Para la creación de estas estrcuturas hemos tardado más o menos diez minutos por cada una, lo que suma un total de 20 minutos. El motivo de haber tardado este tiempo, es porque al principio teníamos muchas dudas sobre en que situaciones se tenían que usar punteros o simplemente variables. En cuanto a este algoritmo, no habría nada que mejorar, pero en cuanto a la red social en sí, sería más práctico sustituir nuestro algoritmo de búsqueda por uno del tipo BinarySearch por ejemplo, que reduciría el tiempo medio de búsqueda así como de el número de ejecuciones del algoritmo. 

#### Tiempo:
Alrededor de 30 min ya que el algoritmo linearSearch lo hemos usado en seminarios y es de los algoritmos mas sencillos de programar. También, como era de las primeras lineas de código tardamos un poco mas ya que aun no habiamos practicado tanto.

#### Ubicación del algoritmo:
La función se encuentra entre las líneas 23 y 31 del archivo *'amistades.c'*

### Implementar como mínimo una Lista (List), una Pila (Stack) y una Cola (Queue) funcionales como parte de alguna de las funcionalidades del proyecto.
Hemos conseguido implementar satisfactoriamente tanto la Lista como la Pila y la Cola. Cada una hace una funcion diferente en nuestro codigo. 

La **Lista** la hemos usado para la lista de usuarios ya que era la opción mas eficaz para ello debido a que es facil de recorrer y modificar. Para ello hemos creado dos estructuras dentro del fichero estructuras_y_funciones,h , llamadas Node_Lista y Lista_Usuarios.

La **Pila** la hemos usado para las solicitudes de amistad, en teoria en la guia esta salia que debia ser una cola pero nosotros hemos pensado que en muchas redes sociales que usamos hoy en dia, la primera solicitud que llega es la que se queda abajo y por lo tanto sale la ultima.


La **Cola** ha sido usada para la lista de amigos de un usuario ya que tambien es facil de recorrer.

### Implementar funcionalmente uno de los algoritmos de ordenamiento que se verán a lo largo del curso (InsertionSort, BubbleSort, MergeSort o QuickSort).
El algoritmo de búsqueda que hemos decidido implementar es el Bubble Sort, que hemos utilizado en nuestro caso para ordenar los gustos de los usuarios (de más a menos común) dentro de un diccionario. A continuación, explicaremos algunos aspectos en relación a la implementación del algoritmo.

#### Variables
- La variable "diccionario" es un puntero a una estructura de tipo "Diccionario". Esta estructura contiene los siguientes campos:
      · "elemento": es un puntero a una estructura de tipo "Elementos". Este campo almacena los elementos del diccionario.
      · "size": indica el número actual de elementos en el diccionario.
      ·"capacity": indica la capacidad máxima del diccionario.
      
#### ¿Qué estructuras de datos se eligieron para este objetivo? ¿Cuál es su uso esperado?
-Se utilizaron dos estructuras de datos principales:
      ·"Elementos": es una estructura que contiene dos campos, "count" de tipo entero, para almacenar la cantidad y "gusto" de tipo array       para almacenar la descripción del gusto.
      ·"Diccionario": es una estructura que contiene tres campos, "elemento" que es un puntero a una matriz de elementos, "size" que            indica el número actual de elementos en el diccionario y "capacity" que indica la capacidad máxima del diccionario. Esta                  estructura se utiliza para almacenar y gestionar los elementos del diccionario.
      
#### ¿Qué algoritmo se eligió para este objetivo? ¿Cuál es su comportamiento esperado? ¿Y su rendimiento en Big O?
El algoritmo elegido es el Bubble Sort. Este algoritmo funciona comparando elementos adyacentes y realizando intercambios si están en el orden incorrecto. El proceso se repite hasta que el array esté completamente ordenado.

El comportamiento esperado del Bubble Sort es ordenar los elementos del diccionario de acuerdo a su atributo "count" (las veces que aparece cada gusto) de mayor a menor.

En cuanto a su rendimiento en Big O, el Bubble Sort tiene una complejidad de O(n^2), donde "n" es el número de elementos en el diccionario. Esto significa que su rendimiento empeora significativamente a medida que el tamaño del diccionario aumenta.

#### ¿Qué limitaciones tiene el algoritmo? ¿Y su implementación?
El Bubble Sort tiene algunas limitaciones, como su rendimiento ineficiente para grandes conjuntos de datos debido a su complejidad de tiempo cuadrática. A simple vista, puede parecer un error que en la implementación actual del algoritmo no se considera la posibilidad de elementos duplicados en el diccionario. Si dos elementos tienen el mismo valor "count", el algoritmo no garantiza un orden específico para esos elementos. No obstante esto no puede suceder ya que el algoritmo lee solamente ficheros de texto, en los que no hay elementos repetidos.

#### ¿Qué se puede mejorar?
Para mejorar el rendimiento,podríamos considerar implementar otros algoritmos de ordenamiento más eficientes, como el Quick Sort o Merge Sort, que tienen una complejidad de tiempo inferior a O(n^2) de promedio O8n log n).

Si necesitaramos mantener el orden de los elementos con el mismo valor "count" y se diera el caso, podríamos agregar criterios adicionales para comparar los elementos, como ordenar alfabéticamente por el campo "gusto" en caso de empate.

### Implementar o bien un Diccionario (Dictionary) o bien una tabla Hash (HashTable) funcionales.

La función leer_gustos implementa la lectura de datos desde un archivo de texto llamado "dictionary.txt" y los almacena en una estructura de datos llamada Diccionario. A continuación, proporcionamos una descripción de las características principales de la implementación:

#### Variables utilizadas y su propósito:

- f: Un puntero a un archivo que se utiliza para abrir el archivo "dictionary.txt".
- buffer: Un arreglo de caracteres utilizado como un buffer temporal para almacenar cada línea leída del archivo.
- gusto: Una variable de tipo cadena (arreglo de caracteres) utilizada para almacenar el valor de gusto leído de cada línea del archivo.
- count: Una variable de tipo entero utilizada para almacenar el valor de count leído de cada línea del archivo.
elemento: Una variable de tipo Elementos que representa un elemento del diccionario, con campos count y gusto para almacenar los valores correspondientes.
- diccionario: Una estructura de datos de tipo Diccionario que contiene un arreglo dinámico de elementos y mantiene el tamaño y la capacidad actual del diccionario.

#### Estructuras de datos utilizadas:

- Elementos: Una estructura que representa un elemento del diccionario, con dos campos: count de tipo entero y gusto de tipo cadena (arreglo de caracteres). Los elementos se almacenan en un arreglo dinámico dentro de la estructura Diccionario.
- Diccionario: Una estructura que mantiene un arreglo dinámico de elementos (elemento), así como el tamaño actual (size) y la capacidad total (capacity) del diccionario.

#### Algoritmo elegido y comportamiento esperado:

El algoritmo que hemos utilizado en esta función es un proceso de lectura e interpretación de líneas, encontradas en un archivo de texto.
Hemos utilizado un bucle while junto con la función fgets para leer cada línea del archivo y almacenarla en el buffer.
Luego, usamos la función sscanf para extraer los valores de gusto y count desde el buffer. A continuación, se crea una nueva instancia de Elementos, se asignan los valores leídos a los campos correspondientes y se agrega al arreglo de elementos del diccionario. Si el tamaño actual del diccionario alcanza su capacidad máxima, se duplica la capacidad del diccionario utilizando realloc para asignar más memoria.
Después de leer todas las líneas del archivo, se cierra el archivo.

#### Desempeño en Big O:
El bucle while recorre todas las líneas del archivo una vez, por lo que tiene una complejidad de O(N), donde N es el número de líneas en el archivo.

#### Posibles mejoras:

Podríamos agregar validaciones y un manejo de errores robusto para garantizar que los datos leídos sean válidos y que el proceso de asignación de memoria sea exitoso.
También podríamos agregar opciones para especificar el nombre del archivo y el formato de entrada, lo que nos permitiría una  mayor flexibilidad en la lectura de datos de diferentes archivos con diferentes formatos.

### Todas las partes importantes de tu código deben estar comentadas (Funciones, ciclos, secciones de código con una funcionalidad definida, secciones con una lógica dificil de entender a simple vista, entre otros), una buena guía de cómo comentar código en C la puedes encontrar en https://learn.microsoft.com/es-es/cpp/c-language/c-comments?view=msvc-170 

Hemos comentado todas las partes importantes o que podrían llegar a ser confusas de nuestro código, además de comentarlas en este mismo informe.

### Usar github para que todos los miembros del equipo puedan trabajar a la par y más cómodamente. Los diferentes miembros del equipo deben mostrar actualizaciones del código constantes.

Hemos hecho uso de github el primer día de prácitca, en el que nos leímos su respectiva guía del colgada en el AulaGlobal. Nos ha sido muy útil a al hora de compenetrarnos como grupo, pudiendo trabajar a la vez o por separado sin ningún tipo de problema al respecto, para completar los objetivos establecidos pro las entregas de la práctica y por los mismos miembros del grupo. 


## Objetivos Deseables:
### Leer datos de una fuente externa como un archivo de texto o CSV (No implica guardado de datos)

### Implementar las funcionalidades de lectura y guardado de datos (Información de los usuarios y sus contactos, y demás que se quiera añadir) desde un archivo externo (.txt o csv) 


## Objetivos de Exploración:
### Funciones de control de usuarios (media de Edad, gustos).

## Solutions

### Arquitectura del sistema

### Gestión de errores
Durante lo largo del proyecto, a medida que hemos ido desarrollando el proyecto, nos han aparecido muchos errores en todos lados y que nos ha costado mucho tiempo el saber corregirlos para que por fin compilase y para que estos desaparecieran. Básicamente cuando un miembro del grupo tenia dudas sobre como resolver cualquier error, lo que hemos ido haciendo, primero de todo ponerlo en común con todos los miembros del grupo para saber si lo podiamos resolver entre nosotros sin la necesidad de preguntar a alguien externo a nuestro grupo. Si nadie lo sabia resolver, lo que haciamos es buscar información a través de internet en varias páginas como por ejemplo usando la inteligencia artificial de CHAT GPT, ya que nos ayudaba mucho para sobretodo tener saber el como y el porque lo solucionava de dicha manera. Sin embargo, tamboén hemos recurrido a vídeos ya sea en youtube o en otras plataformas. en el caso del chat gpt, cuando nos resolvia el error que le proporcionabamos para que nos lo corrijiera, lo primero que hacíamos era comprovarlo en el CLion para saber si realmente estaba bién resuelto y corregido. Si no estaba bien corregido, lo que haciamos era intentar compararlo con gente de otro grupo para ver en que nos podiamos estar equivocando o confundiendo.

### Diseño del modelo de datos

### Descripción y procesamiento del conjunto de datos


