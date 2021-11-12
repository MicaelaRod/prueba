/*
 * utn_validaciones.c
 *
 *  Created on: 28 oct. 2021
 *      Author: micar
 */


#include "utn_validaciones.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int validarEdad(int edad){
	int todoOk =0;

	if(edad > 0 && edad < 20){
		todoOk =1;
	}

	return todoOk;
}

int validarVacuna(char vacunado){
	int todoOk =0;

	if(vacunado == 's' || vacunado == 'n' || vacunado == 'S' || vacunado == 'N' ){
		todoOk=1;
	}


	return todoOk;
}


int validarIdTipo(int id, eTipo tipos[],int tam){
	int todoOk=0;

	if(tipos != NULL && tam >0){

		for(int i=0;i<tam;i++){
			if(tipos[i].id == id){

			todoOk = 1;
			}
		}
	}

	return todoOk;
}


int validarIdColor(int id, eColor colores[],int tam){
	int todoOk=0;

	if(colores != NULL && tam >0){

		for(int i=0;i<tam;i++){
			if(colores[i].id == id){

			todoOk = 1;
			}
		}
	}

	return todoOk;
}

int validarIdMascota(int id, eMascota mascotas[],int tam){
	int todoOk=0;

	if(mascotas != NULL && tam >0){

		for(int i=0;i<tam;i++){
			if(mascotas[i].id == id){

			todoOk = 1;
			}
		}
	}

	return todoOk;
}

int validarIdServicio(int id, eServicio servicios[],int tam){
	int todoOk=0;

	if(servicios != NULL && tam >0){

		for(int i=0;i<tam;i++){
			if(servicios[i].id == id){

			todoOk = 1;


			}
		}

	}

	return todoOk;
}




