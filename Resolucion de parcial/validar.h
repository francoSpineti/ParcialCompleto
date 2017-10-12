#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

#endif // VALIDAR_H_INCLUDED

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getID(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getDireccion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getPrecio(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getTipoPantalla(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getMenu(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getDias(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getNombreArchivo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);

// **************************** validarciones
int val_validarNombre(char* buffer);
int val_validarDireccion(char* buffer);
int val_validarID(char* buffer);
int val_validarPrecio(char* buffer);
int val_validarTipoPantalla(char* buffer);
int val_validarMenu(char* buffer);
int val_validarCuit(char* buffer);
int val_validarDias(char* buffer);
int val_validarNombreArchivo(char* buffer);
void myFgets(char* buffer, int limite ,FILE* archivo);
