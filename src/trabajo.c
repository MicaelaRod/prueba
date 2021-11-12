/*
 * trabajo.c
 *
 *  Created on: 27 oct. 2021
 *      Author: micar
 */
#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "fecha.h"
#include "servicio.h"
#include "mascota.h"
#include "color.h"
#include "tipo.h"
#include "utn_validaciones.h"
#include "cliente.h"

int inicializarTrabajo(eTrabajo trabajos[],int tam){

	int todoOk=0;

	if(trabajos!=NULL && tam>0){

	for(int i=0;i<tam;i++){

		trabajos[i].isEmpty = 1;//VACIO

	}//for

	todoOk=1;
	}

	return todoOk;
}
int buscarLibreTrabajo(eTrabajo lista[],int tam){
	int libre = -1;

	if(lista!=NULL && tam > 0 ){

		for(int i=0; i<tam ; i++){

		if(lista[i].isEmpty == 1){

		libre = i;
		break;//para que en el primero que encuentre, corta el for y devuelvo ese indice de una

			}
			}//for
			}

	return libre;
}

int altaTrabajo(eTrabajo lista[],int tam,eServicio servicios[],int tamServ,eMascota mascotas[],int tamMasc,int* idTrabajo,eColor colores[],int tamC,eTipo tipos[],int tamTipo,eCliente clientes[],int tamCli){

	int todoOk =0;
	eTrabajo aux; //creo un buffer para guardar los datos y validarlos, cuando lo esten, ahi se los paso al indice
	int indice;



	if(lista != NULL && tam > 0 && idTrabajo != NULL && servicios != NULL && tamServ > 0 && mascotas != NULL && tamMasc > 0 &&clientes != NULL && tamCli >0){

		system("cls");

	printf("\n~~~~~~~~~~~~~~~~~~~~~ALTA TRABAJO~~~~~~~~~~~~~~~~~~~~~~\n\n");

		indice = buscarLibreTrabajo(lista,tam); //buscar libre retorna -1 si no hay lugar, y si hay, retorna ese indice

		if(indice == -1){
			printf("No hay lugar!!!\n");
		}
		else{

			aux.id = *idTrabajo;

			(*idTrabajo)++;


			mostrarServicios(servicios,tamServ);
			printf("Ingrese id del Servicio\n");
			scanf("%d",&aux.idServicio);


			while(validarIdServicio(aux.idServicio,servicios,tamServ)==0){//entro al while cuando sea invalido
					printf("ERROR.Ingrese id Servicio\n");
					scanf("%d",&aux.idServicio);
			}


			mostrarMascotas(mascotas,tamMasc, tipos,tamTipo,colores,tamC,clientes,tamCli);
			printf("Ingrese id de la mascota\n");
			scanf("%d",&aux.idMascota);


			while(validarIdMascota(aux.idMascota,mascotas,tamMasc)==0){//entro al while cuando sea invalido
					printf("ERROR.Ingrese id Mascota\n");
					scanf("%d",&aux.idMascota);
						}

			printf("Ingrese fecha\n");
			scanf("%d/%d/%d",&aux.fecha.dia,&aux.fecha.mes,&aux.fecha.anio);



			aux.isEmpty = 0; //lo acabe de llenar, entonces cambio el valor

			lista[indice] = aux;//el indice libre que medio buscarLibre

			printf("Alta exitosa!! Gracias\n");


			todoOk=1;

		}//else


	}
	return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eMascota mascotas[],int tamMasc,eServicio servicios[],int tamServ){

	char descMasc[21];
	char descServ[21];

	if(cargarNombre(mascotas,tamMasc,unTrabajo.idMascota,descMasc)==1 &&
			cargarDescripcionServicio(servicios,tamServ,unTrabajo.idServicio,descServ)==1){

	printf(" id      Mascota     Servicio    Fecha  Dueno de la masc\n");

	printf("%d    %-10s  %s     %2d/%2d/%d  \n",
									unTrabajo.id,
									descMasc,
									descServ,
									unTrabajo.fecha.dia,
									unTrabajo.fecha.mes,
									unTrabajo.fecha.anio


								  );
	}
}


int mostrarTrabajos(eTrabajo lista[],int tam, eMascota mascotas[],int tamMasc, eServicio servicios[],int tamServ){
	int todoOk = 0;

	int flag = 1; //para ver si hay masco

		if(lista != NULL && tam > 0 && mascotas!=NULL && tamMasc > 0 && servicios !=NULL && tamServ >0){
			system("cls");

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lista de Trabajos~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


		for(int i = 0 ; i<tam ; i++){

			if(lista[i].isEmpty == 0){//muestro solo si esta llena!!

				mostrarTrabajo(lista[i], mascotas, tamMasc,servicios,tamServ); //muestro los datos de esa estructura
				flag = 0;
			}

		}//for

		if(flag==1){//significa que nunca puse un trabajp
			printf("No hay trabajos para mostrar\n");
		}
		todoOk = 1;
		}
		return todoOk;
}
/////////////////////////////INFORMES///////////////////////////////////////////////////////
int mostrarTrabajosdeunaMastcota(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,eCliente clientes[],int tamCli)
{
    int todoOk=-1;
    int aux;
    int flag=0;

    if(trabajos!=NULL && tamTra>0 && servicios!=NULL && tamS>0&&mascotas!=NULL && tamMas>0 && clientes != NULL && tamCli >0)
    {
        system("cls");
        printf("   Trabajos en una mascota\n\n");
        mostrarMascotas(mascotas,tamMas,tipos,tamT,colores,tamC,clientes,tamCli);

        printf("Ingrese id de mascota\n");
        scanf("%d",&aux);


        if(validarIdMascota(aux,mascotas,tamMas)==1){


        printf("\n\n");
        printf(" ID      MASCOTA MASCOTA(ID)  SERVICIO   FECHA\n");
        for(int i=0;i<tamMas;i++)
        {
            if(trabajos[i].idMascota==aux&&trabajos[i].isEmpty==0)
            {
            	mostrarTrabajos(trabajos,tamT,mascotas,tamMas,servicios,tamS);
                flag=1;
            }
        }

        if(flag == 0)
        {
            printf("No se realizo ningun trabajo con esta mascota\n\n");
        }

        todoOk=0;
    }
    }
    else{
    	printf("No hay mascota con ese id\n");
    }

    return todoOk;
}
