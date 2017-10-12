#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contratacion.h"
#include "validar.h"
#define MAX_INPUT_BUFFER 4096

//****************** FUNCIONES ESTATICAS ***********************************

static int idAutoincrementable = 0;
static int contratacion_generarIDAutoincrementable(Contratacion* arrayContratacion,int longitud);
static int contratacion_buscarPosicionLibre(Contratacion* arrayContratacion,int longitud);
static int contratacion_buscarIndicePorCuit(Contratacion* arrayContratacion,int longitud,int cuit);
static int contratacion_buscarIndicePorIdPorCuit(Contratacion* arrayContratacion,int longitud,int idPantalla,int cuit,int** index);
static int contratacion_getID(char* destino, char* mensaje,char* mensajeError,int intentos,int limite,Pantalla* arrayPantalla,int longitud);
static int contratacion_getIDConCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite,Contratacion* arrayContratacion,int longitud,int cuit,int* index);
static int contratacion_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite,Contratacion* arrayContratacion,int longitud);

/** \brief genera un Id que se va incrementando de a 1.
 *
 * @param longitud
 * @param arrayContratacion
 * @return retorna el id +1.
 */
static int contratacion_generarIDAutoincrementable(Contratacion* arrayContratacion,int longitud)
{
    idAutoincrementable++;
    return idAutoincrementable;
}

/** \brief funcion que retorna el indice del array por el CUIT, verifica si EXISTE O NO el indice.
 *
 * @param arrayContratacion
 * @param longitud
 * @param id
 * @return
 */
