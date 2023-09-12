#include "Materia.h"

struct MateriaE
{
    char* nombre;
    int codigo;
    char turno;
    ListaPtr listaEstudiantes;
};

MateriaPtr crearMateria(char* nombreNuevo, int codigoNuevo, char turnoNuevo, ListaPtr listaEstudiantesNuevo)
{
    MateriaPtr materiaNueva = (MateriaPtr)malloc(sizeof(struct MateriaE));
    materiaNueva->nombre = crearStringDinamico(nombreNuevo);
    materiaNueva->codigo = codigoNuevo;
    materiaNueva->turno = turnoNuevo;
    materiaNueva->listaEstudiantes = listaEstudiantesNuevo;
    return materiaNueva;
}

void destruirMateria(MateriaPtr materiaDestuir)
{
    destruirStringDinamico(materiaDestuir->nombre);
    destruirLista(materiaDestuir->listaEstudiantes);
    free(materiaDestuir);
    materiaDestuir = NULL;
}

void setnombre(MateriaPtr materiaActual, char* nombreNuevo)
{
    destruirStringDinamico(materiaActual->nombre);
    materiaActual->nombre = crearStringDinamico(nombreNuevo);
}

void setCodigoMateria(MateriaPtr materiaActual, int codigoNuevo)
{
    materiaActual->codigo = codigoNuevo;
}

void setTurnoMateria(MateriaPtr materiaActual, char turnoNuevo)
{
    materiaActual->turno = turnoNuevo;
}

void setListaEstudiantesMateria(MateriaPtr materiaActual, ListaPtr listaEstudiantesNueva)
{
    materiaActual->listaEstudiantes = listaEstudiantesNueva;
}

char* getNombreMateria(MateriaPtr materiaActual)
{
    return materiaActual->nombre;
}

int getCodigoMateria(MateriaPtr materiaActual)
{
    return materiaActual->codigo;
}

char getTurnoMateria(MateriaPtr materiaActual)
{
    return materiaActual->turno;
}

ListaPtr getListaEstudiantes(MateriaPtr materiaActual)
{
    return materiaActual->listaEstudiantes;
}

void insertarEstudianteMateria(MateriaPtr materiaActual, EstudiantePtr estudianteInsertar, int posicionInsertar)
{
    insertarDatoLista(getListaEstudiantes(materiaActual), (EstudiantePtr)estudianteInsertar, posicionInsertar);
}

EstudiantePtr getEstudianteMateria(MateriaPtr materiaActual, int posicion)
{
    return (EstudiantePtr)getDatoLista(getListaEstudiantes(materiaActual), posicion);
}

void mostrarListaEstudiantesMateria(MateriaPtr materiaActual)
{
    ListaPtr listaAuxiliar = getListaEstudiantes(materiaActual);
    if(listaVacia(listaAuxiliar))
    {
        return;
    }
    NodoPtr nodoActual = getNodoPrimero(listaAuxiliar);
    while(nodoActual != NULL)
    {
        EstudiantePtr estudianteMostrar = (EstudiantePtr)getDato(nodoActual);
        mostrarEstudiante(estudianteMostrar);
        nodoActual = getSiguiente(nodoActual);
    }
}

void mostrarMateria(MateriaPtr materiaActual)
{
    printf("\nMateria");
    printf("\n\nNombre: %s\n", getNombreMateria(materiaActual));
    printf("Codigo: %d\n", getCodigoMateria(materiaActual));
    switch(getTurnoMateria(materiaActual))
    {
        case 'm':
            printf("Turno: Maniana\n");
            break;
        case 'M':
            printf("Turno: Maniana\n");
            break;
        case 't':
            printf("Turno: Tarde\n");
            break;
        case 'T':
            printf("Turno: Tarde\n");
            break;
        case 'n':
            printf("Turno: Noche\n");
            break;
        case 'N':
            printf("Turno: Noche\n");
            break;
        default:
            printf("Turno incorrecto\n");
            break;
    }
    printf("\n\nLista de los estudiantes:\n\n");
    mostrarListaEstudiantesMateria(materiaActual);
}

MateriaPtr cargarMateriaManual()
{
    MateriaPtr materiaCargar;
    char nombreCargar[20];
    int codigoCargar;
    char turnoCargar;
    int cantidadIngresar;
    ListaPtr listaEstudiantesCargar = crearLista();

    printf("Nombre de la materia: ");
    scanf("%[^\n]%*c", nombreCargar);

    printf("Codigo de la materia: ");
    scanf("%d", &codigoCargar);

    printf("Turno de la materia: ");
    scanf("%c", &turnoCargar);

    printf("Cantidad de estudiantes a ingresar: ");
    scanf("%d", &cantidadIngresar);

    for(int i = 0 ; i < cantidadIngresar ; i++)
    {
        EstudiantePtr estudianteCargar = cargarEstudianteManual();
        agregarDatoLista(listaEstudiantesCargar, (EstudiantePtr)estudianteCargar);
    }

    materiaCargar = crearMateria(nombreCargar, codigoCargar, turnoCargar, listaEstudiantesCargar);
    return materiaCargar;
}

