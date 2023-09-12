#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estadios.h"

struct EstadioE{
    char nombre[30];
    int capacidad;
    char ciudad[30];
};

Estadio crearEstadio(char nombre[30],int cantidad,char ciudad[30]){
    Estadio est = (Estadio)malloc(sizeof(struct EstadioE));

    strcpy(est->ciudad,ciudad);
    strcpy(est->nombre, nombre);

    est->capacidad = cantidad;

    return est;
};

char* getNombre(Estadio estadio){
    return estadio->nombre;
};
char* getCiudad(Estadio estadio){
    return estadio->ciudad;
};
int getCantidad(Estadio estadio){
    return estadio->capacidad;
};

void mostrarEstadio(Estadio estadio){
    printf("\nEstadio:\nNOMBRE: %s CAPACIDAD: %d CIUDAD: %s",getNombre(estadio),getCantidad(estadio),getCiudad(estadio));

};

void ordenarLista(Lista lista){
    //Nodo actual = getPrimero(lista);
    for(int i=0 ; i<obtenerTamanio(lista)-1;i++){
        for(int e=0;e< obtenerTamanio(lista)-1;e++){
            Estadio estadio1 = (Estadio)getDato(obtenerNodoParametro(lista,e));
            Estadio estadio2 = (Estadio)getDato(obtenerNodoParametro(lista,e+1));

            if(strcmp (getNombre(estadio1), getNombre(estadio2) ) >0){
                Nodo aux1 = obtenerNodoParametro(lista,e);
                Nodo aux2 = obtenerNodoParametro(lista,e+1);

                setDato(aux1,estadio2);
                setDato(aux2,estadio1);

            }
        }
    }
};

void insertarOrdenado(Lista lista, Estadio datoNuevo)
{
    ordenarLista(lista);
    Nodo actual = getPrimero(lista);
    int i = 0;
    int ordenado = 0;
    while( actual != NULL && ordenado == 0)
    {
        int resultadoComparacionStrings = strcmp(getNombre((Estadio)getDato(actual)), getNombre(datoNuevo));
        if(resultadoComparacionStrings > 0 )
        {
            insertar(lista, datoNuevo, i);
            ordenado = 1;
        }
        actual = getSiguiente(actual);
        i++;
    }
    if(ordenado == 1)
    {
        return;
    }
    else
    {
        insertarUltimo(lista, datoNuevo);
    }
}
