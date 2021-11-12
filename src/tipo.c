/*
 * tipo.c
 *
 *  Created on: 26 oct. 2021
 *      Author: micar
 */

#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"
#include "tipo.h"
#include <string.h>
#include "utn_validaciones.h"

int cargarDescripcionTipo(eTipo tipos[],int tam,int idTipo,char descripcion[]){
	int todoOk = 0;
	int flag = 1;

	if(tipos != NULL && descripcion != NULL && tam > 0){
		todoOk = 1;

		for(int i=0;i<tam;i++){

		if(tipos[i].id == idTipo){

			strcpy(descripcion, tipos[i].descripcion);
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

int mostrarTipos(eTipo tipos[],int tam){
	int todoOk=0;
	if(tipos != NULL && tam > 0){

		printf("---Lista de tipos:\n\n");

		printf("Id  Descripcion\n");

		for(int i=0; i< tam; i++){



			printf("%d  %-10s\n",tipos[i].id,tipos[i].descripcion);

		}//for


		todoOk=1;
	}
	return todoOk;
}

int getIdTipo(eTipo tipos[],int tam){

	int id;

	mostrarTipos(tipos,tam);
	    printf("______________________\n");
	    printf("Ingrese el id de tipo de la mascota\n");
	    scanf("%d",&id);
	    while(validarIdTipo(id,tipos,tam)==-1)//valido que se ingrese un tipo existente
	    {
	        printf("Ingrese un Id valido\n");
	        scanf("%d",&id);
	    }
	    printf("\n");

	    return id;
}



