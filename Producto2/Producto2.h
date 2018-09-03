#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
//Esta línea la he tenido que poner para evitar un error con las funciones fopen yfscan
#pragma warning(disable:4996)

void mostrarArchivo() {

	//Defino el máximo de caracteres que leerá fgets en cada invocación
#define BUFFER_SIZE 100
	//Defino la variablepara guardar la ruta del archivo a leer
	char ruta[100];
	//Declaro la variable que albergará el resultado de cada lectura del archivo
	char buffer[BUFFER_SIZE];
	//Declaro puntero tipo FILE
	FILE * fp = NULL;

	//Escrbimos la ruta del archivo y lo almacenamos en la variable creada
	printf("Escriba la ruta del archivo a guardar como\n");
	scanf(" %s", &ruta);

	//Asigno al puntero anterior el archivo pasado por parametro
	fp = fopen(ruta, "r");

	//Mientras no se encuentre la marca de final de archivo el programa leerá gracias a fgets e imprime el resultado por pantalla
	do {
		fgets(buffer, BUFFER_SIZE, fp);
		printf("%s", buffer);
	} while (!feof(fp));
	//Cerramos archivo para liberar recursos
	fclose(fp);
}

void guardarComo() {

	//Defino el máximo de caracteres que leerá fgets en cada invocación
#define BUFFER_SIZE 100
	//Defino las variables par albergar la ruta del archivo original y para la ruta del nuevo archivo
	char ruta[100], rutaNuevo[100];
	//Defino la variable buffer que albergará el resultado de cada lectura del archivo original
	char buffer[BUFFER_SIZE];
	//Declaro dos punteros tipo FILE, uno para el archivo original y otro par el archivo que vamos a crear al guardar como
	FILE * fp = NULL;
	FILE * fp2 = NULL;

	//Introducimos la ruta del archivo a guardar como
	printf("Escriba la ruta del archivo a guardar como\n");
	scanf(" %s", &ruta);

	//Asignamos al puntero fp el archivo pasado por parametro 
	fp = fopen(ruta, "r");

	//Escribimos la ruta del nuevo archivo y lo asignamos a su puntero FILE
	printf("Escribe la  nueva ruta y el nuevo nombre del archivo a guardar como\n");
	scanf(" %s", &rutaNuevo);
	fp2 = fopen(rutaNuevo, "w+");

	//Leemos el contenido del archivo original y lo copiamos en el nuevo hasta la marca EOF
	do {
		fgets(buffer, BUFFER_SIZE, fp);
		fputs(buffer, fp2);
	} while (!feof(fp));
	
	
	//Cerramos los dos archivos		
	fclose(fp);
	fclose(fp2);
	//Borramos el archivo original
	remove(ruta);
}

void chequearArchivo() {

	//Declaro variable para guardar la ruta del archivo
	char ruta[100];
	//Declaro variables para guardar la palabra a buscar y para escanear el texto del archivo
	char palabraABuscar[10], c1[10];
	//Declaro puntero tipo FILE
	FILE * fp = NULL;

	//Escribimos la ruta del archivo a chequear por pantalla
	printf("Escribe la ruta del archivo a chequear\n");
	scanf(" %s", &ruta);

	//Asigno al puntero anterior el archivo pasado por parametro 
	fp = fopen(ruta, "r");

	//Escribimos la palabra a buscar en el archivo
	printf("Escribe la palabra a buscar\n");
	scanf(" %s", &palabraABuscar);

	//Leemos el archivo en busca de la palabra hasta la marca EOF
	
	while (!feof(fp)) {
		fscanf(fp, "%s", c1);
		//Comparamos lapalabra leida en el archivo con la introducida por pantalla
		if (strcmp(c1, palabraABuscar) == 0) {
			printf("SIIII!!! La palabra se encuentra en el archivo!!\n");
			break;
		}
		else {
			if (feof(fp)) {
				printf("OHHH!!!La palabra NO se encuentra en el archivo!!\n");
				break;
			}
		}
	}
	//Cerramos archivo para liberar recursos
	fclose(fp);
}