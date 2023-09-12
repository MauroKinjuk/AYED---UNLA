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

typedef CartonEstructura* Carton;

Carton crearCarton(int fechaEmi, int fechaJuego, char direccion[20], Persona persona);
void generarCarton(Carton c);
void generarCartonUser(Carton c);
void jugada(Carton c);
void mostrarCarton(const Carton c);

Carton crearCarton(int fechaEmi, int fechaJuego, char direccion[20], Persona persona) {
    Carton c = new CartonEstructura;
    int modo = 0;
    std::cout << "Como deseas jugar?" << std::endl;
    std::cout << "1 - Modo automatico" << std::endl;
    std::cout << "2 - Modo manual (Eligiendo los numeros)" << std::endl;
    std::cout << "Escribe un numero: ";
    std::cin >> modo;

    switch (modo) {
        case 1:
            generarCarton(c);
            break;
        case 2:
            generarCartonUser(c);
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            break;
    }

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

void generarCartonUser(Carton c) {
    for (int i = 0; i < 8; i++) {
        std::cout << "Ingrese el numero " << i << ": ";
        std::cin >> c->numeros[i];
    }

    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (c->numeros[i] > c->numeros[j]) {
                int temp = c->numeros[i];
                c->numeros[i] = c->numeros[j];
                c->numeros[j] = temp;
            }
        }
    }
}

void jugada(Carton c) {
    int coincidencias = 0;

    for (int i = 0; i < 20; i++) {
        int numero = rand() % 100;
        c->numerosGenerados[i] = numero;
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 8; j++) {
            if (c->numeros[j] == c->numerosGenerados[i]) {
                c->numerosAcertados[j] = c->numerosGenerados[j];
                coincidencias++;
                break;
            } else {
                c->numerosAcertados[j] = 0;
            }
        }
    }

    c->coincidencias = coincidencias;
}

void mostrarCarton(const Carton c) {
    system("cls");
    std::cout << "========== Carton INFO ==========" << std::endl;
    std::cout << "La direccion del carton es: " << c->direccion << std::endl;
    std::cout << "Fecha de emision: " << c->fechaEmi << std::endl;
    std::cout << "Fecha de juego: " << c->fechaJuego << std::endl;

    std::cout << "Han salido los siguientes numeros en el carton: " << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << " " << c->numerosGenerados[i];
    }
    std::cout << " " << std::endl;

    mostrarPersona(c->persona);

    std::cout << " " << std::endl;

    std::cout << "========== Jugada INFO ==========" << std::endl;

    std::cout << "Numeros seleccionados: " << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << " " << c->numeros[i];
    }

    std::cout << "" << std::endl;

    if (c->coincidencias >= 1) {
        std::cout << "Numeros que has acertado: " << std::endl;
        for (int i = 0; i < 8; i++) {
            if (c->numerosAcertados[i] > 0) {
                std::cout << " " << c->numerosAcertados[i];
            }
        }
        std::cout << std::endl;
    }

    int aciertos = c->coincidencias;

    switch (aciertos) {
        case 5:
            std::cout << "Ganaste $50, ya que acertaste: " << c->coincidencias << " numeros!" << std::endl;
            break;
        case 6:
            std::cout << "Ganaste $500, ya que acertaste: " << c->coincidencias << " numeros!" << std::endl;
            break;
        case 7:
            std::cout << "Ganaste $20.000, ya que acertaste: " << c->coincidencias << " numeros!" << std::endl;
            break;
        case 8:
            std::cout << "Ganaste $11.000.0000, ya que acertaste: " << c->coincidencias << " numeros!" << std::endl;
            break;
        default:
            std::cout << "No ganaste nada, suerte la proxima." << std::endl;
            break;
    }
}
