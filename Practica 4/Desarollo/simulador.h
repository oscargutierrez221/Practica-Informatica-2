#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "red.h"

class Simulador {
public:
    Red miRed; // Aquí instanciamos la red

    Simulador();
    void iniciar();
    void mostrarMenu();
};

#endif // SIMULADOR_H
