#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#include "persona.h"

struct CartonEstructura;

typedef struct CartonEstructura * Carton;

Carton crearCarton(int fechaEmi, int fechaJuego, char direccion[20], Persona persona);

void generarCarton(Carton c);
void jugada(Carton c);
void mostrarCarton(Carton c);



#endif // CARTON_H_ICLUDED
