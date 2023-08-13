#include <iostream>
#include <cstring>
#include "Carton.h"
#include "Jugador.h"

//El cartón tiene la fecha de emisión, la fecha de juego ( un domingo)* y la dirección de la agencia que vendió el cartón
//El carton tambien recibe un Jugador
struct CartonEstructura{
    int fechaEmision;
    int fechaJuego;
    char direccionAgencia[20];
    Jugador jugador;
};

Carton crearCarton(int fechaEmision, int fechaJuego, Jugador jugador){
    Carton c = new CartonEstructura;

    std:: cout << "Ingrese la direccion de la agencia: " << std::endl;
    std:: cin >> c->direccionAgencia;
    c->fechaEmision = fechaEmision;
    c->fechaJuego = fechaJuego;
    c->jugador = jugador;

    return c;
};

//mostrar Carton
Carton mostrarCarton(Carton c){
    std::cout << "Fecha de emision: " << c->fechaEmision << std::endl;
    std::cout << "Fecha de juego: " << c->fechaJuego << std::endl;
    std::cout << "Direccion de agencia: " << c->direccionAgencia << std::endl;
    mostrarJugador(c->jugador);
};