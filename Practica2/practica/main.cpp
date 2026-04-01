#include "_punteros_direcciones.h"
#include "probelmas.h"
#include <iostream>
using namespace std;

int main() {
  // int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // fun_b(array, 10);
  int opcion;
  do {
    cout << "Bienvenido al menu de problemas de la Practica #2" << endl;
    cout << "1. Combinacion de billetes" << endl;
    cout << "2. Comparar cadenas" << endl;
    cout << "3. Transformar int a cadena" << endl;
    cout << "4. Eliminar caracter repetido en cadena" << endl;
    cout << "5. Suma de una cadena por partes" << endl;
    cout << "6. Asientos de la sala de cine" << endl;
    cout << "7. Interseccion entre 2 rectangulos" << endl;
    cout << "8. Determinar numeros amigables de acuerdo a la suma" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << endl;
      cout << "Problema 1: Combinacion de billetes" << endl;
      combinacion_billetes();
      cout << endl;
      break;
    case 2:
      cout << endl;
      cout << "Problema 2: Comparar cadenas" << endl;
      comparar_cadenas();
      cout << endl;
      break;
    case 3: {
      cout << endl;
      cout << "Problema 3: Transformar int a cadena" << endl;
      int n;
      char res[100];
      cout << "Ingrese un numero: ";
      cin >> n;
      int_a_cadena(n, res);
      cout << "Cadena: " << res << endl;
      cout << endl;
      break;
    }
    case 4:
      cout << endl;
      cout << "Problema 4: Eliminar caracter repetido en cadena" << endl;
      caracter_repetido();
      cout << endl;
      break;
    case 5: {
      cout << endl;
      cout << "Problema 5: Suma de una cadena por partes" << endl;
      suma_de_cadena();
      cout << endl;
      break;
    }
    case 6: {
      cout << endl;
      cout << "Problema 6: Asientos de la sala de cine" << endl;
      cine();
      cout << endl;
      break;
    }
    case 7: {
      cout << endl;
      cout << "Calculo de interseccion entre triangulos" << endl;
      interseccion_rectangulos();
      cout << endl;
      break;
    }
    case 8: {
      cout << endl;
      cout << "Problema 8: Determinar numeros amigables de acuerdo a la suma"
           << endl;
      numeros_amigables();
      cout << endl;
      break;
    }
    case 0:
      cout << "Saliendo..." << endl;
      break;
    default:
      cout << "Opcion no valida" << endl;
      break;
    }
  } while (opcion != 0);
}
