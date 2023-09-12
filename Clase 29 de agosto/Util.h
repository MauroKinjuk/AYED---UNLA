#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/***

    FUNCI�N DE OBTENCI�N DE MEMORIA
    PRECONDICI�N: Debe haber espacio en memoria disponible
    POSTCONDICI�N: Devuelve un puntero a memoria dinamica
    PAR�METROS: tamanio en bytes de la memoria a reservar
    DEVUELVE: puntero a void, casteable a cualquier tipo de dato.

***/
void *obtenerMemoria(size_t tamanio);

/***

    FUNCI�N DE CREACI�N DE STRING DINAMICO
    PRECONDICI�N: debe haber memoria suficiente disponible
    POSTCONDICI�N: Devuelve un puntero a char con la posicion del string reservado en memoria dinamica
    PAR�METROS: una cadena de caracteres representada por medio de un puntero a char
    DEVUELVE: un puntero a char a la primera posicion de la memoria reservada

***/
char *crearStringDinamico(char* literal);

/***

    FUNCI�N DE DESTRUCCI�N DE STRING DINAMICO
    PRECONDICI�N: debe haber sido creado en memoria dinamica para ser destruido con crearStringDinamico
    POSTCONDICI�N: libera la memoria que anteriormente ocupaba esa cadena de caracteres reservada en memoria dinamica
    PAR�METROS: cadena de caracteres representada por medio de un puntero a char
    devuelve NULL

***/
void destruirStringDinamico(char *buffer);

#endif // UTIL_H_INCLUDED
