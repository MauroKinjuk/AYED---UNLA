#include <iostream>
#include <cstring>
#include "persona.h"
#include "carton.h"


int main()
{
    srand(time(NULL));
    char nombre[20];
    char direccion[20];
    int dni;
    std::cout << "Escriba su nombre: ";
    std::cin.getline(nombre, sizeof(nombre));
    std::cout << "Escriba su dni: ";
    std::cin >> dni;

    Persona p1 = crearPersona(dni, nombre);
    mostrarPersona(p1);

    Carton miCarton = crearCarton(20230812, 20230815, "Calle Falsa 123", p1);
    mostrarCarton(miCarton);

    return 0;
}
