#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "Producto2.h"


void mostrarMenu();

int main()
{
	int opcion;
	
	mostrarMenu();
	scanf_s(" %d", &opcion);
	
	
	if (opcion == 1) {
		mostrarArchivo();
	}
	else if (opcion == 2) {
		guardarComo();
	}
	else if (opcion == 3) {
		chequearArchivo();
	}
	system("pause");
    return 0;
	
}
void mostrarMenu() {
	printf("Elige la opcion deseada escribiendo su numero:\n");
	printf("1- Mostrar el contenido de un archivo\n");
	printf("2- Implementar guardar como para un archivo\n");
	printf("3- Chequear el contenido de un archivo\n");
}
