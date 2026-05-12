#include "compresion_laz78.h"
#include <fstream>
#include <iostream>

using namespace std;

void comprimir_lz78() {
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

  char *texto = new char[1000000];
  int n = 0;
  char letra;

  // Leer el archivo letra por letra (límite de 1000000 para no desbordar el
  // arreglo)
  while (n < 1000000 && archivo_in.get(letra)) {
    texto[n] = letra;
    n++;
  }

  cout << "Tamaño en bytes: " << n << endl
       << "Caracteres leidos: " << n << endl;

  char palabra[100];     // para la palabra actual
  int letras = 0;    // cantidad de letras en la palabra actual
  int posicion = 0;       // la posicion de la letra actual en el texto

  while (posicion < n) {
    palabra[letras] = texto[posicion];
    letras++;
    palabra[letras] = '\0';

    int buscar = 0;
    if (letras > 1) {
      for (int j = 0; j <= posicion - letras + 1 && buscar == 0; j++) {
        int encontrado = 1;
        for (int k = 0; k < letras - 1 && encontrado == 1; k++) {
          if (texto[j + k] != palabra[k]) encontrado = 0;
        }
        if (encontrado == 1) buscar = j + 1;  // encontrado
      }
    }

    // escribo en el archivo de salida
    archivo_out << buscar << "-" << palabra[letras - 1];

    // reinicio palabra
    letras = 0;
    posicion++;
  }

  cout << "Compresion completada." << endl;

  delete[] texto;
  delete[] archivo_entrada;
  delete[] archivo_salida;
  archivo_in.close();
  archivo_out.close();
}

void descompresion_lz78() {
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

  // Descomprimir

  char *texto = new char[1000000];
  int n = 0;
  char letra;

  // Leer el archivo letra por letra (límite de 1000000 para no desbordar el
  // arreglo)
  while (n < 1000000 && archivo_in.get(letra)) {
    texto[n] = letra;
    n++;
  }

  cout << "Tamaño en bytes: " << n << endl
       << "Caracteres leidos: " << n << endl;

  // reconstruir desde tokens: formato "indice-letra "
  char dict[100][100];   // diccionario reconstruido
  int dictlen[100];      // longitudes
  int nument = 0;        // entradas actuales
  int i = 0;             // posicion en texto comprimido

  while (i < n) {
    // leer numero
    int num = 0;
    while (i < n && texto[i] >= '0' && texto[i] <= '9') {
      num = num * 10 + (texto[i] - '0');
      i++;
    }

    // saltar guion
    if (i < n && texto[i] == '-') i++;

    // leer letra
    char letra = texto[i];
    i++;

    // reconstruir cadena: dict[num-1] + letra
    char cadena[100];
    int clen = 0;

    if (num > 0 && num <= nument) {
      // copiar del diccionario
      for (int c = 0; c < dictlen[num - 1]; c++) {
        cadena[clen] = dict[num - 1][c];
        clen++;
      }
    }

    // agregar letra nueva (si no es fin de archivo)
    if (letra != 0 && letra != ' ') {
      cadena[clen] = letra;
      clen++;
    }

    // escribir al archivo
    for (int c = 0; c < clen; c++) {
      archivo_out << cadena[c];
    }

    // guardar en diccionario si no era fin
    if (letra != 0 && letra != ' ' && nument < 100) {
      for (int c = 0; c < clen; c++) dict[nument][c] = cadena[c];
      dictlen[nument] = clen;
      nument++;
    }

    // saltar espacio si hay
    if (i < n && texto[i] == ' ') i++;
  }

  cout << "Descompresion completada." << endl;

  delete[] texto;
  delete[] archivo_entrada;
  delete[] archivo_salida;
  archivo_in.close();
  archivo_out.close();
}
