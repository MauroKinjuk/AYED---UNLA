#include <iostream>
#include "Jugador.h"
#include "Carton.h"

int main(int argc, char const *argv[]) {
    std::cout << "Hola mundo" << std::endl;
    Carton c = crearCarton(1, 2, crearJugador());
    return 0;
}