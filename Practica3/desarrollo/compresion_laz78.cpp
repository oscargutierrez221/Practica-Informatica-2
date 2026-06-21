#include "compresion_laz78.h"
#include <fstream>
#include <iostream>

using namespace std;

void comprimir_lz78() {
  // Pedir rutas de archivos
  char ruta_entrada[256];
  char ruta_salida[256];

  cout << "Ruta del archivo a comprimir: ";
  cin.ignore();
  cin.getline(ruta_entrada, 256);

  cout << "Ruta del archivo comprimido: ";
  cin.getline(ruta_salida, 256);

  ifstream archivo_entrada(ruta_entrada, ios::binary);
  ofstream archivo_salida(ruta_salida, ios::binary);

  if (!archivo_entrada || !archivo_salida) {
    cout << "Error al abrir archivos" << endl;
    return;
  }

  // Leer todo el archivo
  char texto_completo[1000000];
  int total_caracteres = 0;
  char caracter_actual;

  while (total_caracteres < 1000000 && archivo_entrada.get(caracter_actual)) {
    texto_completo[total_caracteres] = caracter_actual;
    total_caracteres++;
  }

  cout << "Leidos " << total_caracteres << " caracteres" << endl;

  // Comprimir carácter por carácter
  int posicion_actual = 0;

  while (posicion_actual < total_caracteres) {
    char caracter = texto_completo[posicion_actual];
    
    // Buscar si este carácter apareció antes
    int posicion_anterior = 0;
    
    for (int i = 0; i < posicion_actual; i++) {
      if (texto_completo[i] == caracter) {
        posicion_anterior = i + 1;
        break;
      }
    }
    
    archivo_salida << posicion_anterior << "-" << caracter << " ";
    
    posicion_actual++;
  }

  cout << "Compresion completada." << endl;

  archivo_entrada.close();
  archivo_salida.close();
}

void descompresion_lz78() {
  // Pedir rutas de archivos
  char ruta_entrada[256];
  char ruta_salida[256];

  cout << "Ruta del archivo comprimido: ";
  cin.ignore();
  cin.getline(ruta_entrada, 256);

  cout << "Ruta del archivo descomprimido: ";
  cin.getline(ruta_salida, 256);

  ifstream archivo_comprimido(ruta_entrada, ios::binary);
  ofstream archivo_descomprimido(ruta_salida, ios::binary);

  if (!archivo_comprimido || !archivo_descomprimido) {
    cout << "Error al abrir archivos" << endl;
    return;
  }

  // Leer todo el archivo comprimido
  char texto_comprimido[1000000];
  int total_caracteres = 0;
  char caracter;

  while (total_caracteres < 1000000 && archivo_comprimido.get(caracter)) {
    texto_comprimido[total_caracteres] = caracter;
    total_caracteres++;
  }

  cout << "Leidos " << total_caracteres << " caracteres comprimidos" << endl;

  // Guardar
  char diccionario[100][100];
  int longitudes[100];
  int total_entradas = 0;

  int posicion = 0;  // Posición actual en el texto comprimido

  while (posicion < total_caracteres) {
    // Leer posicion
    int numero = 0;
    while (posicion < total_caracteres && texto_comprimido[posicion] >= '0' && texto_comprimido[posicion] <= '9') {
      numero = numero * 10 + (texto_comprimido[posicion] - '0');
      posicion++;
    }

    // Saltar el guión
    if (posicion < total_caracteres && texto_comprimido[posicion] == '-') {
      posicion++;
    }

    // Leer la letra
    char letra = texto_comprimido[posicion];
    posicion++;

    // Reconstruir la cadena
    char resultado[100];
    int longitud = 0;

    // Si el número no es cero, copiar del diccionario
    if (numero > 0 && numero <= total_entradas) {
      for (int i = 0; i < longitudes[numero - 1]; i++) {
        resultado[longitud] = diccionario[numero - 1][i];
        longitud++;
      }
    }

    // Agregar la letra actual
    resultado[longitud] = letra;
    longitud++;

    // Escribir el resultado al archivo
    for (int i = 0; i < longitud; i++) {
      archivo_descomprimido << resultado[i];
    }

    // Guardar en el diccionario si hay espacio
    if (total_entradas < 100) {
      for (int i = 0; i < longitud; i++) {
        diccionario[total_entradas][i] = resultado[i];
      }
      longitudes[total_entradas] = longitud;
      total_entradas++;
    }

    // Saltar el espacio si hay
    if (posicion < total_caracteres && texto_comprimido[posicion] == ' ') {
      posicion++;
    }
  }

  cout << "Descompresion completada." << endl;

  archivo_comprimido.close();
  archivo_descomprimido.close();
}
