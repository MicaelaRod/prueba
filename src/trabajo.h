
#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "fecha.h"
#include "servicio.h"
#include "mascota.h"
#include "color.h"
#include "tipo.h"
#include "utn_validaciones.h"
#include "cliente.h"

typedef struct{
	int id;
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

/**
 * \brief iinicializa isEmpy en 1
 * \param trabajos array a inicilizar
 * \param tam tamaño del array trabajos
 * \return 0 si salio toddo mal y 1 si salio todoo bien
 */
int inicializarTrabajo(eTrabajo trabajos[],int tam);


/**
 * \brief busca una posicion libre en el array
 * \param lista array analizar
 * \param tam tamaño del array
 * \return retorna la posicion libre
 */
int buscarLibreTrabajo(eTrabajo lista[],int tam);




/**
 * \brief Toma los datos para dar un alta
 * \param lista array del tipo eTrabajo
 * \param tam tamaño del array de trabajo
 * \param servicios array del tipo servicios
 * \param tamServ tamaño del array del servicio
 * \param mascotas array del tipo eMascota
 * \param  tamMasc Tamaño del array de mascotas
 * \param idTrabajo puntero a entero para incrementar el id
 * \param colores array del tipo eCOLOR
 * \param tamc Tamaño del array de colores
 * \param tipos array del tipo eTipos
 * \param tamTipo tamaño del array de tipos
 * \param clientes array del tipo eCliente
 * \param tamCli tamaño del array de clientes
 * \return 0 si salio mal y 1 si salio bien
 */
int altaTrabajo(eTrabajo lista[],int tam,eServicio servicios[],int tamServ,eMascota mascotas[],int tamMasc,int* idTrabajo,eColor colores[],int tamC,eTipo tipos[],int tamTipo,eCliente clientes[],int tamCli);




/**
 * \brief muestra 1 trabajo
 * \param un trabajo. variable del tipo eTrabajo
 * \param mascotas array del tipo eMascotas
 * \param tamMas. tamaño del array de mascotas
 * \param servicios array del tipo eServicios
 * \param  tamServ tamaño del array de servicios
 * \return void
 */
void mostrarTrabajo(eTrabajo unTrabajo, eMascota mascotas[],int tamMasc,eServicio servicios[],int tamServ);


/**
 * \brief muestra todos los  trabajos
 * \param lista, array del tipo eTrabajo
 * \param mascotas array del tipo eMascotas
 * \param tamMasc. tamaño del array de mascotas
 * \param servicios array del tipo eServicios
 * \param  tamServ tamaño del array de servicios
 * \return 0 si salio mal y 0 si salio bien
 */
int mostrarTrabajos(eTrabajo lista[],int tam, eMascota mascotas[],int tamMasc, eServicio servicios[],int tamServ);


/**
 * \brief muestra todos los  trabajos que se le hicieron a una mascota en especifico
 * \param trabajos, array del tipo eTrabajo
 * \param mascotas array del tipo eMascotas
 * \param tamMasc. tamaño del array de mascotas
 * \param servicios array del tipo eServicios
 * \param  tamServ tamaño del array de servicios
 * \param  clientes . array del tipo eCliente
 * \param  tamCli. tamaño del array de clientes
 * \return 0 si salio mal y 0 si salio bien
 */
int mostrarTrabajosdeunaMastcota(eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamS,eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,eCliente clientes[],int tamCli);



#endif /* TRABAJO_H_ */