MateriaPtr materiaPredeterminada()
{
    ListaPtr listaEstudiantes = crearLista();
    EstudiantePtr estudianteNuevo1 = crearEstudiante("Jorge", "Rodolfo", 123420, 10.4);
    EstudiantePtr estudianteNuevo2 = crearEstudiante("Sancho", "Samurai", 235821, 8.4);
    EstudiantePtr estudianteNuevo3 = crearEstudiante("Adolfo", "Hitler", 123420, 7.4);
    EstudiantePtr estudianteNuevo4 = crearEstudiante("Sandro", "Ramirez", 438245, 9.4);
    EstudiantePtr estudianteNuevo5 = crearEstudiante("Pedro", "Gonzalez", 928521, 5.4);
    agregarDatoLista(listaEstudiantes, (EstudiantePtr)estudianteNuevo1);
    agregarDatoLista(listaEstudiantes, (EstudiantePtr)estudianteNuevo2);
    agregarDatoLista(listaEstudiantes, (EstudiantePtr)estudianteNuevo3);
    agregarDatoLista(listaEstudiantes, (EstudiantePtr)estudianteNuevo4);
    agregarDatoLista(listaEstudiantes, (EstudiantePtr)estudianteNuevo5);
    MateriaPtr materiaPredeterminada = crearMateria("AYED", 192314, 'N', listaEstudiantes);
    return materiaPredeterminada;
}

void ordenarEstudiantesNombreMateria(MateriaPtr materiaOrdenar)
{
    ListaPtr listaAuxiliar = getListaEstudiantes(materiaOrdenar);
    bool cambio = false;
    do
    {
        cambio = false;
        for(int i = 0 ; i < longitudLista(listaAuxiliar)-1 ; i++)
        {
            EstudiantePtr estudiante_1 = (EstudiantePtr)getDatoLista(listaAuxiliar, i);
            EstudiantePtr estudiante_2 = (EstudiantePtr)getDatoLista(listaAuxiliar, i+1);
            int resultado = strcmp(getNombreEstudiante(estudiante_1), getNombreEstudiante(estudiante_2));
            if(resultado >= 1)
            {
                EstudiantePtr estudianteRemover = removerDeLista(listaAuxiliar, i);
                insertarDatoLista(listaAuxiliar, (EstudiantePtr)estudianteRemover, i+1);
                cambio = true;
            }
        }
    }while(cambio);
}

void ordenarEstudiantesApellidoMateria(MateriaPtr materiaOrdenar)
{
    ListaPtr listaAuxiliar = getListaEstudiantes(materiaOrdenar);
    bool cambio = false;
    do
    {
        cambio = false;
        for(int i = 0 ; i < longitudLista(listaAuxiliar)-1 ; i++)
        {
            EstudiantePtr estudiante_1 = (EstudiantePtr)getDatoLista(listaAuxiliar, i);
            EstudiantePtr estudiante_2 = (EstudiantePtr)getDatoLista(listaAuxiliar, i+1);
            int resultado = strcmp(getApellidoEstudiante(estudiante_1), getApellidoEstudiante(estudiante_2));
            if(resultado >= 1)
            {
                EstudiantePtr estudianteRemover = removerDeLista(listaAuxiliar, i);
                insertarDatoLista(listaAuxiliar, (EstudiantePtr)estudianteRemover, i+1);
                cambio = true;
            }
        }
    }while(cambio);
}

void ordenarEstudiantesLegajoMateria(MateriaPtr materiaOrdenar)
{
    ListaPtr listaAuxiliar = getListaEstudiantes(materiaOrdenar);
    bool cambio = false;
    do
    {
        cambio = false;
        for(int i = 0 ; i < longitudLista(listaAuxiliar)-1 ; i++)
        {
            EstudiantePtr estudiante_1 = (EstudiantePtr)getDatoLista(listaAuxiliar, i);
            EstudiantePtr estudiante_2 = (EstudiantePtr)getDatoLista(listaAuxiliar, i+1);
            if(getLegajoEstudiante(estudiante_1) > getLegajoEstudiante(estudiante_2))
            {
                EstudiantePtr estudianteRemover = removerDeLista(listaAuxiliar, i);
                insertarDatoLista(listaAuxiliar, (EstudiantePtr)estudianteRemover, i+1);
                cambio = true;
            }
        }
    }while(cambio);
}

void ordenarEstudiantesPromedioMateria(MateriaPtr materiaOrdenar)
{
    ListaPtr listaAuxiliar = getListaEstudiantes(materiaOrdenar);
    bool cambio = false;
    do
    {
        cambio = false;
        for(int i = 0 ; i < longitudLista(listaAuxiliar)-1 ; i++)
        {
            EstudiantePtr estudiante_1 = (EstudiantePtr)getDatoLista(listaAuxiliar, i);
            EstudiantePtr estudiante_2 = (EstudiantePtr)getDatoLista(listaAuxiliar, i+1);
            if(getPromedioEstudiante(estudiante_1) > getPromedioEstudiante(estudiante_2))
            {
                EstudiantePtr estudianteRemover = removerDeLista(listaAuxiliar, i);
                insertarDatoLista(listaAuxiliar, (EstudiantePtr)estudianteRemover, i+1);
                cambio = true;
            }
        }
    }while(cambio);
}
