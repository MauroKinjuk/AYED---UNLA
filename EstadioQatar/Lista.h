#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct NodoE;
typedef struct NodoE* Nodo;
struct ListaE;
typedef struct ListaE* Lista;

Nodo crearNodo(void* dato);
Lista crearLista();

Nodo destruirNodo(Nodo nodo);
Lista destruirLista(Lista lista);
int listaVacia(Lista lista);

void* getDato(Nodo nodo);
Nodo getSiguiente(Nodo nodo);
Nodo getPrimero(Lista lista);
Nodo obtenerUltimo(Lista lista);
Nodo obtenerPrimero(Lista lista);
Nodo obtenerNodoParametro(Lista lista, int longitud);
int obtenerTamanio(Lista lista);

void setDato(Nodo nodo,void* datoNuevo);
void setSiguiente(Nodo nodo, Nodo siguiente);
void setPrimero(Lista lista,Nodo nodo);

void insertarPrimero(Lista lista,void* dato);
void insertarUltimo(Lista lista, void* dato);
void insertar(Lista lista,void* dato, int posicionInsertar);

Lista duplicarLista(Lista original);

#endif // LISTA_H_INCLUDED
