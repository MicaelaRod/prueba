

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_
#include "mascota.h"


/** \brief Harcodea las mascotas
 *
 * \param lista. array a hardcodear
 * \param tam Tamanio del array
 * \param pId puntero a entero del id
 * \param cant. cantidad de mascotas a hardcodear
 * \return -1 si no se pudo y si se pudo, retorna las veces que harcodeo
 *
 */
int hardcodearMascotas(eMascota lista[],int tam, int cant,int* pId);

#endif /* DATAWAREHOUSE_H_ */
