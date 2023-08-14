#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


struct PersonaEstructura;

typedef struct PersonaEstructura * Persona;

Persona crearPersona(int dni, char nombre[20]);

void mostrarPersona(Persona p);


#endif // PERSONA_H_INCLUDED
