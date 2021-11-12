
#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#include "utn_validaciones.h"
#include <string.h>
#include "cliente.h"

int menu(){
	int opcion;
	system("cls");

	printf("~~~~~~ABM<3~~~~~~~\n\n");

printf("1. Alta mascota\n");
printf("2. Modificar mascota\n");
printf("3. Baja mascota\n");
printf("4. Listar mascotas\n");
printf("5. Listar tipos\n");
printf("6. Listar colores\n");
printf("7. Listar servicios\n");
printf("8. Listar clientes\n");
printf("9. Alta trabajo\n");
printf("10. Listar trrabajos\n");
printf("11. Informes\n");
printf("12. Salir\n");

printf("Ingrese opcion:\n");

scanf("%d",&opcion);

return opcion;
}


int inicializarMascotas(eMascota mascotas[],int tam){

	int todoOk=0;

	if(mascotas!=NULL && tam>0){

	for(int i=0;i<tam;i++){

		mascotas[i].isEmpty = 1;//VACIO

	}//for

	todoOk=1;
	}

	return todoOk;
}

int buscarLibre(eMascota lista[],int tam){
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
int altaMascota(eMascota lista[],int tam, eTipo tipos[],int tamTipo,int* id,eColor colores[],int tamColor){
	int todoOk =0;
	eMascota aux; //creo un buffer para guardar los datos y validarlos, cuando lo esten, ahi se los paso al indice
	int indice;



	if(lista != NULL && tam > 0 && id !=NULL&& tipos != NULL && tamTipo > 0 && colores != NULL && tamColor >0 ){

		system("cls");

	printf("\n~~~~~~~~~~~~~~~~~~~~~ALTA MASCOTA~~~~~~~~~~~~~~~~~~~~~~\n\n");

		indice = buscarLibre(lista,tam); //buscar libre retorna -1 si no hay lugar, y si hay, retorna ese indice

		if(indice == -1){
			printf("No hay lugar!!!\n");
		}
		else{

			aux.id = *id;

			(*id)++;



			printf("Ingrese su nombre\n");
			fflush(stdin);
			gets(aux.nombre);


			while(strlen(aux.nombre)> 20){
				printf("El nombre de la mascota es demasiado largo\n");
				fflush(stdin);
				gets(aux.nombre);
			}


			printf("Ingrese la edad\n");
			scanf("%d",&aux.edad);


			while(validarEdad(aux.edad)==0){
				printf("ERROR.Ingrese la edad\n");
				scanf("%d",&aux.edad);
			}

			printf("Esta vacunado? s o n");
			fflush(stdin);
			scanf("%c",&aux.vacunado);

			while(validarVacuna(aux.vacunado)==0){
				printf("ERROR.Esta vacunado? s o n");
				fflush(stdin);
				scanf("%c",&aux.vacunado);

			}


			mostrarTipos(tipos,tamTipo);
			printf("Ingrese id del Tipo\n");
			scanf("%d",&aux.idTipo);


			while(validarIdTipo(aux.idTipo,tipos,tam)==0){//entro al while cuando sea invalido
							printf("ERROR.Ingrese id tipo\n");
							scanf("%d",&aux.idTipo);
			}

			mostrarColores(colores,tamColor);
			printf("Ingrese id del Color");
			scanf("%d",&aux.idColor);

			while(validarIdColor(aux.idColor, colores,tam)==0){
				printf("ERROR.Ingrese id color\n");
					scanf("%d",&aux.idColor);


			};




			aux.isEmpty = 0; //lo acabe de llenar, entonces cambio el valor

			lista[indice] = aux;//el indice libre que medio buscarLibre

			printf("Alta exitosa!! Gracias\n");


			todoOk=1;

		}//else


	}
	return todoOk;
}

void mostrarMascota(eMascota unaMascota, eTipo tipos[],int tam,eColor colores[],int tamColor,eCliente clientes[],int tamCli){

	char descTipo[21];
	char descColor[21];
	char nombreClientes[21];

	if(cargarDescripcionTipo(tipos,tam,unaMascota.idTipo,descTipo)==1
			&& cargarDescripcionColor(colores,tamColor,unaMascota.idColor,descColor)==1
			&& nombreCliente(clientes,tamCli,unaMascota.idCliente,nombreClientes)){

	printf(" id      nombre     Tipo    Color  edad   vacunado  Nombre del dueño\n");

	printf("%d    %-10s  %s     %s   %d     %c        %s\n",
									unaMascota.id,
									unaMascota.nombre,
									descTipo,
									descColor,
							        unaMascota.edad,
									unaMascota.vacunado,
									nombreClientes

								  );
	}
}


int mostrarMascotas(eMascota lista[],int tam, eTipo tipos[],int tamTipo, eColor colores[],int tamColor,eCliente clientes[],int tamCli){
	int todoOk = 0;

	int flag = 1; //para ver si hay masco

		if(lista != NULL && tam > 0 && tipos != NULL && colores != NULL && clientes != NULL && tamTipo >0 && tamCli){
			system("cls");

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~Lista de Mascotas~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	 ordenarMascotas(lista,tam,tipos, tamTipo);


		for(int i = 0 ; i<tam ; i++){

			if(lista[i].isEmpty == 0){//muestro solo si esta llena!!

				mostrarMascota(lista[i],tipos,tamTipo,colores,tamColor,clientes,tamCli); //muestro los datos de esa estructura
				flag = 0;
			}

		}//for

		if(flag==1){//significa que nunca puse una persona
			printf("No hay mascotas para mostrar\n");
		}
		todoOk = 1;
		}
		return todoOk;
}


int ordenarMascotas(eMascota mascotas[],int tamMas,eTipo tipos[],int tamT){
    int todoOk=-1;
    char tipoI[20];
    char tipoJ[20];
    eMascota aux;

    if(mascotas!=NULL && tamMas>0 && tipos!=NULL && tamT>0)
    {
        for(int i=0;i<tamMas-1;i++)
        {
            for(int j=i+1;j<tamMas;j++)
            {
                if(mascotas[i].isEmpty==0 && mascotas[j].isEmpty==0)
                {
                	cargarDescripcionTipo(tipos,tamT,mascotas[i].idTipo,tipoI);

                	cargarDescripcionTipo(tipos,tamT,mascotas[j].idTipo,tipoJ);

                    if(stricmp(tipoI,tipoJ)>0)
                    {
                        aux=mascotas[i];
                        mascotas[i]=mascotas[j];
                        mascotas[j]=aux;
                    }else if(stricmp(tipoI,tipoJ)==0&&stricmp(mascotas[i].nombre,mascotas[j].nombre)>0)
                    {
                        aux=mascotas[i];
                        mascotas[i]=mascotas[j];
                        mascotas[j]=aux;
                    }
                }
            }
        }

        todoOk=0;
    }
    return todoOk;
}


//retorna -1 si no encontro a nadie con ese id, y retorna el indice si si la enconro
int buscarId(eMascota lista[],int tam,int id){ //recorre las esctu hasta llegar a la que tenga el mismo indice

	int indice = -1;

	if(lista != NULL && tam > 0){

		for(int i=0;i<tam;i++){//recorro las estructuras para ver quien tiene ese id

			if(id == lista[i].id && lista[i].isEmpty ==0){ //tiene que coincidir el id y tiene que estar cargada la struc
				indice=i; //pongo para retornar el indice
				break;
			}

		}//for

	}
	return indice;
}

int bajaMascotas(eMascota lista[],int tam, eTipo tipos[],int tamTipo, eColor colores[],int tamColor,eCliente clientes[],int tamCli){

	int todoOk = 0;
	int id;
	int indice;
	char confirma;

	if(lista!=NULL &&tam > 0 && tipos != NULL && tamTipo > 0 && colores != NULL && tamColor >0 && clientes != NULL && tamCli > 0){

		printf("Baja mascota\n");
		printf("Ingrese el id de la mascota a hacer la baja\n");
		mostrarMascotas(lista,tam, tipos,tamTipo,colores,tamColor,clientes,tamCli);

		scanf("%d",&id); //lo que ingresa la persona lo guardo aca para despues comparar

		indice = buscarId(lista,tam,id); //lo que me de esta funcion, se lo asigno a indice para trabajar con esa variab



		if(indice == -1){//si retorna -1 es xq no se encontro
			printf("No existe una mascota con ese id\n");
		}
		else{

			mostrarMascota(lista[indice],tipos,tamTipo,colores,tamColor,clientes,tamCli);//porque retorna el INDICE de la struct que tiene ese id

			printf("Confirma baja?\n");
			fflush(stdin);
			scanf("%c",&confirma);

			if(confirma == 's'){
				lista[indice].isEmpty = 1; //SI CONFIRMA LA BAJA, VUELVOA PONER COMO VACIA LA ESTRUCTURA

				printf("Baja existosa, gracias\n");

				todoOk = 1;
			}
			else{
				printf("Baja cancelada\n");
			}
		}
		todoOk=1;
	}
return todoOk;
}

int menuModificar(){

	int opcion;
		system("cls");


	printf("1. Tipo\n");
	printf("2. Vacuna\n");



	printf("Que campo desea modificar\n\n");

	scanf("%d",&opcion);

	return opcion;

}


int modificarMascota(eMascota lista[],int tam,eTipo tipos[],int tamTipo, eColor colores[],int tamColor,eCliente clientes[],int tamCli){

	int todoOk = 0;
	int indice;
	int id;
	char confirma;

	if(lista != NULL && tam > 0 && tipos != NULL && tamTipo > 0 && colores != NULL && tamColor >0 && clientes != NULL && tamCli > 0){

		printf("Ingrese id de la mascota a modificar\n");
		mostrarMascotas(lista,tam, tipos,tamTipo,colores,tamColor,clientes,tamCli);
		scanf("%d",&id);

		indice = buscarId(lista,tam,id);

		if(indice == -1){
			printf("No hay una mascota con ese id\n");
		}
		else{

			mostrarMascota(lista[indice],tipos,tamTipo,colores,tamColor,clientes,tamCli);

printf("Confirma modificar?\n");
fflush(stdin);
scanf("%c",&confirma);
if(confirma == 's'){
			 switch(menuModificar()){

			 case 1:
				 printf("Ingrese el id del tipo a modificar\n");
				 mostrarTipos(tipos,tamTipo);
				 fflush(stdin);
				 scanf("%d",&lista[indice].idTipo);
				 //deberia hacer validacion
				 break;

			 case 2:
				 printf("Ingrese si esta vacunado o no\n");
				 fflush(stdin);
				 scanf("%c",&lista[indice].vacunado);
				 //deberia hacer validacion
				 break;

default:

	printf("Opcion invalida\n");


			 }//switch
				 printf("Cambio hecho\n");
				 todoOk = 1;
}//confirma
else{
	printf("Modificacion cancelada\n");
			}
		}
	}
	return todoOk;
}


int cargarNombre(eMascota mascotas[],int tam,int idMasc,char descripcion[]){
	int todoOk = 0;
	int flag = 1;

	if(mascotas != NULL && descripcion != NULL && tam > 0){
		todoOk = 1;

		for(int i=0;i<tam;i++){

		if(mascotas[i].id == idMasc){

			strcpy(descripcion, mascotas[i].nombre);
			flag = 0;
			break;
		}
		}

if(flag ==1){//significa qque nunca entre y no pudo encontrar
	flag = -1;
}

	}


	return todoOk;
}


int menuInformes(){
	int opcion;
	system("cls");

	printf("Informes:\n\n");

printf("1. - Mostrar las mascotas del color elegido.\n"); //X
printf("2. - Promedio de mascotas vacunadas sobre el total de mascotas.\n");
printf("3. - La o las mascotas de menor edad.\n"); //X
printf("4. - Lista de las mascotas separadas por tipo.\n"); //X
printf("5. - Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.\n");
printf("6. - El o los colores con más cantidad de mascotas.\n");
printf("7. - Mostrar todos los trabajos que se le hicieron a una mascota.\n");


printf("Ingrese opcion:\n");

scanf("%d",&opcion);

return opcion;
}




//////////////////////////////////////////INFORMES//////////////////////////////////////////////////////////////////////

//muestra las mascotas del tipo elegido por el usuario


int mostrarMascotasTipo(eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli){

	int todoOk =0;
	int idTipo;



	printf("Listado de mascotas por TIPO ingresado:\n");

	if(mascotas != NULL && tipos != NULL && tamMasc>0 && tamTipo >0 &&colores != NULL && clientes != NULL &&tamColor > 0 && tamCli >0){
//pido
					idTipo=getIdTipo(tipos,tamTipo);//pide el id del tipo
//muestro
					mostrarMascotasIdTipo(idTipo,mascotas, tamMasc, tipos,tamTipo, colores, tamColor, clientes, tamCli);
		todoOk = 1;
	}
return todoOk;
}

int mostrarMascotasIdTipo(int idTipo,eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli){

	int todoOk = 0;
	int flag=0;

	if(mascotas != NULL && tipos != NULL && tamMasc>0 && tamTipo >0 &&colores != NULL && clientes != NULL &&tamColor > 0 && tamCli >0){

		for(int i=0; i< tamTipo;i++){
			//si el id recibido por parametro es igual a algun idTipo de la estructura, muesto la mascota de ese indice
			if(idTipo == mascotas[i].idTipo && mascotas[i].isEmpty ==0){
			mostrarMascota(mascotas[i],tipos,tamTipo,colores,tamColor,clientes,tamCli);
				flag=1;
		}

		}
		if(flag==0){//significa que no entre, osea que no se encontro
								printf("No se encontro una mascota de ese tipo \n");
							}

		todoOk =1;
	}
	return todoOk;
}


int mostrarMascotasIdColor(int idColor,eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli){

	int todoOk = 0;
	int flag=0;

	if(mascotas != NULL && tipos != NULL && tamMasc>0 && tamTipo >0 &&colores != NULL && clientes != NULL &&tamColor > 0 && tamCli >0){

		for(int i=0; i< tamTipo;i++){
			//si el id recibido por parametro es igual a algun idTipo de la estructura, muesto la mascota de ese indice
			if(idColor == mascotas[i].idColor && mascotas[i].isEmpty ==0){
			mostrarMascota(mascotas[i],tipos,tamTipo,colores,tamColor,clientes,tamCli);
				flag=1;
		}

		}

		if(flag==0){//significa que no entre, osea que no se encontro
								printf("No se encontro una mascota de ese color \n");
							}

		todoOk =1;
	}
	return todoOk;
}

int mostrarMascotasColor(eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli){

	int todoOk =0;
	int idColor;



	printf("Listado de mascotas por COLOR ingresado:\n");

	if(mascotas != NULL && tipos != NULL && tamMasc>0 && tamTipo >0 &&colores != NULL && clientes != NULL &&tamColor > 0 && tamCli >0){
//pido
					idColor=getIdColor(colores,tamColor); //pide id color
//muestro
					mostrarMascotasIdColor(idColor,mascotas, tamMasc, tipos,tamTipo, colores, tamColor, clientes, tamCli);
		todoOk = 1;
	}
return todoOk;
}


//muestra las mascotas de todos los tipos por tipo ROEDOR: ----- AVE -----
int mostrarMascotasdeCadatipo(eMascota mascotas[], int tamMasc, eTipo tipos[],int tamTipo,eColor colores[],int tamColor,eCliente clientes[],int tamCli){
int todoOk=0;



if(mascotas != NULL && tipos != NULL && tamMasc>0 && tamTipo >0 &&colores != NULL && clientes != NULL &&tamColor > 0 && tamCli >0){

		printf("Listado de mascotas de cada tipo:\n");

		//recorro el array de tipos para ir obteniendo en cada iteracion el id del tipo
		for(int i=0;i<tamTipo;i++){

			printf("Tipo: %s \n",tipos[i].descripcion); //muestro el nombre del tipo

			mostrarMascotasIdTipo(tipos[i].id,mascotas, tamMasc, tipos,tamTipo, colores, tamColor, clientes, tamCli);
printf("\n\n-------------------\n");
		}
		todoOk =1;
	}
return todoOk;
}



int mostrarMascotaMasJoven(eMascota mascotas[],int tamMas,eColor colores[],int tamC,eTipo tipos[],int tamT,eCliente clientes[],int tamCli)
{
    int todoOk=-1;
    int minimoEdad;//guardo el minimo de edad

    if(mascotas!=NULL && tamMas>0 && colores != NULL && tamC>0 && tipos != NULL && tamT>0)
    {

        printf("   MASCOTA(S) MAS JOVEN(ES)\n\n");
        for(int i=0;i<tamMas;i++)
        {
            if((i==0||mascotas[i].edad<minimoEdad)&&mascotas[i].isEmpty==0)
            {
                minimoEdad=mascotas[i].edad;
            }
        }

        printf("Mascota(s) mas joven(es):\n\n");

        for(int i=0;i<tamMas;i++)
        {
            if((mascotas[i].edad==minimoEdad)&&mascotas[i].isEmpty==0)
            {
                mostrarMascota(mascotas[i],tipos,tamT,colores,tamC,clientes,tamCli);
                todoOk=0;
            }
        }
    }

    return todoOk;
}


int colorRepetido(eMascota mascotas[],int tamMas,eColor colores[],int tamC)
{
    int todoOk=-1;
    int cont[tamC];
    int colorElegido;

    if(mascotas!=NULL && tamMas>0 && colores!=NULL && tamC>0)
    {

        printf("    Color con mas cantidad de mascotas:\n\n");

        for(int c=0;c<tamC;c++)
        {
            cont[c]=0;
            for(int m=0;m<tamMas;m++)
            {
                if(mascotas[m].idColor==colores[c].id&&mascotas[m].isEmpty==0)
                {
                    cont[c]++;
                }
            }
        }

        for(int c=0;c<tamC;c++)
        {
            if(c==0||cont[c]>colorElegido)
            {
            	colorElegido=cont[c];
            }
        }

        printf("Color(es) mas elegido(s):\n");

        for(int c=0;c<tamC;c++)
        {
            if(cont[c]==colorElegido)
            {
                printf("-%s\n",colores[c].nombreColor);
            }
        }

        todoOk=0;
    }

    return todoOk;
}



int contarMascotasporColorytipo(eMascota mascotas[],int tamMasc,eColor colores[],int tamC,eTipo tipos[],int tamT)
{
    int todoOk=-1;

    int auxColor;

    int auxTipo;

    int cont=0;

    if(mascotas!=NULL && tamMasc>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamT>0)
    {

       todoOk =1;
        printf("   Mascotas de un color y un tipo:\n\n");

        auxColor=getIdColor(colores,tamC);//pido y valido id color

        auxTipo=getIdTipo(tipos,tamT);//pido y valido id de tipo

        for(int i=0;i<tamMasc;i++)
        {
            if(mascotas[i].idColor==auxColor && mascotas[i].idTipo==auxTipo && mascotas[i].isEmpty==0)
            {
                cont++;

            }
        }

        if(cont ==0)
        {
            printf("\nNo hay mascotas de ese tipo y color\n\n");
        }else if(cont==1)
        {
            printf("\nHay una mascota con ese color y tipo\n\n");
        }else
        {
            printf("\nCantidad de mascotas de este color y tipo:%d\n\n",cont);
        }
    }

    return todoOk;
}



