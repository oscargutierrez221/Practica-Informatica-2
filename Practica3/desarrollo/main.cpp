#include "compresion_rle.h"
#include "encriptar.h"
#include <iostream>

using namespace std;

int main() {
  int opcion;
  do {
    cout << "1. Compresion RLE" << endl;
    cout << "2. Descompresion RLE" << endl;
    cout << "3. Encriptar archivo" << endl;
    cout << "4. Desencriptar archivo" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << "Comprimiendo archivo..." << endl;
      compresion_rle();
      break;
    case 2:
      cout << "Modulo de descompresion aun no disponible." << endl;
      break;
    case 3: {
      cout << "Encriptando archivo..." << endl;
      encriptar_archivo();
      break;
    }
    case 4: {
      cout << "Desencriptando archivo..." << endl;
      desencriptar_archivo();
      break;
    }
    case 0:
      return 0;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  } while (opcion != 0);
  return 0;
}
