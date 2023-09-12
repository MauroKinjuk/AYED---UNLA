#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#include "Util.h"

struct EstudianteE;

typedef struct EstudianteE* EstudiantePtr;

EstudiantePtr crearEstudiante(char* nombreNuevo, char* apellidoNuevo, int legajoNuevo, float promedioNuevo);

void destruirEstudiante(EstudiantePtr estudianteDestruir);

void setNombreEstudiante(EstudiantePtr estudianteActual, char* nombreNuevo);

void setApellidoEstudiante(EstudiantePtr estudianteActual, char* apellidoNuevo);

void setLegajoEstudiante(EstudiantePtr estudianteActual, int legajoNuevo);

void setPromedioEstudiante(EstudiantePtr estudianteActual, float promedioNuevo);

char* getNombreEstudiante(EstudiantePtr estudianteActual);

char* getApellidoEstudiante(EstudiantePtr estudianteActual);

int getLegajoEstudiante(EstudiantePtr estudianteActual);

float getPromedioEstudiante(EstudiantePtr estudianteActual);

void mostrarEstudiante(EstudiantePtr estudianteActual);

EstudiantePtr cargarEstudianteManual();

#endif // ESTUDIANTE_H_INCLUDED
