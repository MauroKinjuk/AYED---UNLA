#include "Nodo.h"

struct Nodo{
    void* dato;
    struct Nodo* sgte;
};

NodoPtr crearNodo(void* dato)
{
    NodoPtr nodo = (NodoPtr)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->sgte = NULL;
    return nodo;
}

NodoPtr destruirNodo(NodoPtr nodo)
{
    free(nodo);
    return NULL;
}

void setDato(NodoPtr nodo, void* dato)
{
    nodo->dato = dato;
}

void* getDato(NodoPtr nodo)
{
    return nodo->dato;
}

void setSiguiente(NodoPtr esteNodo, NodoPtr siguienteNodo)
{
    esteNodo->sgte = siguienteNodo;
}

NodoPtr getSiguiente(NodoPtr nodo)
{
    return nodo->sgte;
}
