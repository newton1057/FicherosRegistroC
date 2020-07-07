/*2. Desarrolle un programa que permita leer el archivo creado en el punto anterior, y que muestre el
contenido en pantalla. Su programa solo puede preguntar por el nombre del archivo, mostrar el número
de empleados (registros) guardados y la información de cada empleado. */
#include <stdlib.h>
#include <stdio.h>

int main(){
 	FILE *archivo;
	char caracter;
	char nombre[50];
	
	printf("Nombre del archivo: ");
	scanf(" %[^\n]",&nombre);
	
	archivo = fopen(nombre,"r");
	
	if (archivo == NULL){
        printf("\nError de apertura del archivo. \n\n");
    }else{
        printf("\nBase de Datos  \n\n");
        while((caracter = fgetc(archivo)) != EOF){
		printf("%c",caracter);
	    }
    }
    fclose(archivo);
 	
 	return 0;
}
