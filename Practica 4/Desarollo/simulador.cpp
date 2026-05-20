#include "simulador.h"
#include <iostream>

Simulador::Simulador() {
    // El constructor puede quedar vacío, porque al crear 'miRed'
    // automáticamente llama al constructor de Red() que carga los archivos.
}

void Simulador::iniciar() {
    mostrarMenu();
}

void Simulador::mostrarMenu() {
    int opcion = 0;

    while (opcion != 4) {
        std::cout << "\n--- MENU RED DE ENRUTADORES ---\n";
        std::cout << "1. Agregar Enrutador\n";
        std::cout << "2. Agregar Conexion\n";
        std::cout << "3. Ver Enrutadores y Conexiones\n";
        std::cout << "4. Eliminar Conexion\n";
        std::cout << "5. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string nombre;
            std::cout << "Ingrese nombre del enrutador (ej. A): ";
            std::cin >> nombre;
            miRed.agregarEnrutador(nombre);

        } else if (opcion == 2) {
            std::string origen, destino;
            int costo;
            std::cout << "Enrutador origen: ";
            std::cin >> origen;
            std::cout << "Enrutador destino: ";
            std::cin >> destino;
            std::cout << "Costo del enlace: ";
            std::cin >> costo;
            miRed.agregarConexion(origen, destino, costo);

        } else if (opcion == 3) {
            std::cout << "\n--- ENRUTADORES REGISTRADOS ---\n";
            for (float i = 0; i < miRed.enrutadores.size(); i++) {
                std::cout << "- " << miRed.enrutadores[i].nombre << "\n";
            }

            std::cout << "\n--- CONEXIONES REGISTRADAS ---\n";
            for (float i = 0; i < miRed.conexiones.size(); i++) {
                std::cout << miRed.conexiones[i].origen << " -> "
                          << miRed.conexiones[i].destino << " (Costo: "
                          << miRed.conexiones[i].costo << ")\n";
            }

        } else if (opcion == 4) {
            std::string origen, destino;
            std::cout << "Ingrese el enrutador de origen: ";
            std::cin >> origen;
            std::cout << "Ingrese el enrutador de destino a desconectar: ";
            std::cin >> destino;

            miRed.eliminarConexion(origen, destino);

        } else if (opcion == 5) {
            std::cout << "Saliendo del simulador...\n";

        } else {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}