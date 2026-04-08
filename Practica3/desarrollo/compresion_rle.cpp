#include "compresion_rle.h"
#include <fstream>
#include <iostream>

using namespace std;

void compresion_rle() {
  char *archivo_entrada = new char[256];
  char *archivo_salida = new char[256];

  cout << "Por favor, ingrese la ruta del archivo: ";
  cin.ignore();
  cin.getline(archivo_entrada, 256);

  cout << "Por favor, ingrese la ruta del archivo de salida: ";
  cin.getline(archivo_salida, 256);

  ifstream archivo_in(archivo_entrada, ios::binary);
  ofstream archivo_out(archivo_salida, ios::binary);

  if (!archivo_in.is_open()) {
    cout << "Error al abrir el archivo de entrada" << endl;
    return;
  }

  if (!archivo_out.is_open()) {
    cout << "Error al abrir el archivo de salida" << endl;
    return;
  }

  // Usamos memoria dinamica porque no sabemos el tamaño de los archivos
  char *contenido = new char[100000];
  int n = 0;
  char letra;

  // Leer el archivo letra por letra
  while (archivo_in.get(letra)) {
    contenido[n] = letra;
    n++;
  }

  cout << "Tamaño en bytes: " << n << endl
       << "Caracteres leidos: " << n << endl;

  // Recorrer el arreglo para comprimir
  for (int i = 0; i < n; i++) {
    int count = 1;
    // Mirar las siguientes letras para ver si son iguales
    while (i + 1 < n && contenido[i] == contenido[i + 1]) {
      count++;
      i++;
    }

    // Si es un salto de línea, lo ponemos las veces que aparezca, pero sin
    // número
    if (contenido[i] == '\n' || contenido[i] == '\r') {
      for (int j = 0; j < count; j++) {
        archivo_out << contenido[i];
      }
    } else {
      // Escribimos directo al archivo
      archivo_out << count << contenido[i];
    }
  }

  delete[] contenido;
  cout << "Compresión completada." << endl;
  delete[] archivo_entrada;
  delete[] archivo_salida;
}