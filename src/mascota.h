
#ifndef MASCOTA_H_
#define MASCOTA_H_

#include "tipo.h"
#include "color.h"
#include "cliente.h"

typedef struct{
	int id;
	char nombre[21];
	int idTipo;
	int idColor;
	int idCliente;
	int edad;
	char vacunado;
	int isEmpty;
}eMascota;

/**
 * \brief Muestra un menu de opciones
 * \param void
 * \return la opcion elegida
 */
int menu();


/**
 * \brief Pone el campo isEmpty en 1
 * \param Mascotas.Array a recorrer
 * \param tam.Tamaño del array
 * \return 1 si toddo sale bien y 0 si sale mal
 */
int inicializarMascotas(eMascota mascotas[],int tam);


/**
 * \brief Busca las estructuras libres(con isEmpty ==1)
 * \param Mascotas. Array a recorrer
 * \param  tam Tamaño del array
 * \return 1 si sale toddo bien y 0 si sale mal
 */
int buscarLibre(eMascota lista[],int tam);


/**
 * \brief Toma los datos de una mascota
 * \param Lista. Vector a llenar
 * \param tam. Tamaño del array mascotas
 * \param tipos. Array de tipos
 * \param  tamTipo. Tamaño del array de tipos
 * \param id. Puntero a entero para incrementar
 * \param colores. Array de colores
 * \param tamColor. Tamaño del vector de colores
 * \return 1 si se pudo dar el alta y 0 si no se pudo
 */
int altaMascota(eMascota lista[],int tam, eTipo tipos[],int tamTipo,int* id,eColor colores[],int tamColor);


/**
 * \brief Muestra los datos de una mascota
 * \param unaMascota variable del tipo eMascota
 * \param tipos. Vector a mostrar
 * \param tam. Tamaño del vector de tipos
 * \param colores. Vector de colores a mostrar
 * \param clientes
 * \param tamCli Tamaño del vector clientes
 * \param tamColor. Tamaño del vector de colores
 * \return void
 */
void mostrarMascota(eMascota unaMascota, eTipo tipos[],int tam, eColor colores[],int tamColor,eCliente clientes[],int tamCli);


/**
 * \brief Muestra los datos de muchas mascotas
 * \param unaMascota variable del tipo eMascota
 * \param tipos. Vector a mostrar
 * \param tamTipos. Tamaño del vector de tipos
 * \param colores. Vector de colores a mostrar
 * \param tamColor. Tamaño del vector de colores
 * \param clientes
 * \param tamCli Tamaño del vector clientes
 * \return 1 si salio toodo bien y 0 si salio todoo mal
 */
int mostrarMascotas(eMascota lista[],int tam, eTipo tipos[],int tamTipo, eColor colores[],int tamColor,eCliente clientes[],int tamCli);


/**
 * \brief
 *\param unaMascota variable del tipo eMascota
 * \param tipos. Vector del tipo eTipos
 * \param tamTipos. Tamaño del vector de tipos
 * \param colores. Vector de colores
 * \param tamColor. Tamaño del vector de colores
 * \param clientes
 * \param tamCli Tamaño del vector clientes
 * \return  1 si salio todoo bien y 0 si salio toodo mal
 */
int bajaMascotas(eMascota lista[],int tam, eTipo tipos[],int tamTipo, eColor colores[],int tamColor,eCliente clientes[],int tamCli);


/**
 * \brief muestra un menu
 * \param void
 * \return la opcion elegida
 */
int menuModificar();


/**
 * \brief modifica el tipo y el color de loa mascota elegida
 *  \param tipos. Vector del tipo eTipos
 * \param tamTipos. Tamaño del vector de tipos
 * \param colores. Vector de colores
 * \param tamColor. Tamaño del vector de colores
 * \param clientes
 * \param tamCli Tamaño del vector clientes
 * \return 1 si salio toodo bien y 0 si salio ttodo mal
 */
int modificarMascota(eMascota lista[],int tam,eTipo tipos[],int tamTipo, eColor colores[],int tamColor,eCliente clientes[],int tamCli);


/**
 * \brief Pone la descripcion del id
 * \param mascotas Array a recorrer
 * \param tam. Tamaño del array mascotas
 * \param idMasc id comparar
 * \param descripcion. String. lo que esta en el campo nombre, se lo copio a descripcion
 * \return 1 si salio toodo bien y 0 si salio toddo mal
 */
int cargarNombre(eMascota mascotas[],int tam,int idMasc,char descripcion[]);


int ordenarMascotas(eMascota mascotas[],int tamMas,eTipo tipos[],int tamT);

//////////////////////////////////////////////////////////////INFORMES//////////////////////////////////////////////////
/**
 * \brief Muestra las mascotas del tipo elegido por el usuario
 *  \param mascotas. Vector del tipo eMascotas
 * \param tamMasc. Tamaño del vector de mascotas
 * \param colores. Vector de colores
 * \param tamColor. Tamaño del vector de colores
 * \param clientes
 * \param tamCli Tamaño del vector clientes
 * \return 1 si salio toodo bien y 0 si salio ttodo mal
 */
int mostrarMascotasTipo(eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli);

int mostrarMascotasIdTipo(int idTipo,eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli);


/**
 * \brief Muestra las mascotas del color elegido por el usuario
 *  \param mascotas. Vector del tipo eMascotas
 * \param tamMasc. Tamaño del vector de mascotas
 * \param colores. Vector de colores
 * \param tamColor. Tamaño del vector de colores
 * \param clientes
 * \param tamCli Tamaño del vector clientes
 * \return 1 si salio toodo bien y 0 si salio ttodo mal
 */
int mostrarMascotasColor(eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli);

int mostrarMascotasIdColor(int idTipo,eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli);


/**
 * \brief muestra un menu
 * \param void
 * \return la opcion elegida
 */
int menuInformes();




int mostrarMascotasdeCadatipo(eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli);


/** \brief muestra la o las mascotas de menor edad
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \param tipos array eTipo
 * \param tamT int
 * \return 0 si salio toodo bien y -1 si no
 *
 */
int mostrarMascotaMasJoven(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,eCliente clientes[],int tamCli);



/** \brief muestra el color mas repetido
 *
 * \param mascotas array eMascota
 * \param tamMas int
 * \param colores array eColor
 * \param tamC int
 * \return 0 si salio todo bien y -1 si no
 *
 */
int colorRepetido(eMascota mascotas[],int tamMas,eColor colores[],int tamC);




int contarMascotasporColorytipo(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT);

#endif /* MASCOTA_H_ */
