#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "validar.h"
#include "Contratacion.h"

int main()
{
    int cuit;
    Pantalla arrayPantalla[CANTIDAD_PANTALLAS];
    pantalla_inicializarArray(arrayPantalla,CANTIDAD_PANTALLAS);

    Contratacion arrayContratacion[CANTIDAD_CONTRATACION];
    contratacion_inicializarArray(arrayContratacion,CANTIDAD_CONTRATACION);
    char bufferMenu[3];
    do
    {
        val_getMenu(bufferMenu,"\n1-Alta Pantalla\n2-Modificar datos de Pantalla\n3-Baja de Pantalla\n4-Contratar Publicidad\n5-Modificar publicidad\n6-Cancelar Contratacion\n7-Consulta de Facturacion\n8-Listar Contrataciones\n9-Listar Pantallas\n10-Informar los clientes con sus contrataciones\n11-Informar Cliente con importe mas alto a facturar\n0-Salir\n","\nSolo 1,2,3,4,5,6,7,8,9,10,11\n",2,3);
        system("cls");
        switch(atoi(bufferMenu))
        {
        case 1:
            if(pantalla_altaPantalla(arrayPantalla,CANTIDAD_PANTALLAS) == 0)
                printf("\n Se creo una nueva pantalla \n");
            else
                printf("\n No se puede agregar mas registros \n");

            system("pause");
            break;

        case 2:
            if(pantalla_modificarPantalla(arrayPantalla,CANTIDAD_PANTALLAS) == 0)
                printf("\n Pantalla modificada \n");
            else
                printf("\n No se encuentra el ID ingresado \n");
            system("pause");
            break;

        case 3:
            if(pantalla_bajaPantalla(arrayPantalla,CANTIDAD_PANTALLAS) == 0)
                printf("\n Se dio de baja la pantalla \n");
            else
                printf("\n No se encuentra el ID ingresado \n");
            system("pause");
            break;

        case 4:
            if(pantalla_mostrarPantalla(arrayPantalla,CANTIDAD_PANTALLAS) == 0)
                contratacion_altaPublicidad(arrayContratacion,CANTIDAD_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS);
            else
                printf("\n No hay pantallas por mostrar \n");
            system("pause");
            break;

        case 5:
            cuit = contratacion_mostrarCuitsDeClientes(arrayContratacion,CANTIDAD_CONTRATACION);
            if(cuit != -1)
                contratacion_modificarPublicidad(arrayContratacion,CANTIDAD_CONTRATACION,cuit);
            else
                printf("\n No se Pudo modificar la publicidad \n");
            system("pause");
            break;

        case 6:
            cuit = contratacion_mostrarCuitsDeClientes(arrayContratacion,CANTIDAD_CONTRATACION);
            if(cuit != -1)
                contratacion_bajaPublicidad(arrayContratacion,CANTIDAD_CONTRATACION,cuit);
            else
                printf("\n No se puede dar de baja una publicidad \n");
            system("pause");
            break;

        case 7:
            if(contratacion_listarFacturacion(arrayContratacion,CANTIDAD_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS) == -1)
                printf("\n Hubo un error al mostrar la lista \n");
            system("pause");
            break;

        case 8:
            if(contratacion_mostrarContratacion(arrayContratacion,CANTIDAD_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS) == -1)
                printf("\n No hay Contrataciones por mostrar \n");
            system("pause");
            break;

        case 9:
            if(pantalla_mostrarPantalla(arrayPantalla,CANTIDAD_PANTALLAS) == -1)
                printf("\n No hay pantallas por mostrar \n");
            system("pause");
            break;

        case 10:
            if(contratacion_InformeDeClientesConFacturacion(arrayContratacion,CANTIDAD_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS) == -1)
                printf("\n No existen contrataciones \n");
            system("pause");
            break;

        case 11:
            if(contratacion_informarClienteImporteConMasAlto(arrayContratacion,CANTIDAD_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS) == -1)
                printf("\n No existen publicidades \n");
            system("pause");
            break;
        }
        system("cls");
    }
    while( atoi(bufferMenu) != 0);

    return 0;
}
