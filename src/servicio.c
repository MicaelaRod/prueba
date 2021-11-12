
#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mostrarServicios(eServicio servicios[],int tam){
	int todoOk=0;
	if(servicios != NULL && tam > 0){

		printf("---Lista de Servicios:\n\n");

		printf("Id  Descripcion  Precio \n");

		for(int i=0; i< tam; i++){

			printf("%d  %-10s  %d\n",servicios[i].id , servicios[i].descripcion , servicios[i].precio);

		}//for


		todoOk=1;
	}
	return todoOk;
}


int cargarDescripcionServicio(eServicio servicios[],int tam,int idServ,char descripcion[]){
	int todoOk = 0;
	int flag = 1;

	if(servicios != NULL && descripcion != NULL && tam > 0){
		todoOk = 1;

		for(int i=0;i<tam;i++){

		if(servicios[i].id == idServ){

			strcpy(descripcion, servicios[i].descripcion);
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

