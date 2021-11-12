/*
 * datawarehouse.c
 *
 *  Created on: 26 oct. 2021
 *      Author: micar
 */

#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#include "datawarehouse.h"
#include <string.h>

char nombres[10][20]={
	"Matilda",
	"toby",
	"sara",
	"kiara",
	"michi",
	"india",
	"mufasa",
	"simba",
	"nala",
	"sira"
};

char vacunados [10] = {'s','n','n','n','s','s','s','n','s','n'};


int edades[10]={2,3,2,3,4,5,7,8,15};

int idTipos[10] = {1000,1001,1002,1003,1004,1005,1000,1001,1002,1003};

int idColores [10] = {5000,5001,5002,5003,5004,5005,5000,5001,5002,5003};

int idCliente [10] = {1,2,3,4,5,1,4,5,1,5};

int hardcodearMascotas(eMascota lista[],int tam, int cant,int* pId){

	int contador = -1;

	if(lista != NULL && pId != NULL && tam > 0 && cant >= 0 && cant < tam){

		contador = 0;

		for(int i = 0; i< cant ; i++){
			lista[i].id = *pId;

			(*pId)++;

			strcpy(lista[i].nombre , nombres[i]);
			lista[i].vacunado = vacunados[i];
			lista[i].edad = edades[i];
			lista[i].idTipo = idTipos[i];
			lista[i].idColor = idColores[i];
			lista[i].idCliente = idCliente[i];
			lista[i].isEmpty = 0;
			contador++;
		}//for

	}
	return contador;
}
