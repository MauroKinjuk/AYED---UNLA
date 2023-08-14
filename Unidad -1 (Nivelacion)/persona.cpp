#include <cstring>
#include <iostream>
#include "persona.h"


struct PersonaEstructura{

    int dni;
    char nombre[20];

};

Persona crearPersona(int dni, char nombre[20]){

    Persona p = new PersonaEstructura;

    p->dni = dni;
    strcpy(p->nombre,nombre);

    return p;

};

void mostrarPersona(Persona p){

    std::cout << "========== Persona ==========" << std::endl;
    std::cout << "Nombre: " << p->nombre << std::endl;
    std::cout << "DNI: " << p->dni << std::endl;

};
