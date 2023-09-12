#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Util.h"

struct Nodo;

typedef struct Nodo* NodoPtr;


/***

     Funcion de construccion (constructor)
     Precondición: Debe haber memoria suficiente
     Postcondición: Se reserva memoria dinamica para el nodo
     Parámetros: Ninguno
     Devuelve: Puntero al nodo creado

***/
NodoPtr crearNodo(void* dato);

/***

     Funcion de destruccion (destructor)
     Precondición: El nodo debe haberse creado
     Postcondición: Se Libera la memoria dinamica del nodo eliminado
     Parámetros: Puntero al nodo a destruir
     Devuelve: NULL

***/
NodoPtr destruirNodo(NodoPtr nodo);

/***

     Procedimiento de asignacion de datos de nodo
     Precondición: El nodo debe haber sido creado
     Postcondición: Asigna el valor correspondiente al dato del nodo
     Parámetros: Puntero al nodo y Puntero al dato
     Devuelve: Vacio

***/
void setDato(NodoPtr nodo, void* dato);

/***

     Funcion de obtención de datos del nodo
     Precondición: El nodo debe haber sido creado
     Postcondición: Obtiene el dato del nodo
     Parámetros: Puntero al nodo
     Devuelve: Puntero al dato

***/
void* getDato(NodoPtr nodo);

/***

     Procedimiento de asignacion del siguiente nodo
     Precondición: Ambos nodos deben haber sido creados
     Postcondición: Se asigna el nodo siguiente del nodo en cuestion
     Parámetros: Puntero al nodo actual y al siguiente nodo para asignar
     Devuelve: Vacio

***/
void setSiguiente(NodoPtr esteNodo, NodoPtr siguienteNodo);

/***

     Funcion de obtención del siguiente nodo
     Precondición: El nodo debe haber sido creado
     Postcondición: Se obtiene el nodo siguiente del nodo seleccionado
     Parámetros: Puntero al nodo a utilizar
     Devuelve: Puntero a nodo
***/
NodoPtr getSiguiente(NodoPtr nodo);

#endif // NODO_H_INCLUDED
