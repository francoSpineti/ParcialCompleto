#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#define MAX_INPUT_BUFFER 4096
#define esBlanco(x) ((x) == ' ' || (x) == '\t'? 1:0)

/** \brief fgets personalizado
 *
 * \param
 * \param
 * \return
 *
 */
void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fflush(stdin);
    fgets(buffer, limite,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

/** \brief pide nombre por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el nombre. / -1 si tiene un ERROR.
 */
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarNombre(buffer) == -1)
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


/** \brief pide nombre de archivo por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el nombre. / -1 si tiene un ERROR.
 */
int val_getNombreArchivo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarNombreArchivo(buffer) == -1)
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



/** \brief pide descripcion por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el nombre. / -1 si tiene un ERROR.
 */
int val_getDireccion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarDireccion(buffer) == -1)
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

/** \brief pide menu por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente la edad. / -1 si tiene un ERROR.
 */
int val_getMenu(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarMenu(buffer) == -1)
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
 * @return  0 si valido correctamente la edad. / -1 si tiene un ERROR.
 */
int val_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarCuit(buffer) == -1)
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
 * @return  0 si valido correctamente la edad. / -1 si tiene un ERROR.
 */
int val_getDias(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarDias(buffer) == -1)
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
int val_getID(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarID(buffer) == -1)
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

/** \brief pide un precio por consola
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el nombre. / -1 si tiene un ERROR.
 */
int val_getPrecio(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarPrecio(buffer) == -1)
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


/** \brief pide tipo de pantalla por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el nombre. / -1 si tiene un ERROR.
 */
int val_getTipoPantalla(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarTipoPantalla(buffer) == -1)
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

// ****************************************************************************** VALIDACIONES ***********************************************************

/** \brief valida un nombre.
 *
 * @param buffer
 * @return 0 OK / -1 si el nombre esta mal ingresado.
 *
 */
int val_validarNombre(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (esBlanco(buffer[i]) == 0) && (buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/** \brief valida un nombre y puntos
 *
 * @param buffer
 * @return 0 OK / -1 si el nombre esta mal ingresado.
 *
 */
int val_validarNombreArchivo(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (esBlanco(buffer[i]) == 0) && (buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '.')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}


/** \brief valida un tipo de pantalla.
 *
 * @param buffer
 * @return 0 OK / -1 si el nombre esta mal ingresado.
 */
int val_validarTipoPantalla(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < 'A' || buffer[i] > 'Z')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/** \brief valida una direccion.
 *
 * @param buffer
 * @return 0 OK / -1 si la direccion esta mal ingresada.
 *
 */
int val_validarDireccion(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z')&& (esBlanco(buffer[i]) == 0) && (buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/** \brief valida el menu del main.
 *
 * @param buffer
 * @return 0 OK / -1 si la edad esta mal ingresada.
 *
 */
int val_validarMenu(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief valida un ID.
 *
 * @param buffer
 * @return 0 OK / -1 si la edad esta mal ingresada.
 */
int val_validarID(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/** \brief valida un precio
 *
 * \param buffer
 * \return 0 si esta ok / -1 error
 */
int val_validarPrecio(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' && (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            else
            {
                if(buffer[i] == '-' && i != 0)
                {
                    retorno = -1;
                    break;
                }
                else if(buffer[i] == '.')
                {
                    flagPunto++;
                    if(flagPunto > 1)
                    {
                        retorno = -1;
                        break;
                    }
                }
            }
            i++;
        }
    }

    return retorno;
}

/** \brief valida el cuit del cliente.
 *
 * @param buffer
 * @return 0 OK / -1 si la edad esta mal ingresada.
 *
 */
int val_validarCuit(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}


/** \brief valida dias.
 *
 * @param buffer
 * @return 0 OK / -1 si la edad esta mal ingresada.
 *
 */
int val_validarDias(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}
