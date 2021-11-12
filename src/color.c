#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "utn_validaciones.h"


int mostrarColores(eColor colores[],int tam){
	int todoOk=0;
	if(colores != NULL && tam > 0){

		printf("---Lista de colores:\n\n");

		printf("Id  Descripcion\n");

		for(int i=0; i< tam; i++){

			printf("%d  %-10s\n",colores[i].id,colores[i].nombreColor);

		}//for


		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionColor(eColor colores[],int tam,int idColor,char descripcion[]){
	int todoOk = 0;
		int flag = 1;

		if(colores != NULL && descripcion != NULL && tam > 0){
			todoOk = 1;

			for(int i=0;i<tam;i++){

			if(colores[i].id == idColor){

				strcpy(descripcion, colores[i].nombreColor);
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

int getIdColor(eColor colores[],int tam){

	int id;

	mostrarColores(colores, tam);

	    printf("______________________\n");
	    printf("Ingrese el id del color de la mascota\n");
	    scanf("%d",&id);
	    while(validarIdColor(id,colores,tam)==-1)//valido que se ingrese un tipo existente
	    {
	        printf("Ingrese un Id valido\n");
	        scanf("%d",&id);
	    }
	    printf("\n");

	    return id;
}
