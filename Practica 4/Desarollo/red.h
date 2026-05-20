#ifndef RED_H
#define RED_H

#include <vector>
#include <string>
#include "enrutador.h"

struct Enlace {
    std::string origen;
    std::string destino;
    int costo;
};


class Red {
public:
    std::vector<Enrutador> enrutadores;
    std::vector<Enlace> conexiones;

    Red();

    // Funciones para manejar archivos
    void cargarDatos();
    void guardarDatos();

    // Funciones básicas
    void agregarEnrutador(std::string nombre);
    void agregarConexion(std::string origen, std::string destino, int costo);
    void eliminarConexion(std::string origen, std::string destino);

    // Funciones de búsqueda
    bool existeEnrutador(std::string nombre);
};
#endif // RED_H
