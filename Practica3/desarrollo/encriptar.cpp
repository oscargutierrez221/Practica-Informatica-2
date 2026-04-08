#include "encriptar.h"
#include <fstream>
#include <iostream>

using namespace std;

void encriptar_archivo() {

  // Usamos memoria dinamica aqui porque no sabemos el tamaño de los archivos
  char *entrada = new char[256];
  char *salida = new char[256];

  cout << "Ruta del archivo de entrada: ";
  cin.ignore();
  cin.getline(entrada, 256);
  cout << "Ruta del archivo de salida: ";
  cin.getline(salida, 256);

  int clave;
  int rotacion_bits;

  cout << "Ingrese la clave: ";
  cin >> clave;
  cout << "Ingrese la rotacion de bits: ";
  cin >> rotacion_bits;

  ifstream archivo_in(entrada, ios::binary);
  ofstream archivo_out(salida, ios::binary);

  if (!archivo_in.is_open()) {
    cerr << "Error al abrir el archivo de entrada" << endl;
    return;
  }

  if (!archivo_out.is_open()) {
    cerr << "Error al abrir el archivo de salida" << endl;
    return;
  }

  char letra;
  // Leemos letra por letra
  while (archivo_in.get(letra)) {
    // Usamos unsigned char para que no haya números negativos
    unsigned char numero = letra;

    // Paso 1: Sumar la clave
    int suma = numero + clave;
    numero = suma % 256;

    // Paso 2: Rotar a la izquierda
    numero = rotIzq(numero, rotacion_bits);

    // Escribimos al archivo de salida
    archivo_out.put(numero);
  }

  archivo_in.close();
  archivo_out.close();

  delete[] entrada;
  delete[] salida;
}

void desencriptar_archivo() {

  char *entrada = new char[256];
  char *salida = new char[256];

  cout << "Ruta del archivo de entrada: ";
  cin.ignore();
  cin.getline(entrada, 256);
  cout << "Ruta del archivo de salida: ";
  cin.getline(salida, 256);

  int clave;
  int rotacion_bits;

  cout << "Ingrese la clave: ";
  cin >> clave;
  cout << "Ingrese la rotacion de bits: ";
  cin >> rotacion_bits;

  ifstream archivo_in(entrada, ios::binary);
  ofstream archivo_out(salida, ios::binary);

  if (!archivo_in.is_open()) {
    cerr << "Error al abrir el archivo de entrada" << endl;
    return;
  }

  if (!archivo_out.is_open()) {
    cerr << "Error al abrir el archivo de salida" << endl;
    return;
  }

  char letra;
  while (archivo_in.get(letra)) {
    unsigned char numero = letra;

    // Paso 1: Rotar a la derecha
    numero = rotDer(numero, rotacion_bits);

    // Paso 2: Restar la clave
    int resta = numero - clave;
    // Si la resta da negativo, le damos la vuelta sumando 256
    if (resta < 0) {
      resta = resta + 256;
    }
    numero = resta;

    archivo_out.put(numero);
  }

  archivo_in.close();
  archivo_out.close();

  delete[] entrada;
  delete[] salida;
}

unsigned char rotIzq(unsigned char c, int n) {
  unsigned char parte_izq = c << n;
  unsigned char parte_der = c >> (8 - n);
  return parte_izq | parte_der;
}

unsigned char rotDer(unsigned char c, int n) {
  unsigned char parte_der = c >> n;
  unsigned char parte_izq = c << (8 - n);
  return parte_der | parte_izq;
}