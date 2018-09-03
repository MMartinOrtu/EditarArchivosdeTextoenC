# EditarArchivosdeTextoenC

Proyecto para crear una aplicación de consola en C para editar archivos de texto, realizado como ejercicio en el Ciclo de Técnico Superior en Desarrollo de Aplicacions Multiplataforma en la UOC.

Los archivos se encuentran dentro de la carpeta "Proyecto2".

Este proyecto ha sido realizado en C con Visual Studio.

En este ejercicio he desarrollado una aplicación de consola en C con 3 funciones para manipular archivos en C.

La clave para la manipulación de archivos en C es la declaración de una variable de tipo FILE, que es un apuntador al archivo que le indiquemos.

1. Configuración del Menú:
En primer lugar se ha configurado una función mostrarMenu(); para que muestre por pantalla las distintas opciones que el usuario puede elegir.

2. Opción 1: Mostrar el contenido de un archivo:
Al seleccionar esta opción se ejecuta la función mostrarArchivo();
Esta función nos pide la ruta de un archivo a mostrar (En nuestro caso hemos creado un archivo txt llamado “archivo1.txt” dentro de la carpeta de del proyecto, por lo que basta con escribir como ruta el nombre del archivo con su extensión).
El archivo1.txt contiene el siguiente texto en mayúsculas “HOLA SOY MIGUEL”.
La ruta del archivo se guarda en una variable que hemos llamado “ruta” a la que después se le asigna un puntero FILE “fp”.
Después se lee el archivo con la función fgets, que almacena el contenido del archivo en una variable que hemos llamado “buffer”.
El resultado de la lectura se muestra por pantalla y posteriormente se cierra el archivo.

3. Opción 2: Implementar guardar como de un archivo:
Al seleccionar esta opción se ejecuta la función guardarComo();
Esta función nos pide la ruta de un archivo a mostrar (escribimos la misma ruta que en la opción anterior: “archivo1.txt”).
La ruta del archivo se guarda en una variable que hemos llamado “ruta” a la que después se le asigna un puntero FILE “fp”.
En este caso declaramos un segundo puntero FILE “fp2”, para el archivo nuevo que vamos a crear
Escribimos por pantalla la ruta del nuevo archivo, que se almacena en la variable “nuevaRuta” y le asignamos el puntero fp2, que con la opción w+ crea el archivo con el nombre que le hemos asignado.
Con fgets y fputs, leemos y copiamos el contenido del archivo original en el archivo nuevo (usamos de nuevo la variable “buffer”).
Finalmente,  cerramos los 2 archivos y con la función “remove”, eliminamos el archivo original.

4. Opción 3: Chequear el contenido de un archivo:

Al seleccionar esta opción se ejecuta la función chequearArchivo();
Esta función nos pide la ruta de un archivo a mostrar.
La ruta del archivo se guarda en una variable que hemos llamado “ruta” a la que después se le asigna un puntero FILE “fp”.
Después el programa nos pide que introduzcamos la palabra a buscar y la guarda en la variable “palabraABuscar”.
Posteriormente se lee el archivo, palabra por palabra, con la función fscanf. Cada palabra leída en el archivo se compara con la palabra almacenada en “palabraABuscar” con la función para comparar cadenas “strcmp”.
Si coinciden, se muestra un mensaje por pantalla, afirmando que esa palabra se encuentra en el archivo. Si no coinciden, se muestra el mensaje contrario.
Para finalizar se cierra el archivo.

