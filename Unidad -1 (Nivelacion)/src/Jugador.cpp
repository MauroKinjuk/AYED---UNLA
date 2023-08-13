#include <iostream>
#include <cstring>
#include "Jugador.h"

struct JugadorEstructura{
    int dni;
    char nombre[20];
};


Jugador crearJugador(){
    Jugador p = new JugadorEstructura;

    //Pido el dni
    std::cout << "Ingrese el dni: ";
    std:: cin >> p->dni;

    std:: cout << "Ingrese su nombre: ";
    std:: cin >> p->nombre;

    return p;
};

Jugador mostrarJugador(Jugador p){
    std::cout << "DNI: " << p->dni << std::endl;
    std::cout << "Nombre: " << p->nombre << std::endl;
};