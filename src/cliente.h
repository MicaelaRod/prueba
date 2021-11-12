/*
 * cliente.h
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


typedef struct{
	int id;
	char nombre[21];
	char sexo;
}eCliente;


/**
 * \brief Le asigna el nombre al id del usuario
 * \param clientes, vector a analizar
 * \param tam, tamañol del vector de clientes
 * \param idCliente. Recibido para comparar
 * \param nombre1. vector para guardar la cadena
 * \return  Retorna 1 si salio bien o 0 si salio mal
 */
int nombreCliente(eCliente clientes[],int tam,int idCliente,char nombre1[]);

int mostrarClientes(eCliente clientes[],int tam);


#endif /* CLIENTE_H_ */
