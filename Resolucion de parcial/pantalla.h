#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct{
    int idPantalla;
    char nombre[100];
    char direccion[100];
    float precio;
    int flag;
    char tipoPantalla[4];
}Pantalla;
#endif // PANTALLA_H_INCLUDED

#define PANTALLA_OCUPADA 1
#define PANTALLA_LIBRE 0
#define CANTIDAD_PANTALLAS 3

int pantalla_buscarIndicePorId(Pantalla* arrayPantalla,int longitud,int id);

int pantalla_inicializarArray(Pantalla* arrayPantalla,int longitud);

int pantalla_altaPantalla(Pantalla* arrayPantalla,int longitud);

int pantalla_modificarPantalla(Pantalla* arrayPantalla,int longitud);

int pantalla_bajaPantalla(Pantalla* arrayPantalla,int longitud);

int pantalla_mostrarPantalla(Pantalla* arrayPantalla, int longitud);

int pantalla_mostrarPantallasParaPublicidad(Pantalla* arrayPantalla, int longitud);

int pantalla_mostrarPantalla(Pantalla* arrayPantalla, int longitud);
