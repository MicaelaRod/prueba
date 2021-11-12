
#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id;
	char descripcion[21];
	int precio;
}eServicio;

/**
 * \brief muestra los servicios
 * \param servicios array eServicio
 * \param tam tamaño del array servicios

 * \return 1 si salio bien y 0 si salio mal
 */
int mostrarServicios(eServicio servicios[],int tam);



/**
 * \brief Le asigna la descripcion al id
 * \param servicios, vector a analizar del tipo eSericio
 * \param tam, tamañol del vector de colores
 * \param idServ. Recibido para comparar
 * \param descripcion. vector para guardar la cadena
 * \return  Retorna 1 si salio bien o 0 si salio mal
 */
int cargarDescripcionServicio(eServicio servicios[],int tam,int idServ,char descripcion[]);

#endif /* SERVICIO_H_ */
