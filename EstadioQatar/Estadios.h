#ifndef ESTADIOS_H_INCLUDED
#define ESTADIOS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
struct EstadioE;
typedef struct EstadioE * Estadio;

Estadio crearEstadio(char nombre[30],int cantidad,char ciudad[30]);

char* getNombre(Estadio estadio);
char* getCiudad(Estadio estadio);
int getCantidad(Estadio estadio);

void mostrarEstadio(Estadio estadio);

void ordenarLista(Lista lista);
void insertarOrdenado(Lista lista,Estadio datoNuevo);

#endif // ESTADIOS_H_INCLUDED
