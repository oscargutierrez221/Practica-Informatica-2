#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <string>

class Enrutador {
public:
    std::string nombre;

    // Constructor vacio
    // Enrutador() {}

    // Constructor con nombre
    Enrutador(std::string n) {
        nombre = n;
    }
};
#endif // ENRUTADOR_H
