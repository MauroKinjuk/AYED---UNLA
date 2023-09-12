#include <iostream>
#include <cstring>
#include <time.h>
#include <windows.h>
#include "persona.h"
#include "carton.h"


int main()
{
    srand(time(NULL));
    char nombre[20];
    char direccion[20];
    int dni;
    std::cout <<"======== Quieniela Plus ========" << std:: endl;
    std::cout << "Escriba su nombre: ";
    std::cin.getline(nombre, sizeof(nombre));
    std::cout << "Escriba su dni: ";
        std::cin >> dni;
    system("cls");

    Persona p1 = crearPersona(dni, nombre);

    Carton miCarton = crearCarton(20230812, 20230815, "Calle Falsa 123", p1);
    mostrarCarton(miCarton);

    return 0;
}
