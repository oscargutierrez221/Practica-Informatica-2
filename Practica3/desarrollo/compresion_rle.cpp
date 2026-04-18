#include "compresion_rle.h"
#include <fstream>
#include <iostream>

using namespace std;

void compresion_rle() {
  // Ingresar ruta de archivos
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

  // Comprimir

  char *contenido = new char[100000];
  int n = 0;
  char letra;

  // Leer el archivo letra por letra (límite de 100000 para no desbordar el arreglo)
  while (n < 100000 && archivo_in.get(letra)) {
    contenido[n] = letra;
    n++;
  }

  cout << "Tamaño en bytes: " << n << endl
       << "Caracteres leidos: " << n << endl;

  for (int i = 0; i < n; i++) {
    int count = 1;
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
      // Escribimos al archivo agregando un guion '-' para separar el número de la letra
      archivo_out << count << "-" << contenido[i];
    }
  }

  delete[] contenido;
  cout << "Compresión completada." << endl;
  delete[] archivo_entrada;
  delete[] archivo_salida;
}

void descompresion_rle(){
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

  // Descomprimir
  char *contenido = new char[100000];
  int n = 0;
  char letra;

  while (n < 100000 && archivo_in.get(letra)) {
    contenido[n] = letra;
    n++;
  }

  cout << "Tamano en bytes: " << n << endl
       << "Caracteres leidos: " << n << endl;

  int i = 0;
  while (i < n) {
    if (contenido[i] == '\n' || contenido[i] == '\r') {
      // Los saltos de línea se guardaron directamente, sin número
      archivo_out << contenido[i];
      i++;
    } else if (contenido[i] >= '0' && contenido[i] <= '9') {
      int count = 0;
      // Leer el número completo (puede tener más de un dígito, ej: "10")
      while (i < n && contenido[i] >= '0' && contenido[i] <= '9') {
        count = count * 10 + (contenido[i] - '0');
        i++;
      }
      
      // Saltamos el guion '-' que pusimos en la compresión
      if (i < n && contenido[i] == '-') {
        i++;
      }
      
      // El siguiente caracter es la letra a repetir
      if (i < n) {
        char letra = contenido[i];
        for (int j = 0; j < count; j++) {
          archivo_out << letra;
        }
        i++;
      }
    } else {
      // Por si hay algún caracter suelto sin número
      archivo_out << contenido[i];
      i++;
    }
  }
  
  delete[] contenido;
  cout << "Descompresión completada." << endl;
  delete[] archivo_entrada;
  delete[] archivo_salida;
}