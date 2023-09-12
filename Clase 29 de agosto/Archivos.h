#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

struct EstudianteEstaticoE;

typedef struct EstudianteEstaticoE* EstudianteEstaticoPtr;

struct MateriaEstaticaE;

typedef struct MateriaEstaticaE* MateriaEstaticaPtr;

void guardarDatos(MateriaPtr materiaDinamicaGuardar);

MateriaPtr leerDatos();

#endif // ARCHIVOS_H_INCLUDED
