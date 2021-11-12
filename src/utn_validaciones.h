
#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"

/**
 * \brief valida la edad
 * \param edad a validar
 * \return 1 si salio bien o 0 si salio mal
 */
int validarEdad(int edad);


/**
 * \brief valida la vacuna
 * \param vacunado. char a validar
 * \return 1 si salio bien o 0 si salio mal
 */
int validarVacuna(char vacunado);



/** \brief Busca el id pasado por parametro
 *
 * \param tipos el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 1 si se encontro el id,sino 0
 *
 */
int validarIdTipo(int id, eTipo tipos[],int tam);



/** \brief Busca el id pasado por parametro
 *
 * \param colores el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 1 si se encontro el id,sino 0
 *
 */
int validarIdColor(int id, eColor colores[],int tam);




/** \brief Busca el id pasado por parametro
 *
 * \param mascotas el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 1 si se encontro el id,sino 0
 *
 */
int validarIdMascota(int id, eMascota mascotas[],int tam);




/** \brief Busca el id pasado por parametro
 *
 * \param servicios el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 1 si se encontro el id,sino 0
 *
 */
int validarIdServicio(int id, eServicio servicios[],int tam);


#endif /* UTN_VALIDACIONES_H_ */
