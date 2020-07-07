/*1. Desarrolle un programa que permita capturar M registros, en donde cada registro es la abstracción de
un empleado cuyos campos son: nombre, número de empleado, días de la semana que labora (puede
elaborar 1 o los 7 días) y sueldo. Usted define el tipo de dato asociado a cada campo. El programa
preguntará por M y permitirá capturar esos M registros, para después guardar esos M registros en un
archivo con el nombre que usted desee.*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char nombre[50];
	int id_empleado;
	int num_dias;
	int dias_elaboracion[10];
}empleados;

void registrar(empleados *date, int num_empleados);
void imprimir_semana();
void buscar_todos(empleados *date, int num_empleados);
void registrar_archivo(empleados *date, int num_empleados);

int main(){
	empleados *p;
	int num_empleados=0,opcion=0;
	
	printf("Cuantos empleados registraras: ");
	scanf("%d", &num_empleados);
	
	p = (empleados *)malloc(num_empleados*sizeof(empleados));
	
	registrar(p, num_empleados);
	
	printf("EMPLEADOS REGISTRADOS CON EXITO!! ");
	
	do{
        // Menu principal
    	printf("\n");
        printf("Escoja una opcion:");
        printf("\n1.- Mostrar los datos de los empleados");
        printf("\n2.- Registrar los datos en Archivo .txt");
        printf("\n3.- Salir\n");
      	
	  	scanf("%d", &opcion);
 		printf("\n");
        // Hacemos una cosa u otra según la opción escogida
        switch(opcion){
        	case 1:
        		buscar_todos(p,num_empleados);//Funcion para imprimir los registros
				break;
        	case 2:
           		registrar_archivo(p,num_empleados);//Funcion para almacenar los registros en un archivo
				break;	
	 		case 3: 
	 			printf("SALIENDO!!\n");
	 			system("PAUSE");
			 	break;
		}				   
  	}while (opcion != 3);
  return 0;
}

void registrar(empleados *date, int num_empleados){
	int i=0,j=0,aux=0;
	for(i=0;i<num_empleados;i++){
		date[i].id=i;
		printf("Dame tu nombre completo: ");
		scanf(" %[^\n]",&date[i].nombre);
		printf("ID del Empleado: ");
		scanf("%d",&date[i].id_empleado);
		printf("Numero de dias laborados: ");
		scanf(" %d",&date[i].num_dias);
		imprimir_semana();//Llamar funcion para imprimir dias de la semana
		for(j=0;j<date[i].num_dias;j++){
			printf("Dia Numero %d: ",j+1);
			scanf(" %d",&aux);
			date[i].dias_elaboracion[j]=aux;
		}		
	}
}

void imprimir_semana(){
	printf("Dias:\n");
	printf("1.-Lunes\n");
	printf("2.-Martes\n");
	printf("3.-Miercoles\n");
	printf("4.-Jueves\n");
	printf("5.-Viernes\n");
	printf("6.-Sabado\n");
	printf("7.-Domingo\n");
}

void buscar_todos(empleados *date, int num_empleados){
	int i=0,j=0,aux=0,dia=0;
	for(i=0;i<num_empleados;i++,date++){
		printf("ID: %d\n",  date->id );
		printf("Nombre del empleado: %s\n", date->nombre);
		printf("ID del empleado: %d\n", date->id_empleado);
		printf("Dias Elaborados:\n");
		aux = date->num_dias;
		for (j=0;j<aux;j++){
			dia = date->dias_elaboracion[j];
			if(dia==1){
				printf("Lunes\n");
			}
			if(dia==2){
				printf("Martes\n");
			}
			if(dia==3){
				printf("Miercoles\n");
			}
			if(dia==4){
				printf("Jueves\n");
			}
			if(dia==5){
				printf("Viernes\n");
			}
			if(dia==6){
				printf("Sabado\n");
			}
			if(dia==7){
				printf("Domingo\n");
			}
		}
		printf("\n\n");
	}
}

void registrar_archivo(empleados *date, int num_empleados){
	FILE *archivo;
 	int i=0,j=0,aux=0,dia=0,aux_int=0;
 	char nombre[50];
 	
 	printf("Nombre del archivo: ");
	scanf(" %[^\n]",&nombre);
	
 	archivo = freopen(nombre, "w+", stdout);//dirigimos la salida de datos al archivo
 	
	for(i=0;i<num_empleados;i++,date++){
		printf("ID: %d\n",  date->id );
		printf("Nombre del empleado: %s\n", date->nombre);
		printf("ID del empleado: %d\n", date->id_empleado);
		printf("Dias Elaborados:\n");
		aux = date->num_dias;
		for (j=0;j<aux;j++){
			dia = date->dias_elaboracion[j];
			if(dia==1){
				printf("Lunes\n");
			}
			if(dia==2){
				printf("Martes\n");
			}
			if(dia==3){
				printf("Miercoles\n");
			}
			if(dia==4){
				printf("Jueves\n");
			}
			if(dia==5){
				printf("Viernes\n");
			}
			if(dia==6){
				printf("Sabado\n");
			}
			if(dia==7){
				printf("Domingo\n");
			}
		}
		printf("\n\n");
	}
 	fclose ( archivo );
 	freopen("CONOUT$", "w", stdout);//volvemos a dirigir la salida de datos a la terminal del programa
 	printf("REGISTRO ARCHIVO EXITOSO!!\n");
}
