#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Util.h"

struct Nodo;

typedef struct Nodo* NodoPtr;


/***

     Funcion de construccion (constructor)
     Precondici�n: Debe haber memoria suficiente
     Postcondici�n: Se reserva memoria dinamica para el nodo
     Par�metros: Ninguno
     Devuelve: Puntero al nodo creado

***/
NodoPtr crearNodo(void* dato);

/***

     Funcion de destruccion (destructor)
     Precondici�n: El nodo debe haberse creado
     Postcondici�n: Se Libera la memoria dinamica del nodo eliminado
     Par�metros: Puntero al nodo a destruir
     Devuelve: NULL

***/
NodoPtr destruirNodo(NodoPtr nodo);

/***

     Procedimiento de asignacion de datos de nodo
     Precondici�n: El nodo debe haber sido creado
     Postcondici�n: Asigna el valor correspondiente al dato del nodo
     Par�metros: Puntero al nodo y Puntero al dato
     Devuelve: Vacio

***/
void setDato(NodoPtr nodo, void* dato);

/***

     Funcion de obtenci�n de datos del nodo
     Precondici�n: El nodo debe haber sido creado
     Postcondici�n: Obtiene el dato del nodo
     Par�metros: Puntero al nodo
     Devuelve: Puntero al dato

***/
void* getDato(NodoPtr nodo);

/***

     Procedimiento de asignacion del siguiente nodo
     Precondici�n: Ambos nodos deben haber sido creados
     Postcondici�n: Se asigna el nodo siguiente del nodo en cuestion
     Par�metros: Puntero al nodo actual y al siguiente nodo para asignar
     Devuelve: Vacio

***/
void setSiguiente(NodoPtr esteNodo, NodoPtr siguienteNodo);

/***

     Funcion de obtenci�n del siguiente nodo
     Precondici�n: El nodo debe haber sido creado
     Postcondici�n: Se obtiene el nodo siguiente del nodo seleccionado
     Par�metros: Puntero al nodo a utilizar
     Devuelve: Puntero a nodo
***/
NodoPtr getSiguiente(NodoPtr nodo);

#endif // NODO_H_INCLUDED
