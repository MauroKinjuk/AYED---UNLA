#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo.h"

struct Lista;

typedef struct Lista* ListaPtr;

/***

    Funcion de construccion (constructor)
    Precondición: La lista no debe haber sido creada.
    Postcondición: Reserva en memoria dinamica la lista
    Parámetros: Ninguno
    Devuelve: Puntero a la lista creada

***/
ListaPtr crearLista();


/***
     Funcion de destruccion (destructor)
     Precondición: La lista debe haber sido creada
     Postcondición: Se libera la memoria de lista.
     Parámetros: Puntero a la lista y si desea remover los elementos
     Devuelve: NULL

***/
ListaPtr destruirLista(ListaPtr lista);

/***
     Funcion de asignar el primer nodo
     Precondición: La lista debe haber sido creada
     Postcondición: Se asigna el primer nodo de la lista
     Parámetros: Puntero a la lista y puntero al nodo a insertar
     Devuelve: Vacio

***/
void setNodoPrimero(ListaPtr lista, NodoPtr nodo);


/***
     Funcion de obtencion del primer nodo
     Precondición: La lista debe haber sido creada
     Postcondición: Se obtiene el primer nodo de la lista
     Parámetros: Puntero a la lista
     Devuelve: Puntero al primer nodo de la lista

***/
NodoPtr getNodoPrimero(ListaPtr lista);


/***

     Funcion de verificación de estado
     Precondición: La lista debe haber sido creada.
     Postcondición: Se informa el estado de la lista
     Parámetros: Puntero a la lista
     Devuelve: True si esta vacia, false de lo contrario

***/
bool listaVacia(ListaPtr lista);

/***

     Funcion de obtención del dato
     Precondición: La lista debe haber sido creada.
     Postcondición: Se obitiene el dato en la posicion solicitada
     Parámetros: Puntero a la lista y la posicion indicada
     Devuelve puntero al dato obtenido

***/
void* getDatoLista(ListaPtr lista, int posicion);

/***

     Funcion de obtención del dato de la primera posición
     Precondición: La lista debe haber sido creada.
     Postcondición: Se obitiene el dato en la primera posicion
     Parámetros: Puntero a la lista
     Devuelve: Puntero al dato de la cabecera

***/
void* getCabecera(ListaPtr lista);

/***

     Funcion de obtención de la longitud de la lista
     Precondición: La lista debe haber sido creada.
     Postcondición: Se obtiene la longitud de la lista
     Parámetros: Puntero de la lista
     Devuelve: Cantidad total de elementos

***/
int longitudLista(ListaPtr lista);

/***
     Procedimiento de agregado antes de la cabecera
     Precondición: La lista debe haber sido creada.
     Postcondición: Se agrega el dato antes de la cabecera de la lista
     Parámetros: Puntero a la lista, Puntero al dato
     Devuelve: Vacio

***/
void agregarDatoLista(ListaPtr lista, void* dato);

/***
     Funcion de inserción de elemento en lista
     Precondición: La lista debe haber sido creada.
     Postcondición: Se inserta el dato despues de la posición indicada
     Parámetros: Puntero a la lista, Puntero al dato a insertar, Posicion indicada
     Devuelve true si pudo insertar, false de lo contrario

***/
void insertarDatoLista(ListaPtr lista, void* dato, int posicion);

/***

     Funcion de remover elemento de la lista
     Precondición: La lista debe haber sido creada
     Postcondición: Se elimina el nodo de la posición indicada
     Parámetros: Puntero a la lista y la posicion indicada
     Devuelve: Puntero al dato eliminado

***/
void* removerDeLista(ListaPtr lista, int posicion);


/***

    Funcion de obtener nodo lista
    Precondicion: La lista debe haber sido creada
    Postcondicion: Se obtiene el nodo de la lista con la posicion indicada
    Parametros: Puntero a la lista y la posicion a extraer
    Devuelve: Puntero al nodo extraido

***/
NodoPtr getNodoLista(ListaPtr lista, int posicion);

#endif // LISTA_H_INCLUDED
