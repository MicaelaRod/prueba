

#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nombreCliente(eCliente clientes[],int tam,int idCliente,char nombre1[]){
	int todoOk = 0;
		int flag = 1;

		if(clientes != NULL && nombre1 != NULL && tam > 0){
			todoOk = 1;

			for(int i=0;i<tam;i++){

			if(clientes[i].id == idCliente){

				strcpy(nombre1, clientes[i].nombre);
				flag = 0;
				break;
			}
			}

	if(flag ==1){//significa qque nunca entre y no pudo encontrar
		flag = -1;
	       }
		}
		return todoOk;
}


int mostrarClientes(eCliente clientes[],int tam){
	int todoOk=0;
	if(clientes != NULL && tam > 0){

		printf("---Lista de Clientes:\n\n");

		printf("Id  Nombre  Sexo \n");

		for(int i=0; i< tam; i++){

			printf("%d  %-10s  %c\n",clientes[i].id , clientes[i].nombre , clientes[i].sexo);

		}//for


		todoOk=1;
	}
	return todoOk;
}

