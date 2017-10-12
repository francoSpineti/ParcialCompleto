#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "validar.h"

// ****************** FUNCIONES ESTATICAS ***********************************

static int idAutoincrementable = 0;
static int pantalla_generarIDAutoincrementable(Pantalla* arrayPantalla,int longitud);
static int pantalla_buscarPosicionLibre(Pantalla* arrayPantalla,int longitud);

/** \brief genera un Id que se va incrementando de a 1.
 *
 * @param longitud
 * @param arrayPantalla
 * @return retorna el id +1.
 */
static int pantalla_generarIDAutoincrementable(Pantalla* arrayPantalla,int longitud)
{
    idAutoincrementable++;
    return idAutoincrementable;
}

/** \brief me devuelve el index del primer item vacio de la array, la voy a usar para el alta, me retorna la posicion del array, si esta todo ocupado devuelve -1, si hay una posicion libre devuelve i.
 *
 * \param
 * \param longitud
 * \return
 *
 */
static int pantalla_buscarPosicionLibre(Pantalla* arrayPantalla,int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantalla != NULL && longitud > 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayPantalla[i].flag == PANTALLA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

// **********************************************************     FIN FUNCIONES ESTATICAS    *******************************************************************************************

/** \brief funcion que retorna el indice del array por el ID, verifica si EXISTE O NO el indice.
 *
 * @param arrayPantalla
 * @param longitud
 * @param id
 * @return retorna el indice del array
 */
int pantalla_buscarIndicePorId(Pantalla* arrayPantalla,int longitud,int id)
{
    int i;
    int retorno = -1;
    if(arrayPantalla != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayPantalla[i].flag == PANTALLA_OCUPADA)
            {
                if(id == arrayPantalla[i].idPantalla)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief  inicializamos el array, que todos los flags esten libres
 *
 * \param longitud - tamaño/longitud del  array
 * \param arrayPantalla
 * \return 0 = ok
 */
int pantalla_inicializarArray(Pantalla* arrayPantalla,int longitud)
{
    int i;
    for(i=0;i < longitud;i++)
    {
        arrayPantalla[i].flag = PANTALLA_LIBRE;
    }
    return 0;
}

/** \brief damos de alta una nueva pantalla
 *
 * @param longitud - longitud del array
 * @param arrayPantalla
 * @return 0 ok / -1 error
 */
int pantalla_altaPantalla(Pantalla* arrayPantalla,int longitud)
{
    int indexVacio = pantalla_buscarPosicionLibre(arrayPantalla,longitud);
    int idNuevo;
    int retorno = -1;
    char bufferNombre[100];
    char bufferDireccion[100];
    char bufferPrecio[30];
    char bufferTipo[4];

    if(arrayPantalla != NULL && indexVacio >=0 && longitud > 0)
    {
       if(val_getNombre(bufferNombre,"Ingrese Nombre de la Pantalla: \n","ERROR: Nombre no valido. \n \n",2,50)== 0)
       {
            if(val_getDireccion(bufferDireccion,"Ingrese Direccion: \n","ERROR: Direccion no valida. \n \n",2,50)== 0)
            {
                if(val_getTipoPantalla(bufferTipo,"Ingrese Tipo de Pantalla (LCD o LED): \n","ERROR: Tipo no valido. \n",2,4)== 0)
                {
                    if(val_getPrecio(bufferPrecio,"Ingrese Precio: \n","ERROR: Precio no valido. \n",2,30)== 0)
                    {
                         idNuevo = pantalla_generarIDAutoincrementable(arrayPantalla,longitud);
                         arrayPantalla[indexVacio].flag = PANTALLA_OCUPADA;
                         arrayPantalla[indexVacio].idPantalla = idNuevo;
                         strncpy(arrayPantalla[indexVacio].nombre,bufferNombre,100);
                         strncpy(arrayPantalla[indexVacio].direccion,bufferDireccion,31);
                         strncpy(arrayPantalla[indexVacio].tipoPantalla,bufferTipo,100);
                         arrayPantalla[indexVacio].precio = atof(bufferPrecio);
                         retorno = 0;
                    }
                }
            }
       }
    }
    return retorno;
}

/** \brief modifica al usuario. 1) Busco la posicion donde esta el ID, 2) Pido datos nuevos. 3) cargo en los campos.
 *
 * @param
 * @param
 * @return
 */
int pantalla_modificarPantalla(Pantalla* arrayPantalla,int longitud)
{
   int index;
   int retorno = -1;
   char bufferID[50];
   char bufferNombre[50];
   char bufferDireccion[50];
   char bufferPrecio[30];
   char bufferTipo[4];

   if(arrayPantalla != NULL && longitud > 0)
   {
       if(val_getID(bufferID,"Ingrese el ID de la Pantalla a Modificar: \n","ERROR : id no valido \n\n",2,31)== 0)
       {
           index = pantalla_buscarIndicePorId(arrayPantalla,longitud,atoi(bufferID));
           if(index != -1)
           {
             if(val_getNombre(bufferNombre,"Ingrese Nombre de la Pantalla a modificar: \n","ERROR: Nombre no valido. \n \n",2,50)== 0)
             {
                if(val_getDireccion(bufferDireccion,"Ingrese Direccion a modificar: \n","ERROR: Direccion no valida. \n \n",2,50)== 0)
                {
                    if(val_getTipoPantalla(bufferTipo,"Ingrese Tipo de Pantalla (LCD o LED) a modificar: \n","ERROR: Tipo no valido. \n",2,3)== 0)
                    {
                        if(val_getPrecio(bufferPrecio,"Ingrese Precio a modificar: \n","ERROR: Precio no valido. \n",2,30)== 0)
                        {
                            arrayPantalla[index].flag = PANTALLA_OCUPADA;
                            strncpy(arrayPantalla[index].nombre,bufferNombre,100);
                            strncpy(arrayPantalla[index].direccion,bufferDireccion,31);
                            strncpy(arrayPantalla[index].tipoPantalla,bufferTipo,100);
                            arrayPantalla[index].precio = atof(bufferPrecio);
                            retorno = 0;
                        }
                    }
                }
              }
           }
      }
   }
   return retorno;
}

/** \brief da de baja una pantalla
 *
 * \param arrayPantalla
 * \param longitud
 * \return 0 ok / -1 error
 */
int pantalla_bajaPantalla(Pantalla* arrayPantalla,int longitud)
{
    int index;
    int retorno = -1;
    char bufferID[31];

    if(arrayPantalla != NULL && longitud > 0)
    {
        if(val_getID(bufferID,"Ingrese el ID de la Pantalla a Eliminar: \n","ERROR : ID no valido \n\n",2,31)== 0)
        {
            index = pantalla_buscarIndicePorId(arrayPantalla,longitud,atoi(bufferID));
            if(index != -1)
            {
                arrayPantalla[index].flag = PANTALLA_LIBRE;
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief muestra la lista de las pantallas cargados.
 *
 * @param arrayAsociado
 * @param longitud
 * @return -1 si da error la funcion / 0 si esta todo ok.
 */
int pantalla_mostrarPantalla(Pantalla* arrayPantalla, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantalla != NULL && longitud > 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayPantalla[i].flag == PANTALLA_OCUPADA)
            {
                printf("\n \n \n ID: %d \n - Nombre: %s \n - Direccion: %s \n - Tipo: %s \n - Precio: %.2f \n",arrayPantalla[i].idPantalla,
                       arrayPantalla[i].nombre,
                       arrayPantalla[i].direccion,
                       arrayPantalla[i].tipoPantalla,
                       arrayPantalla[i].precio);
                retorno = 0;
            }
        }
    }
    return retorno;
}
/**
int pantalla_mostrarPantalla(Pantalla* arrayPantalla, int longitud)
{
   int retorno = -1;
   int i;
   if(arrayPantalla != NULL && longitud >= 0)
   {
       printf("\nID\t NOMBRE\t DIRECCION\t TIPO\t PRECIO");
       printf("\n______________________________________________________________");
       for(i=0; i < longitud ; i++)
       {
           if(arrayPantalla[i].flag == PANTALLA_OCUPADA)
           {
               printf("\n\n %d\t %s\t %s\t\t %s\t %.2f\n \n\n\n",arrayPantalla[i].idPantalla,
                      arrayPantalla[i].nombre,
                      arrayPantalla[i].direccion,
                      arrayPantalla[i].tipoPantalla,
                      arrayPantalla[i].precio);
               retorno = 0;
           }
       }
   }
   return retorno;
}
*/
/** \brief muestra la lista de las pantallas cargados.
 *
 * @param arrayAsociado
 * @param longitud
 * @return -1 si da error la funcion / 0 si esta todo ok.
 */
int pantalla_mostrarPantallasParaPublicidad(Pantalla* arrayPantalla, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantalla != NULL && longitud > 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayPantalla[i].flag == PANTALLA_OCUPADA)
            {
                printf("\n \n \n ID: %d \n - Nombre: %s \n ",arrayPantalla[i].idPantalla,arrayPantalla[i].nombre);
                retorno = 0;
            }
        }
    }
    return retorno;
}
