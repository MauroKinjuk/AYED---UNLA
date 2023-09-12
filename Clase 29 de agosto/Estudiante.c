#include "Estudiante.h"


struct EstudianteE
{
    char* nombre;
    char* apellido;
    int legajo;
    float promedio;
};

EstudiantePtr crearEstudiante(char* nombreNuevo, char* apellidoNuevo, int legajoNuevo, float promedioNuevo)
{
    EstudiantePtr estudianteNuevo = (EstudiantePtr)malloc(sizeof(struct EstudianteE));
    estudianteNuevo->nombre = crearStringDinamico(nombreNuevo);
    estudianteNuevo->apellido = crearStringDinamico(apellidoNuevo);
    estudianteNuevo->legajo = legajoNuevo;
    estudianteNuevo->promedio = promedioNuevo;
    return estudianteNuevo;
}

void destruirEstudiante(EstudiantePtr estudianteDestruir)
{
    destruirStringDinamico(estudianteDestruir->nombre);
    destruirStringDinamico(estudianteDestruir->apellido);
    free(estudianteDestruir);
    estudianteDestruir = NULL;
}

void setNombreEstudiante(EstudiantePtr estudianteActual, char* nombreNuevo)
{
    destruirStringDinamico(estudianteActual->nombre);
    estudianteActual->nombre = crearStringDinamico(nombreNuevo);
}

void setApellidoEstudiante(EstudiantePtr estudianteActual, char* apellidoNuevo)
{
    destruirStringDinamico(estudianteActual->apellido);
    estudianteActual->apellido = crearStringDinamico(apellidoNuevo);
}

void setLegajoEstudiante(EstudiantePtr estudianteActual, int legajoNuevo)
{
    estudianteActual->legajo = legajoNuevo;
}

void setPromedioEstudiante(EstudiantePtr estudianteActual, float promedioNuevo)
{
    estudianteActual->promedio = promedioNuevo;
}

char* getNombreEstudiante(EstudiantePtr estudianteActual)
{
    return estudianteActual->nombre;
}

char* getApellidoEstudiante(EstudiantePtr estudianteActual)
{
    return estudianteActual->apellido;
}

int getLegajoEstudiante(EstudiantePtr estudianteActual)
{
    return estudianteActual->legajo;
}

float getPromedioEstudiante(EstudiantePtr estudianteActual)
{
    return estudianteActual->promedio;
}

void mostrarEstudiante(EstudiantePtr estudianteActual)
{
    printf("Nombre: %s\n", getNombreEstudiante(estudianteActual));
    printf("Apellido: %s\n", getApellidoEstudiante(estudianteActual));
    printf("Legajo: %d\n", getLegajoEstudiante(estudianteActual));
    printf("Promedio: %.2f\n\n", getPromedioEstudiante(estudianteActual));
}

EstudiantePtr cargarEstudianteManual()
{
    EstudiantePtr estudianteCargar;
    char nombreCargar[20];
    char apellidoCargar[20];
    int legajoCargar;
    float promedioCargar;

    printf("Nombre: ");
    scanf("%[^\n]%*c", nombreCargar);

    printf("Apellido: ");
    scanf("%[^\n]%*c", apellidoCargar);

    printf("Legajo: ");
    scanf("%d", &legajoCargar);

    printf("Promedio: ");
    scanf("%f", &promedioCargar);

    estudianteCargar = crearEstudiante(nombreCargar, apellidoCargar, legajoCargar, promedioCargar);
    return estudianteCargar;
}

