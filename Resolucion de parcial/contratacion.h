#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED
typedef struct{
    int idContratacion;
    int idPantalla;
    int cantidadDeDias;
    char nombreArchivo[50];
    int flag;
    int cuitCliente;
}Contratacion;
#endif // PUBLICIDAD_H_INCLUDED

#define CONTRATACION_LIBRE 0
#define CONTRATACION_OCUPADA 1
#define CANTIDAD_CONTRATACION 5
#include "Pantalla.h"

int contratacion_altaPublicidad(Contratacion* arrayContratacion,int longitud,Pantalla* arrayPantalla,int longitudPantalla);

int contratacion_modificarPublicidad(Contratacion* arrayContratacion,int longitud,int cuit);

int contratacion_bajaPublicidad(Contratacion* arrayContratacion,int longitud,int cuit);

int contratacion_mostrarCuitsDeClientes(Contratacion* arrayContratacion, int longitud);

int contratacion_inicializarArray(Contratacion* arrayContratacion,int longitud);

int contratacion_informarClienteImporteConMasAlto(Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla);

int contratacion_buscarPrecioPorCuit(int cuitCliente,Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla);

int contratacion_listarFacturacion(Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla);

int contratacion_mostrarContratacion(Contratacion* arrayContratacion, int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla);

int contratacion_InformeDeClientesConFacturacion(Contratacion* arrayContratacion,int longitudContratacion,Pantalla* arrayPantalla,int longitudPantalla);

int verExistencia(int* vectorAux, int cuit);
