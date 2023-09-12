#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

#include "Lista.h"
#include "Estudiante.h"

struct MateriaE;

typedef struct MateriaE* MateriaPtr;

MateriaPtr crearMateria(char* nombreNuevo, int codigoNuevo, char turnoNuevo, ListaPtr listaEstudiantesNuevo);

void destruirMateria(MateriaPtr materiaDestuir);

void setnombre(MateriaPtr materiaActual, char* nombreNuevo);

void setCodigoMateria(MateriaPtr materiaActual, int codigoNuevo);

void setTurnoMateria(MateriaPtr materiaActual, char turnoNuevo);

void setListaEstudiantesMateria(MateriaPtr materiaActual, ListaPtr listaEstudiantesNueva);

char* getNombreMateria(MateriaPtr materiaActual);

int getCodigoMateria(MateriaPtr materiaActual);

char getTurnoMateria(MateriaPtr materiaActual);

ListaPtr getListaEstudiantes(MateriaPtr materiaActual);

void insertarEstudianteMateria(MateriaPtr materiaActual, EstudiantePtr estudianteInsertar, int posicionInsertar);

EstudiantePtr getEstudianteMateria(MateriaPtr materiaActual, int posicion);

void mostrarListaEstudiantesMateria(MateriaPtr materiaActual);

void mostrarMateria(MateriaPtr materiaActual);

MateriaPtr cargarMateriaManual();

MateriaPtr materiaPredeterminada();

void ordenarEstudiantesNombreMateria(MateriaPtr materiaOrdenar);

void ordenarEstudiantesApellidoMateria(MateriaPtr materiaOrdenar);

void ordenarEstudiantesLegajoMateria(MateriaPtr materiaOrdenar);

void ordenarEstudiantesPromedioMateria(MateriaPtr materiaOrdenar);



#endif // MATERIA_H_INCLUDED
