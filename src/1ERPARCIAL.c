

#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"
#include "datawarehouse.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

#define TAM 15
#define TAMTIPO 5
#define TAMCOLOR 5
#define TAMSERV 3
#define TAMTRAB 10
#define TAMCLI 5


int main(void) {

	setbuf(stdout,NULL);

	char seguir = 's';

	eMascota lista[TAM];

	eTrabajo trabajos[TAMTRAB];

	eTipo tipos[TAMTIPO] = {
			{1000, "Ave"},
			{1001, "Perro"},
			{1002, "Roedor"},
			{1003, "Gato"},
			{1004, "Pez"}
	};

	eColor colores[TAMCOLOR] = {
				{5000, "Negro"},
				{5001, "Blanco"},
				{5002, "Rojo"},
				{5003, "Gris"},
				{5004, "Azul"}
		};

	eServicio servicios[TAMCOLOR] = {
			{20000, "Corte", 850},
			{20001, "Desparacitado", 800},
			{20002, "Castrado", 600},

			};
	//AGREGE ESTO
	eCliente clientes[TAMCLI] = {
				{1, "Juan", 'm'},
				{2, "Pedro", 'm'},
				{3, "Ana", 'f'},
				{4, "Laura", 'f'},
				{5, "Paola", 'f'}

				};


	int nextId =2000;
	int nextIdTrab = 50000;
	int flagAlta =0;


	if(inicializarMascotas(lista,TAM) == 0){ //retorna 0 si algo salio mal

			printf("Error\n");

		}

	if(inicializarTrabajo(trabajos,TAMTRAB) == 0){

				printf("Error\n");

			}

	hardcodearMascotas(lista,TAM,10,&nextId);

	do{

			switch(menu()){

			case 1 :

				altaMascota(lista,TAM,tipos,TAMTIPO,&nextId,colores,TAMCOLOR);

				flagAlta =1;

				break;

			case 2:

				if(flagAlta==1){

				 modificarMascota(lista,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAMCLI);
				}
				else{
					printf("Primero deberia dar el alta de alguna mascota\n");
				}

				break;

			case 3:

				if(flagAlta==1){
				bajaMascotas(lista,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAMCLI);
				}
				else{
				printf("Primero deberia dar el alta de alguna mascota\n");
								}
				break;

			case 4:
				if(flagAlta==1){

				mostrarMascotas(lista,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAMCLI);
				}
				else{
				printf("Primero deberia dar el alta de alguna mascota\n");
				}
				break;

			case 5:
				mostrarTipos(tipos,TAMTIPO);
				break;

			case 6:
				mostrarColores(colores,TAMCOLOR);
				break;

			case 7:
				 mostrarServicios(servicios,TAMSERV);
				break;

			case 8:
				mostrarClientes(clientes,TAMCLI);
				break;

			case 9:
altaTrabajo(trabajos,TAMTRAB,servicios,TAMSERV,lista,TAM,&nextIdTrab,colores,TAMCOLOR,tipos,TAMTIPO,clientes,TAMCLI);
				break;

			case 10:
				mostrarTrabajos(trabajos,TAMTRAB,lista,TAM,servicios,TAMSERV);

				break;
			case 11:
				switch(menuInformes()){
					case 1:
					//muestra mascota seleccionada x el usuario
					mostrarMascotasColor(lista,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAMCLI);

							break;

					case 2:

						// :(
					break;

					case 3:
					//muestra la mascota mas joven, si hay empate, muestra ambas
					mostrarMascotaMasJoven(lista,TAM,colores,TAMCOLOR,tipos,TAMTIPO,clientes,TAMCLI);
					break;

					case 4:
					//muestra todas las mascotas de cada tipo
					mostrarMascotasdeCadatipo(lista,TAM,tipos,TAMTIPO,colores,TAMCOLOR,clientes,TAMCLI);
					break;

					case 5:

					contarMascotasporColorytipo(lista,TAM,colores,TAMCOLOR,tipos,TAMTIPO);
					break;

					case 6:
					//color que mas mascotas tienen
					colorRepetido(lista,TAM,colores,TAMCOLOR);
					break;

				    case 7:
				    mostrarTrabajosdeunaMastcota(trabajos,TAMTRAB,servicios,TAMSERV,lista,TAM,colores,TAMCOLOR,tipos,TAMTIPO,clientes,TAMCLI);
					break;

					default:
					printf("Opcion invalida.\n");
								}

				break;

			case 12:
				printf("Saliste\n");
				seguir='n';
				break;



			default:
				printf("Opcion invalida\n");
			}

	system("pause");


		}while(seguir == 's');






	return EXIT_SUCCESS;
}









