/*
 * tipo.h
 *
 *  Created on: 26 oct. 2021
 *      Author: micar
 */

#ifndef TIPO_H_
#define TIPO_H_


typedef struct{
	int id;
	char descripcion[30];
}eTipo;


/** \brief  Le asigna la descripcion al id
 * \param tipos array eTipo
 * \param tam Tamañoo del array
 * \return 0 si salio mal o 1 si salio bien
 *
 */
int cargarDescripcionTipo(eTipo tipos[],int tam,int idTipo,char descripcion[]);





/** \brief  Muestra los tipos
 * \param tipos array eTipo
 * \param tam Tamañoo del array
 * \return 0 si salio mal o 1 si salio bien
 *
 */
int mostrarTipos(eTipo tipos[],int tam);


/** \brief muestra los tipos y le pide al usuario que elija uno
 * \param tipos array eTipo
 * \param tam Tamañoo del array
 * \return el id ingresado y validado
 *
 */
int getIdTipo(eTipo tipos[],int tam);




#endif /* TIPO_H_ */