static int contratacion_buscarIndicePorCuit(Contratacion* arrayContratacion,int longitud,int cuit)
{
    int i;
    int retorno = -1;
    if(arrayContratacion != NULL && longitud > 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayContratacion[i].flag == CONTRATACION_OCUPADA && cuit == arrayContratacion[i].cuitCliente)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief funcion que retorna el indice del array por el ID, verifica si EXISTE O NO el indice.
 *
 * @param arrayContratacion
 * @param longitud
 * @param id
 * @return
 */
static int contratacion_buscarIndicePorIdPorCuit(Contratacion* arrayContratacion,int longitud,int idPantalla,int cuit,int** index)
{
    int i;
    int retorno = -1;

    if(arrayContratacion != NULL && longitud > 0 && idPantalla >= 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayContratacion[i].flag == CONTRATACION_OCUPADA && arrayContratacion[i].idPantalla == idPantalla && arrayContratacion[i].cuitCliente == cuit)
            {
                retorno = i;
                index = (int**)i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief me devuelve el index del primer item vacio de la array, la voy a usar para el alta, me retorna la posicion del array, si esta todo ocupado devuelve -1, si hay una posicion libre devuelve i.
 *
 * \param
 * \param longitud
 * \return
 *
 */
static int contratacion_buscarPosicionLibre(Contratacion* arrayContratacion,int longitud)
{
    int retorno = -1;
    int i;
    if(arrayContratacion != NULL && longitud > 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayContratacion[i].flag == CONTRATACION_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide id por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente la id. / -1 si tiene un ERROR.
 */
static int contratacion_getID(char* destino, char* mensaje,char* mensajeError,int intentos,int limite,Pantalla* arrayPantalla,int longitud)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarID(buffer) == -1 || pantalla_buscarIndicePorId(arrayPantalla,longitud,atoi(buffer)) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide cuit por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el cuit. / -1 si tiene un ERROR.
 */
static int contratacion_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite,Contratacion* arrayContratacion,int longitud)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarCuit(buffer) == -1 || contratacion_buscarIndicePorCuit(arrayContratacion,longitud,atoi(buffer)) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide id por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente la id. / -1 si tiene un ERROR.
 */
static int contratacion_getIDConCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite,Contratacion* arrayContratacion,int longitud,int cuit,int* index)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);
            if(val_validarID(buffer) == -1 || contratacion_buscarIndicePorIdPorCuit(arrayContratacion,longitud,atoi(buffer),cuit,&index) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

//**********************************************************     FIN FUNCIONES ESTATICAS    *******************************************************************************************

/** \brief  inicializamos el array, que todos los flags esten libres
 *
 * \param longitud - tamaño/longitud del  array
 * \param arrayContratacion
 * \return 0 = ok
 */
int contratacion_inicializarArray(Contratacion* arrayContratacion,int longitud)
{
    int i;
    for(i=0; i < longitud; i++)
    {
        arrayContratacion[i].flag = CONTRATACION_LIBRE;
    }
    return 0;
}

/** \brief damos de alta una nueva publicidad
 *
 * @param longitud - longitud del array
 * @param arrayContratacion
 * @return 0 ok / -1 error
 */
int contratacion_altaPublicidad(Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla)
{
    int indexVacio = contratacion_buscarPosicionLibre(arrayContratacion,longitudContratacion);
    int idNuevo;
    int retorno = -1;
    char bufferNombre[50];
    char bufferCantidadDias[50];
    char bufferCuit[50];
    char bufferIDPantalla[5];

    if(arrayContratacion != NULL && indexVacio >=0 && longitudContratacion > 0)
    {
        if(contratacion_getID(bufferIDPantalla,"Ingrese el ID de pantalla: \n","ERROR: ID inexistente en la lista. \n",2,5,arrayPantalla,longitudPantalla)==0)
        {
            if(val_getCuit(bufferCuit,"Ingrese el cuit del Cliente: \n","ERROR: cuit no valido. \n",2,11)== 0)
            {
                if(val_getDias(bufferCantidadDias,"Ingrese los dias a contratar: \n","ERROR: dias no validos. \n",2,5)==0)
                {
                    if(val_getNombreArchivo(bufferNombre,"Ingrese el nombre del Archivo: \n","ERROR: nombre invalido. \n",2,50)==0)
                    {
                        idNuevo = contratacion_generarIDAutoincrementable(arrayContratacion,longitudContratacion);
                        arrayContratacion[indexVacio].flag = CONTRATACION_OCUPADA;
                        arrayContratacion[indexVacio].idContratacion = idNuevo;
                        strncpy(arrayContratacion[indexVacio].nombreArchivo,bufferNombre,50);
                        arrayContratacion[indexVacio].cantidadDeDias = atoi(bufferCantidadDias);
                        arrayContratacion[indexVacio].cuitCliente = atoi(bufferCuit);
                        arrayContratacion[indexVacio].idPantalla = atoi(bufferIDPantalla);
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
int contratacion_modificarPublicidad(Contratacion* arrayContratacion,int longitud,int cuit)
{
    int index;
    int retorno = -1;
    char bufferIDPantalla[5];
    char bufferDias[4];

    if(arrayContratacion != NULL && longitud > 0 && cuit > 0)
    {
        if(contratacion_getIDConCuit(bufferIDPantalla,"Ingrese el ID de la Pantalla a Modificar: \n","ERROR : id inexistente \n\n",2,5,arrayContratacion,longitud,cuit,&index) == 0)
        {
            if(index != -1)
            {
                if(val_getDias(bufferDias,"Ingrese los dias a modificar : \n","ERROR: dias no validos. \n",2,4)==0)
                {
                    arrayContratacion[index].cantidadDeDias = atoi(bufferDias);
                    retorno = 0;
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
int contratacion_bajaPublicidad(Contratacion* arrayContratacion,int longitud,int cuit)
{
   int index;
   int retorno = -1;
   char bufferIDPantalla[5];

   if(arrayContratacion != NULL && longitud > 0 && cuit > 0)
   {
       if(contratacion_getIDConCuit(bufferIDPantalla,"Ingrese el ID de la Pantalla a Modificar: \n","ERROR : id inexistente \n\n",2,5,arrayContratacion,longitud,cuit,&index) == 0)
       {
           if(index != -1)
           {
               arrayContratacion[index].flag = CONTRATACION_LIBRE;
               retorno = 0;
            }
        }
   }
   return retorno;
}

/** \brief muestra la lista de los cuits de los clientes cargados.
 *
 * @param arrayContratacion
 * @param longitud
 * @return -1 si da error la funcion / 0 si esta todo ok.
 */
int contratacion_mostrarCuitsDeClientes(Contratacion* arrayContratacion, int longitud)
{
    //int retorno = -1;
    int i;
    char bufferCuit[13];
    if(arrayContratacion != NULL && longitud > 0)
    {
        if(contratacion_getCuit(bufferCuit,"Ingrese CUIT del Cliente: \n","ERROR: Cuit inexistente en la lista. \n",2,13,arrayContratacion,longitud)==0)
        {
            for(i=0; i < longitud ; i++)
            {
                if(arrayContratacion[i].flag == CONTRATACION_OCUPADA && arrayContratacion[i].cuitCliente == atoi(bufferCuit))
                {
                    printf("\n\n\n ID Pantalla : %d \n - Nombre de Archivo : %s \n - Cantidad de Dias : %d \n",arrayContratacion[i].idPantalla,
                           arrayContratacion[i].nombreArchivo,
                           arrayContratacion[i].cantidadDeDias);
                    //retorno = 0;
                }
            }
        }
    }
    return atoi(bufferCuit);
}

/** \brief lista y muestra al cliente con el importe mas alto
 *
 * @param arrayContratacion
 * @param longitudContratacion
 * @param arrayPantalla
 * @param longitudPantalla
 * \return 0 ok
 */
int contratacion_informarClienteImporteConMasAlto(Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla)
{
    int i, cuitClienteMayor = 0, precioClienteMayor = 0;

    if(arrayContratacion != NULL && longitudContratacion > 0)
    {
        for(i = 0; i < longitudContratacion; i++)
        {
            if(arrayContratacion[i].flag == CONTRATACION_OCUPADA && contratacion_buscarPrecioPorCuit(arrayContratacion[i].cuitCliente,arrayContratacion,longitudContratacion,arrayPantalla,longitudPantalla) > precioClienteMayor)
            {
                precioClienteMayor = contratacion_buscarPrecioPorCuit(arrayContratacion[i].cuitCliente,arrayContratacion,longitudContratacion,arrayPantalla,longitudPantalla);
                cuitClienteMayor = arrayContratacion[i].cuitCliente;
            }
        }

        printf("\n El cuit del cliente con mayor importe a facturar es: %d \n", cuitClienteMayor);
        printf("\n El importe del cliente con mayor importe a facturar es: %d \n", precioClienteMayor);
    }

    return 0;
}

/** \brief Busca los precios del cuit
 *
 * @param
 * @param
 * @return retorna los precios del cuit del cliente
 */
int contratacion_buscarPrecioPorCuit(int cuitCliente,Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla)
{
    int i, idPantalla, pos, precioCliente = 0;

    for(i = 0; i < longitudContratacion; i++)
    {
        if(cuitCliente == arrayContratacion[i].cuitCliente)
        {
            idPantalla = arrayContratacion[i].idPantalla;
            pos = pantalla_buscarIndicePorId(arrayPantalla,longitudPantalla,idPantalla);
            precioCliente += arrayPantalla[pos].precio * arrayContratacion[i].cantidadDeDias;;
        }
    }

    return precioCliente;
}

int contratacion_InformeDeClientesConFacturacion(Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla)
{
   int retorno = -1, j, i, pos, idPantalla, vectorAux[CANTIDAD_CONTRATACION];
   float precioTotalCliente;

    if(arrayContratacion != NULL && longitudContratacion > 0)
    {
        for(i=0; i<longitudContratacion; i++)
        {
            if(arrayContratacion[i].flag == CONTRATACION_OCUPADA && verExistencia(vectorAux, arrayContratacion[i].cuitCliente) == -1)
            {
                vectorAux[i] = arrayContratacion[i].cuitCliente;
                for(j = 0;  j<longitudContratacion; j++)
                {
                    if(arrayContratacion[j].flag == CONTRATACION_OCUPADA && arrayContratacion[j].cuitCliente == arrayContratacion[i].cuitCliente)
                    {
                        idPantalla = arrayContratacion[j].idPantalla;
                        pos = pantalla_buscarIndicePorId(arrayPantalla,longitudPantalla,idPantalla);
                        precioTotalCliente = arrayPantalla[pos].precio * arrayContratacion[j].cantidadDeDias;
                        printf("CUIT: %d \n ID DE PANTALLA: %d \n CANTIDAD DE DIAS CONTRATADOS: %d \n PRECIO POR DIA: %.2f \n TOTAL A FACTURAR: %.2f \n\n",
                        arrayContratacion[j].cuitCliente, idPantalla, arrayContratacion[j].cantidadDeDias,arrayPantalla[pos].precio, precioTotalCliente);
                    }
                }
            }
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief vector auxiliar para guardar los cuits para no repetirlos
 *
 * @param vector aux
 * @param cuit
 * @return -1 error 0 ok
 */
int verExistencia(int* vectorAux, int cuit)
{
    int i;

    if(vectorAux != NULL)
    {
        for(i = 0; i < CANTIDAD_CONTRATACION; i++)
            if(vectorAux[i] == cuit)
                return 0;
    }

    return -1;
}

/** \brief Se ingresa el cuit del cliente deseado y muestra todas sus contrataciones
 *
 * @param arrayContratacion
 * @param longitudContratacion
 * @param arrayPantalla
 * @param longitudPantalla
 * @return 0 = ok / -1 error
 */
int contratacion_listarFacturacion(Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla)
{
  int retorno = -1, i, pos, idPantalla;
  float precioTotalCliente;
  char bufferCuit[13];

   if(arrayContratacion != NULL && longitudContratacion > 0)
   {
       if(contratacion_getCuit(bufferCuit,"Ingrese CUIT del Cliente: \n","ERROR: Cuit inexistente en la lista. \n",2,13,arrayContratacion,longitudContratacion)==0)
       {
           for(i=0; i<longitudContratacion; i++)
           {
               if(arrayContratacion[i].cuitCliente == atoi(bufferCuit) && arrayContratacion[i].flag == CONTRATACION_OCUPADA)
               {
                   idPantalla = arrayContratacion[i].idPantalla;
                   pos = pantalla_buscarIndicePorId(arrayPantalla,longitudPantalla,idPantalla);
                   precioTotalCliente = arrayPantalla[pos].precio * arrayContratacion[i].cantidadDeDias;
                   if(arrayPantalla[pos].flag == CONTRATACION_OCUPADA)
                   {
                       printf("CUIT: %d \n ID DE PANTALLA: %d \n CANTIDAD DE DIAS CONTRATADOS: %d \n PRECIO POR DIA: %.2f \n TOTAL A FACTURAR: %.2f \n\n",
                          arrayContratacion[i].cuitCliente, idPantalla, arrayContratacion[i].cantidadDeDias,arrayPantalla[pos].precio, precioTotalCliente);
                       retorno = 0;
                   }
               }
           }
       }
  }

  return retorno;
}

/** \brief muestra todas las contrataciones cargadas.
 *
 * @param arrayContratacion
 * @param longitudContratacion
 * @param arrayPantalla
 * @param longitudPantalla
 * @return 0 = ok / -1 error.
 */
int contratacion_mostrarContratacion(Contratacion* arrayContratacion, int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla)
{
  int retorno = -1;
  int i, idPantalla, pos;
  char bufferNombre[100];

  if(arrayContratacion != NULL && longitudContratacion > 0)
  {
      printf("\nNOMBRE PANTALLA\t VIDEO\t DIAS\t CUIT");
      printf("\n______________________________________________________________ \n");
      for(i=0; i < longitudContratacion ; i++)
      {
          if(arrayContratacion[i].flag == CONTRATACION_OCUPADA)
          {
              idPantalla = arrayContratacion[i].idPantalla;
              pos = pantalla_buscarIndicePorId(arrayPantalla,longitudPantalla,idPantalla);
              if(arrayPantalla[pos].flag == CONTRATACION_OCUPADA)
              {
                  strcpy(bufferNombre,arrayPantalla[pos].nombre);
                  printf("\n\n %s\t\t %s\t %d\t %d\n",bufferNombre,
                         arrayContratacion[i].nombreArchivo,
                         arrayContratacion[i].cantidadDeDias,
                         arrayContratacion[i].cuitCliente);
                  retorno = 0;
              }
          }
      }
  }
  return retorno;
}
