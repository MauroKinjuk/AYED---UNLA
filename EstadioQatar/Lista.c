#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
struct NodoE{
    void* dato;
    Nodo siguiente;
};

struct ListaE{
    Nodo primero;

};

Nodo crearNodo(void* dato){
    Nodo nodo = (Nodo)malloc(sizeof(struct NodoE));
    nodo->dato=dato;
    nodo->siguiente=NULL;
    return nodo;
};
Lista crearLista(){
    Lista lista= (Lista)malloc(sizeof(struct ListaE));
    lista->primero= NULL;

    return lista;
};

Nodo destruirNodo(Nodo nodo){
    free(nodo);
    return NULL;
};
Lista destruirLista(Lista lista){
    free(lista);
    return lista;
};
int listaVacia(Lista lista){
    return (lista->primero==NULL);
}

void* getDato(Nodo nodo){
    return nodo->dato;
};
Nodo getSiguiente(Nodo nodo){
    return nodo->siguiente;
};
Nodo getPrimero(Lista lista){
    return lista->primero;
};
Nodo obtenerUltimo(Lista lista){
     Nodo ultimo= lista->primero;
    while(ultimo->siguiente!=NULL){
        ultimo= ultimo->siguiente;
    }
    return ultimo;
};
Nodo obtenerPrimero(Lista lista){
    return lista->primero;
};
Nodo obtenerNodoParametro(Lista lista, int longitud){
     Nodo ultimo= lista->primero;
     int posicionActual=0;

    if(ultimo!=NULL){

        while(posicionActual<longitud && ultimo->siguiente!=NULL){
            posicionActual++;
            ultimo=ultimo->siguiente;
        }
    }
    return ultimo;
};
int obtenerTamanio(Lista lista){
     int tam= 0;
      Nodo ultimo= lista->primero;
        while(ultimo!=NULL){
            ultimo= ultimo->siguiente;
            tam++;
        }
        return tam;
};


void setDato(Nodo nodo,void* datoNuevo){
    nodo->dato=datoNuevo;
};
void setSiguiente(Nodo nodo, Nodo siguiente){
    nodo->siguiente= siguiente;
};
void setPrimero(Lista lista,Nodo nodo){
    lista->primero= nodo;
};

void insertarPrimero(Lista lista,void* dato){
    Nodo nuevo = crearNodo(dato);

    if(listaVacia(lista)){
        nuevo->siguiente=NULL;
        lista->primero = nuevo;

    }else{
        Nodo aux = lista->primero;

        nuevo->siguiente= aux;
        lista->primero= nuevo;

    }

};
void insertarUltimo(Lista lista, void* dato){
    Nodo nuevo= crearNodo(dato);
    if(listaVacia(lista)){
        insertarPrimero(lista,dato);
    }
    Nodo ultimo= obtenerUltimo(lista);

    nuevo->siguiente = ultimo->siguiente;
    ultimo->siguiente = nuevo;
};
void insertar(Lista lista,void* dato, int posicionInsertar){

    Nodo nuevo= crearNodo(dato);
    if(obtenerTamanio(lista)==0 || posicionInsertar == 0){
        insertarPrimero(lista,dato);
    }else{

        Nodo ultimo= obtenerNodoParametro(lista, posicionInsertar-1);

        if(ultimo!= NULL){
            nuevo->siguiente = ultimo->siguiente;
            ultimo->siguiente = nuevo;
        }
    }
};

Lista duplicarLista(Lista original){
    Lista duplicada= crearLista();

    if(listaVacia(original)){
        return NULL;
    }
    Nodo actual= original->primero;

    for( int i=0; i<obtenerTamanio(original); i++ ){
        void* dato = getDato(obtenerNodoParametro(original,i));

        if(i==0){

            insertarPrimero(duplicada,dato);
        }else{

            insertarUltimo(duplicada,dato);
        }

    }
    return duplicada;
};



