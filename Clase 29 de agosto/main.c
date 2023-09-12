#include "Materia.h"
#include "Archivos.h"

int main()
{
    printf("\n\n\nARCHIVOS ANTES DE GUARDARLOS\n\n\n");
    MateriaPtr materia = materiaPredeterminada();
    ordenarEstudiantesNombreMateria(materia);
    //ordenarEstudiantesApellidoMateria(materia);
    //ordenarEstudiantesLegajoMateria(materia);
    //ordenarEstudiantesPromedioMateria(materia);
    guardarDatos(materia);
    mostrarMateria(materia);

    printf("\n\n\nARCHIVOS DESPUES DE LEERLOS\n\n\n");
    MateriaPtr materiaLeer = NULL;
    materiaLeer = leerDatos();
    mostrarMateria(materiaLeer);
    return 0;
}
