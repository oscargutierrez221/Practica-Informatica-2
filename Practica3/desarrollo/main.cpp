#include "compresion_rle.h"
#include "compresion_laz78.h"
#include "encriptar.h"
#include <iostream>

using namespace std;

int main() {
  int opcion;
  do {
    cout << "   ==> Bienvenido al menu de compresion y descompresion <==    \n" << endl;
    cout << "--> ¿Que metodo de compresion/descompresion deseas utilizar? <-- \n" << endl;
    cout << "1. Comprimir e encriptar con RLE" << endl;
    cout << "2. Comprimir e encriptar con Lz78" << endl;
    cout << "3. Comprimir con RLE o Lz78" << endl;
    cout << "4. Descomprimir con RLE o Lz78" << endl;
    cout << "5. Encriptar o desencriptar" << endl;
    cout << "0. Salir \n" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << "\n Comprimiendo archivo... \n";
      compresion_rle();
      cout << "\n Archivo comprimido, pasando a la encriptación... \n";
      encriptar_archivo();
      cout << "\n Proceso de encriptación finalizado \n";
      break;
    case 2:
      cout << "\n Comprimiendo archivo... \n";
      comprimir_lz78();
      cout << "\n Archivo comprimido, pasando a la encriptación... \n";
      encriptar_archivo();
      cout << "\n Proceso de encriptación finalizado \n";
      break;
    case 3:
      int metodo;
      do{
      cout << "\n ¿Que metodo de compresion deseas utilizar? \n";
      cout << "1. RLE \n";
      cout << "2. Lz78 \n";
      cout << "3. Volver al menu anterior \n";
      cin >> metodo;
      switch (metodo) {
      case 1:
        compresion_rle();
        break;
      case 2:
        comprimir_lz78();
        break;
      case 3:
        cout << "\n Volviendo al menu anterior... \n";
        break;
      }
      } while (metodo != 3);
      break;
    case 4:
      int metodo2;
      do{
      cout << "\n ¿Que metodo de descompresion deseas utilizar? \n";
      cout << "1. RLE \n";
      cout << "2. Lz78 \n";
      cout << "3. Volver al menu anterior \n";
      cin >> metodo2;
      switch (metodo2) {
      case 1:
        descompresion_rle();
        break;
      case 2:
        descompresion_lz78();
        break;
      case 3:
        cout << "\n Volviendo al menu anterior... \n";
        break;
      } while(metodo2 != 3);
      break;
    case 5:
      int metodo3;
      do{
      cout << "\n ¿Deseas encriptar o desencriptar? \n";
      cout << "1. Encriptar \n";
      cout << "2. Desencriptar \n";
      cout << "3. Volver al menu anterior \n";
      cin >> metodo3;
      switch (metodo3) {
      case 1:
        encriptar_archivo();
        break;
      case 2:
        desencriptar_archivo();
        break;
      case 3:
        cout << "\n Volviendo al menu anterior... \n";
        break;
      }
      }while (metodo3 != 3);
      break;
    case 0:
      cout << "\n Saliendo... \n";
      return 0;
    default:
      cout << "\n Opcion invalida \n";
      break;
    }
  } while (opcion != 0);
  return 0;
}
}