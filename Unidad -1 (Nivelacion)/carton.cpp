#include <iostream>
#include <cstring>
#include <ctime>
#include "carton.h"

struct CartonEstructura {
    int fechaEmi;
    int fechaJuego;
    char direccion[20];
    int numerosGenerados[20];
    int numerosAcertados[8];
    int numeros[8];
    int coincidencias;
    Persona persona;
};

Carton crearCarton(int fechaEmi, int fechaJuego, char direccion[20], Persona persona) {
    Carton c = new CartonEstructura;

    generarCarton(c);

    c->fechaEmi = fechaEmi;
    c->fechaJuego = fechaJuego;
    strcpy(c->direccion, direccion);
    c->persona = persona;

    jugada(c);

    return c;
}

void generarCarton(Carton c) {

    bool numerosUsados[100] = {false};

    for (int i = 0; i < 8; i++) {
        int numero;
        do {
            numero = rand() % 100;
        } while (numerosUsados[numero]);

        c->numeros[i] = numero;
        numerosUsados[numero] = true;
    }

    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (c->numeros[j] < c->numeros[i]) {
                int temp = c->numeros[i];
                c->numeros[i] = c->numeros[j];
                c->numeros[j] = temp;
            }
        }
    }
}

void jugada(Carton c){

    int numerosGenerados[20];
    int coincidencias = 0;

    //Genero los 20 numeros
    for(int i=0; i < 20 ; i++){
        int numero = rand()%100;
        numerosGenerados[i] = numero;
        c->numerosGenerados[i] = numero;
    }

    //Voy a contar las coincidencias
    for(int i = 0; i < 20 ; i++){
        for(int j = 0; j < 8; j++){
            if(c->numeros[j] == numerosGenerados[i]){
                coincidencias++;
                c->numerosAcertados[j] = c->numerosGenerados[i];
                break;
            }
        }
    }

    c->coincidencias = coincidencias;
}

void mostrarCarton(const Carton c) {
    std::cout << "========== Carton ==========" << std::endl;
    std::cout << "La direccion del carton es: " << c->direccion << std::endl;
    std::cout << "Fecha de emision: " << c->fechaEmi << std::endl;
    std::cout << "Fecha de juego: " << c->fechaJuego << std::endl;

    std::cout << "Numeros seleccionados: " << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << " " << c->numeros[i];
    }

    std::cout <<""<< std::endl;

    std::cout<< "Han salido los siguientes numeros en el carton: " <<std::endl;
    for(int i = 0; i < 20; i++){
        std::cout<<" "<<c->numerosGenerados[i];
    }
    std::cout <<""<< std::endl;

    std::cout<< "Haz acertado el/los numeros: " <<std::endl;
    for(int i=0; i <8; i++){
        if(c->numerosAcertados[i] > 0){
            std::cout << " " << c->numerosAcertados[i];
        }
    }

    int aciertos = c->coincidencias;

    switch (aciertos){
        case 5:
            std::cout << "Ganaste $50, ya que acertaste: " <<c->coincidencias <<" numeros!" << std::endl;
            break;
        case 6:
            std::cout << "Ganaste $500, ya que acertaste: " <<c->coincidencias <<" numeros!" << std::endl;
            break;
        case 7:
            std::cout << "Ganaste $20.000, ya que acertaste: " <<c->coincidencias <<" numeros!" << std::endl;
            break;
        case 8:
            std::cout << "Ganaste $11.000.0000, ya que acertaste: " <<c->coincidencias <<" numeros!" << std::endl;
            break;
        default:
            std::cout << "No ganaste nada, suerte la proxima. Haz acertado: " << c->coincidencias << std::endl;
            break;
    }
}
