#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadios.h"
#include "Lista.h"

void mostrarEstadiosLista(Lista lista){
    for(int i=0; i<obtenerTamanio(lista);i++){
        Estadio estadio= *(Estadio*)obtenerNodoParametro(lista,i);
        mostrarEstadio(estadio);
    }
    printf("\n");
}

int main()
{
    Estadio estadio1 =crearEstadio("Khalifa",40000,"Doha");
    Estadio estadio2 =crearEstadio("Al Bayt",60000,"Doha");
    Estadio estadio3 =crearEstadio("Al Jonoub",5000,"Doha");
    Estadio estadio4 =crearEstadio("Florencio Sola",34000,"Doha");
/*
    mostrarEstadio(estadio1);
    mostrarEstadio(estadio2);
    mostrarEstadio(estadio3);
    mostrarEstadio(estadio4);*/


    /*
        printf("\n null? %d",estadio1!=NULL); //si es falso 0 si es true 1
        printf("\n null? %d\n Un elemento de la Lista: \n ",estadio1==NULL); //si es falso 0 si es true 1
    */

    Lista listaEstadios = crearLista();
    insertarPrimero(listaEstadios,estadio1);
    insertarPrimero(listaEstadios,estadio2);
    //insertarPrimero(listaEstadios,estadio1);
    insertarPrimero(listaEstadios,estadio3);
    insertarPrimero(listaEstadios,estadio4);
    ordenarLista(listaEstadios);

    printf("\n\n Lista original: \n\n ");
    mostrarEstadiosLista(listaEstadios);


    /*
        printf("\n\n Listas duplicadas: \n\n ");
        Lista listaEstadiosDuplicada = duplicarLista(listaEstadios);
        //mostrarEstadiosLista(listaEstadiosDuplicada);
    */

    //printf("\n Lista duplicada ordenada: \n ");
    //ordenarLista(listaEstadiosDuplicada);
    //mostrarEstadiosLista(listaEstadiosDuplicada);

    printf("\n\n Lista insertado primero: \n\n ");
    Estadio estadio5 = crearEstadio("A",47000,"Lanus");
    insertarOrdenado(listaEstadios, estadio5);
    mostrarEstadiosLista(listaEstadios);

    printf("\n\n Lista insertado ultimo: \n\n ");
    Estadio estadio6 = crearEstadio("Zair Josedolfo Perez Sancho",47000,"Lanus");
    insertarOrdenado(listaEstadios, estadio6);
    mostrarEstadiosLista(listaEstadios);

    printf("\n\n Lista insertado ultimo: \n\n ");
    Estadio estadio7 = crearEstadio("Carlitos Tevez",47000,"Lanus");
    insertarOrdenado(listaEstadios, estadio7);
    mostrarEstadiosLista(listaEstadios);

    return 0;
}
