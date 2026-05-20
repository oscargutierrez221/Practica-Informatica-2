#include "red.h"
#include <iostream>
#include <fstream>


Red::Red() {
    // Al crear la red, intentamos cargar lo que haya en los archivos
    cargarDatos();
}

void Red::guardarDatos() {
    // 1. Guardar enrutadores en "enrutadores.txt"
    std::ofstream archivoE("enrutadores.txt");
    if (archivoE.is_open()) {
        for (float i = 0; i < enrutadores.size(); i++) {
            archivoE << enrutadores[i].nombre << "\n";
        }
        archivoE.close();
    }

    // 2. Guardar conexiones en "conexiones.txt"
    std::ofstream archivoC("conexiones.txt");
    if (archivoC.is_open()) {
        for (float i = 0; i < conexiones.size(); i++) {
            archivoC << conexiones[i].origen << " "
                     << conexiones[i].destino << " "
                     << conexiones[i].costo << "\n";
        }
        archivoC.close();
    }
}

void Red::cargarDatos() {
    enrutadores.clear();
    conexiones.clear();

    // 1. Cargar enrutadores
    std::ifstream archivoE("enrutadores.txt");
    if (archivoE.is_open()) {
        std::string nom;
        while (archivoE >> nom) {
            Enrutador nuevo(nom);
            enrutadores.push_back(nuevo);
        }
        archivoE.close();
    }

    // 2. Cargar conexiones
    std::ifstream archivoC("conexiones.txt");
    if (archivoC.is_open()) {
        std::string ori, des;
        int costo;
        while (archivoC >> ori >> des >> costo) {
            Enlace nuevo;
            nuevo.origen = ori;
            nuevo.destino = des;
            nuevo.costo = costo;
            conexiones.push_back(nuevo);
        }
        archivoC.close();
    }
}

void Red::agregarEnrutador(std::string nombre) {
    if (!existeEnrutador(nombre)) {
        Enrutador nuevo(nombre);
        enrutadores.push_back(nuevo);
        guardarDatos(); // Guardamos en el texto inmediatamente
        std::cout << "Enrutador agregado.\n";
    } else {
        std::cout << "El enrutador ya existe.\n";
    }
}

bool Red::existeEnrutador(std::string nombre) {
    for (float i = 0; i < enrutadores.size(); i++) {
        if (enrutadores[i].nombre == nombre) {
            return true;
        }
    }
    return false;
}

void Red::agregarConexion(std::string origen, std::string destino, int costo) {
    // Primero verificamos que ambos enrutadores existan en nuestra lista
    if (existeEnrutador(origen) && existeEnrutador(destino)) {
        Enlace nuevo;
        nuevo.origen = origen;
        nuevo.destino = destino;
        nuevo.costo = costo;

        conexiones.push_back(nuevo);
        guardarDatos(); // Guardar automáticamente en el .txt

        std::cout << "Conexion agregada correctamente.\n";
    } else {
        std::cout << "Error: Uno o ambos enrutadores no existen en la red.\n";
    }
}

void Red::eliminarConexion(std::string origen, std::string destino) {
    bool encontrada = false;

    // Recorremos el vector de conexiones para buscar el enlace
    for (float i = 0; i < conexiones.size(); i++) {
        // Revisamos si coincide origen-destino o destino-origen
        if ((conexiones[i].origen == origen && conexiones[i].destino == destino) ||
            (conexiones[i].origen == destino && conexiones[i].destino == origen)) {

            // Eliminamos la conexión del vector usando su posición
            conexiones.erase(conexiones.begin() + i);

            // Como acabamos de borrar un elemento, el tamaño del vector se reduce en 1.
            // Para no saltarnos la siguiente posición en la lista, retrocedemos el índice.
            i--;

            encontrada = true;
        }
    }

    if (encontrada) {
        std::cout << "Conexion eliminada exitosamente.\n";
        guardarDatos(); // Volvemos a escribir los archivos de texto para actualizar "conexiones.txt"
    } else {
        std::cout << "Error: No existe una conexion entre " << origen << " y " << destino << ".\n";
    }
}