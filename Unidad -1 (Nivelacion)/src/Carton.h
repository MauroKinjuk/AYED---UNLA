#ifndef CARTON_H
#define CARTON_H

struct CartonEstructura;

typedef CartonEstructura * Carton;

Carton crearCarton(int fechaEmision, int fechaJuego, Jugador jugador);


#endif