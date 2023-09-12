#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo.h"

struct Lista;

typedef struct Lista* ListaPtr;

/***

    Funcion de construccion (constructor)
    Precondici�n: La lista no debe haber sido creada.
    Postcondici�n: Reserva en memoria dinamica la lista
    Par�metros: Ninguno
    Devuelve: Puntero a la lista creada

***/
ListaPtr crearLista();


/***
     Funcion de destruccion (destructor)
     Precondici�n: La lista debe haber sido creada
     Postcondici�n: Se libera la memoria de lista.
     Par�metros: Puntero a la lista y si desea remover los elementos
     Devuelve: NULL

***/
ListaPtr destruirLista(ListaPtr lista);

/***
     Funcion de asignar el primer nodo
     Precondici�n: La lista debe haber sido creada
     Postcondici�n: Se asigna el primer nodo de la lista
     Par�metros: Puntero a la lista y puntero al nodo a insertar
     Devuelve: Vacio

***/
void setNodoPrimero(ListaPtr lista, NodoPtr nodo);


/***
     Funcion de obtencion del primer nodo
     Precondici�n: La lista debe haber sido creada
     Postcondici�n: Se obtiene el primer nodo de la lista
     Par�metros: Puntero a la lista
     Devuelve: Puntero al primer nodo de la lista

***/
NodoPtr getNodoPrimero(ListaPtr lista);


/***

     Funcion de verificaci�n de estado
     Precondici�n: La lista debe haber sido creada.
     Postcondici�n: Se informa el estado de la lista
     Par�metros: Puntero a la lista
     Devuelve: True si esta vacia, false de lo contrario

***/
bool listaVacia(ListaPtr lista);

/***

     Funcion de obtenci�n del dato
     Precondici�n: La lista debe haber sido creada.
     Postcondici�n: Se obitiene el dato en la posicion solicitada
     Par�metros: Puntero a la lista y la posicion indicada
     Devuelve puntero al dato obtenido

***/
void* getDatoLista(ListaPtr lista, int posicion);

/***

     Funcion de obtenci�n del dato de la primera posici�n
     Precondici�n: La lista debe haber sido creada.
     Postcondici�n: Se obitiene el dato en la primera posicion
     Par�metros: Puntero a la lista
     Devuelve: Puntero al dato de la cabecera

***/
void* getCabecera(ListaPtr lista);

/***

     Funcion de obtenci�n de la longitud de la lista
     Precondici�n: La lista debe haber sido creada.
     Postcondici�n: Se obtiene la longitud de la lista
     Par�metros: Puntero de la lista
     Devuelve: Cantidad total de elementos

***/
int longitudLista(ListaPtr lista);

/***
     Procedimiento de agregado antes de la cabecera
     Precondici�n: La lista debe haber sido creada.
     Postcondici�n: Se agrega el dato antes de la cabecera de la lista
     Par�metros: Puntero a la lista, Puntero al dato
     Devuelve: Vacio

***/
void agregarDatoLista(ListaPtr lista, void* dato);

/***
     Funcion de inserci�n de elemento en lista
     Precondici�n: La lista debe haber sido creada.
     Postcondici�n: Se inserta el dato despues de la posici�n indicada
     Par�metros: Puntero a la lista, Puntero al dato a insertar, Posicion indicada
     Devuelve true si pudo insertar, false de lo contrario

***/
void insertarDatoLista(ListaPtr lista, void* dato, int posicion);

/***

     Funcion de remover elemento de la lista
     Precondici�n: La lista debe haber sido creada
     Postcondici�n: Se elimina el nodo de la posici�n indicada
     Par�metros: Puntero a la lista y la posicion indicada
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
