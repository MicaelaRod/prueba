
#ifndef COLOR_H_
#define COLOR_H_

typedef struct{
	int id;
	char nombreColor[21];
}eColor;

/**
 * \brief Muestra la lista de colores
 * \param colores. Array a mostrar
 * \param tamaño del array
 *\return Retorna 1 si salio bien o 0 si salio mal
 */
int mostrarColores(eColor colores[],int tam);


/**
 * \brief Le asigna la descripcion al id
 * \param Colores, vector a analizar
 * \param tam, tamañol del vector de colores
 * \param idColor. Recibido para comparar
 * \param descripcion. vector para guardar la cadena
 * \return  Retorna 1 si salio bien o 0 si salio mal
 */
int cargarDescripcionColor(eColor colores[],int tam,int idColor,char descripcion[]);


/** \brief muestra el listado de colores y le pide al usuario que elija uno
 *
 * \param colores Array colores
 * \param tam del array
 * \return int El id ingresado
 *
 */
int getIdColor(eColor colores[],int tam);


#endif /* COLOR_H_ */
