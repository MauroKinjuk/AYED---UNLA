#include "Materia.h"
#include "Archivos.h"

struct EstudianteEstaticoE
{
    char nombre[20];
    char apellido[20];
    int legajo;
    float promedio;
};

struct MateriaEstaticaE
{
    char nombre[20];
    int codigo;
    char turno;
    struct EstudianteEstaticoE listaEstudiantes[20];
    int cantidadEstudiantes;
};

void transferirEstudianteDinamicoEstudianteEstatico(EstudiantePtr estudianteDinamico, EstudianteEstaticoPtr estudianteEstatico);

EstudiantePtr transferirEstudianteEstaticoEstudianteDinamico(EstudianteEstaticoPtr estudianteEstatico);

void transferirMateriaDinamicaMateriaEstatica(MateriaPtr materiaDinamica, MateriaEstaticaPtr materiaEstatica);

MateriaPtr transferirMateriaEstaticaMateriaDinamcia(MateriaEstaticaPtr materiaEstatica);

void transferirEstudianteDinamicoEstudianteEstatico(EstudiantePtr estudianteDinamico, EstudianteEstaticoPtr estudianteEstatico)
{
    strcpy(estudianteEstatico->nombre, getNombreEstudiante(estudianteDinamico));
    strcpy(estudianteEstatico->apellido, getApellidoEstudiante(estudianteDinamico));
    estudianteEstatico->legajo = getLegajoEstudiante(estudianteDinamico);
    estudianteEstatico->promedio = getPromedioEstudiante(estudianteDinamico);
}

EstudiantePtr transferirEstudianteEstaticoEstudianteDinamico(EstudianteEstaticoPtr estudianteEstatico)
{
    char nombreCargar[20];
    char apellidoCargar[20];
    int legajoCargar;
    float promedioCargar;

    strcpy(nombreCargar, estudianteEstatico->nombre);
    strcpy(apellidoCargar, estudianteEstatico->apellido);
    legajoCargar = estudianteEstatico->legajo;
    promedioCargar = estudianteEstatico->promedio;

    EstudiantePtr estudianteDinamico = crearEstudiante(nombreCargar, apellidoCargar, legajoCargar, promedioCargar);
    return estudianteDinamico;
}

void transferirMateriaDinamicaMateriaEstatica(MateriaPtr materiaDinamica, MateriaEstaticaPtr materiaEstatica)
{
    strcpy(materiaEstatica->nombre, getNombreMateria(materiaDinamica));
    materiaEstatica->codigo = getCodigoMateria(materiaDinamica);
    materiaEstatica->turno = getTurnoMateria(materiaDinamica);
    int cantidadEstudiantes = 0;
    ListaPtr listaAuxiliar = getListaEstudiantes(materiaDinamica);
    NodoPtr nodoActual = getNodoPrimero(listaAuxiliar);
    while(nodoActual != NULL)
    {
        EstudiantePtr estudianteDinamico = (EstudiantePtr)getDato(nodoActual);
        transferirEstudianteDinamicoEstudianteEstatico(estudianteDinamico, &(materiaEstatica->listaEstudiantes[cantidadEstudiantes]));
        cantidadEstudiantes++;
        nodoActual = getSiguiente(nodoActual);
    }
    materiaEstatica->cantidadEstudiantes = cantidadEstudiantes;
}

MateriaPtr transferirMateriaEstaticaMateriaDinamcia(MateriaEstaticaPtr materiaEstatica)
{
    char nombreCargar[20];
    int codigoCargar;
    char turnoCargar;
    ListaPtr listaEstudiantesCargar = crearLista();

    strcpy(nombreCargar, materiaEstatica->nombre);
    codigoCargar = materiaEstatica->codigo;
    turnoCargar = materiaEstatica->turno;
    for(int i = 0 ; i < materiaEstatica->cantidadEstudiantes ; i++)
    {
        EstudiantePtr estudianteDinamico = transferirEstudianteEstaticoEstudianteDinamico(&(materiaEstatica->listaEstudiantes[i]));
        insertarDatoLista(listaEstudiantesCargar, (EstudiantePtr)estudianteDinamico, longitudLista(listaEstudiantesCargar));
    }
    MateriaPtr materiaDinamica = crearMateria(nombreCargar, codigoCargar, turnoCargar, listaEstudiantesCargar);
    return materiaDinamica;
}

void guardarDatos(MateriaPtr materiaDinamicaGuardar)
{
    FILE* archivo;
    archivo = fopen("Materia.txt", "wb");
    if(archivo == NULL)
    {
        exit(1);
    }
    struct MateriaEstaticaE materiaEstaticaGuardar;
    transferirMateriaDinamicaMateriaEstatica(materiaDinamicaGuardar, &materiaEstaticaGuardar);
    fprintf(archivo, "%s %d %c %d \n", materiaEstaticaGuardar.nombre, materiaEstaticaGuardar.codigo, materiaEstaticaGuardar.turno, materiaEstaticaGuardar.cantidadEstudiantes);
    for(int i = 0 ; i < materiaEstaticaGuardar.cantidadEstudiantes ; i++)
    {
        fprintf(archivo, "%s %s %d %f \n", materiaEstaticaGuardar.listaEstudiantes[i].nombre, materiaEstaticaGuardar.listaEstudiantes[i].apellido, materiaEstaticaGuardar.listaEstudiantes[i].legajo, materiaEstaticaGuardar.listaEstudiantes[i].promedio);
    }
    fclose(archivo);
}

MateriaPtr leerDatos()
{
    FILE* archivo;
    archivo = fopen("Materia.txt", "rb");
    if(archivo == NULL)
    {
        exit(1);
    }
    struct MateriaEstaticaE materiaEstaticaLeer;
    fscanf(archivo, "%s %d %c %d \n", materiaEstaticaLeer.nombre, &(materiaEstaticaLeer.codigo), &(materiaEstaticaLeer.turno), &(materiaEstaticaLeer.cantidadEstudiantes));
    for(int i = 0 ; i < materiaEstaticaLeer.cantidadEstudiantes ; i++)
    {
        fscanf(archivo, "%s %s %d %f \n", materiaEstaticaLeer.listaEstudiantes[i].nombre, materiaEstaticaLeer.listaEstudiantes[i].apellido, &(materiaEstaticaLeer.listaEstudiantes[i].legajo), &(materiaEstaticaLeer.listaEstudiantes[i].promedio));
    }
    fclose(archivo);

    MateriaPtr materiaDinamicaLeer = transferirMateriaEstaticaMateriaDinamcia(&materiaEstaticaLeer);
    return materiaDinamicaLeer;
}
