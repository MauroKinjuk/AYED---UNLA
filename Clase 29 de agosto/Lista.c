#include "Lista.h"

struct Lista {
    NodoPtr primero;
};

NodoPtr getNodoPrimero(ListaPtr lista)
{
    return lista->primero;
}

void setNodoPrimero(ListaPtr lista, NodoPtr nodo)
{
    lista->primero = nodo;
}

ListaPtr crearLista()
{
    ListaPtr lista = malloc(sizeof(struct Lista));
    lista->primero = NULL;
    return lista;
};

ListaPtr destruirLista(ListaPtr lista)
{
    while(!listaVacia(lista))
    {
        removerDeLista(lista,0);
    }
    free(lista);
    return NULL;
}

bool listaVacia(ListaPtr lista)
{
    return (getNodoPrimero(lista) == NULL);
}

NodoPtr getNodoLista(ListaPtr lista, int posicion)
{
    NodoPtr nodo = getNodoPrimero(lista);
    int posicionActual = 0;
    if(nodo != NULL)
    {
        while(posicionActual < posicion && getSiguiente(nodo) != NULL)
        {
            posicionActual++;
            nodo = getSiguiente(nodo);
        }
    }
    return nodo;
}

void* getDatoLista(ListaPtr lista, int posicion)
{
    void* dato = NULL;
    NodoPtr nodo = getNodoLista(lista, posicion);
    if(nodo != NULL)
    {
        dato = getDato(nodo);
    }
    return dato;
}

void* getCabecera(ListaPtr lista)
{
    void* dato = NULL;
    if(getNodoPrimero(lista) != NULL)
    {
        dato = getDato(getNodoPrimero(lista));
    }
    return dato;
}

int longitudLista(ListaPtr lista)
{
    int longitud = 0;
    NodoPtr nodo = getNodoPrimero(lista);
    while(nodo != NULL)
    {
        nodo = getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}

void agregarDatoLista(ListaPtr lista, void* dato)
{
    NodoPtr nuevoNodo = crearNodo(dato);
    setSiguiente(nuevoNodo, getNodoPrimero(lista));
    setNodoPrimero(lista, nuevoNodo);
}

void insertarDatoLista(ListaPtr lista, void* dato, int posicion)
{
    NodoPtr nuevoNodo = crearNodo(dato);
    if (posicion == 0 || getNodoPrimero(lista) == NULL)
    {
        agregarDatoLista(lista, dato);
    }
    else
    {
        NodoPtr nodoAnterior = getNodoPrimero(lista);
        nodoAnterior = getNodoLista(lista, posicion-1);
        setSiguiente(nuevoNodo, getSiguiente(nodoAnterior));
        setSiguiente(nodoAnterior, nuevoNodo);
    }
}

void* removerDeLista(ListaPtr lista, int posicion)
{
    void* dato = NULL;
    NodoPtr nodoEliminar = NULL;
    if(getNodoPrimero(lista) != NULL)
    {
        if(posicion == 0)
        {
            nodoEliminar = getNodoPrimero(lista);
            dato = getDato(nodoEliminar);
            setNodoPrimero(lista, getSiguiente(getNodoPrimero(lista)));
            destruirNodo(nodoEliminar);
        }
        else
        {
            NodoPtr nodoAnterior = getNodoLista(lista, posicion-1);
            if(nodoAnterior != NULL)
            {
                nodoEliminar = getSiguiente(nodoAnterior);
                if(nodoEliminar != NULL)
                {
                    dato = getDato(nodoEliminar);
                    setSiguiente(nodoAnterior, getSiguiente(nodoEliminar));
                    destruirNodo(nodoEliminar);
                }
            }
        }
    }
    return dato;
}
