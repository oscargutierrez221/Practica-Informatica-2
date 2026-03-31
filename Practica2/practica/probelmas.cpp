#include "probelmas.h"
#include <iostream>
#include <new>
using namespace std;

/* Desarrolle un programa que permita determinar la minima combinacion de
billetes y monedas para una cantidad de dinero determinada. Los billetes en
circulacion son de $50.000, $20.000, $10.000, $5.000, $2.000 y $1.000, y las
monedas son de $500, $200, $100 y $50. Si por medio de los billetes y monedas
disponibles no se puede lograr la cantidad deseada, el sistema debera decir
lo que resta para lograrla. Use arreglos y ciclos para realizar el programa.*/

void combinacion_billetes() {
  int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
  int cantidad;
  cout << "Ingrese la cantidad de dinero: ";
  cin >> cantidad;
  for (int i = 0; i < 10; i++) {
    int cantidad_billetes = cantidad / billetes[i];
    cantidad = cantidad % billetes[i];
    cout << billetes[i] << ": " << cantidad_billetes << endl;
  }
  if (cantidad > 0) {
    cout << "Faltante: " << cantidad << endl;
  }
}

/* PROBLEMA - 3
Esciba un programa que compare 2 cadenas de caracteres y retorne verdadero si
son iguales y falso en caso contrario. Utilice arreglos de char. Tenga en cuenta
la longitud del arreglo y el caracter que indica la finalizacion de una cadena
de caracteres.
*/

void comparar_cadenas() {
  char cadena1[100];
  char cadena2[100];

  cin.ignore();

  cout << "Ingrese la primera cadena: ";
  cin.getline(cadena1, 100);

  cout << "Ingrese la segunda cadena: ";
  cin.getline(cadena2, 100);

  int i = 0;
  while (cadena1[i] == cadena2[i] && cadena1[i] != '\0') {
    i++;
  }

  if (cadena1[i] == cadena2[i]) {
    cout << "Las cadenas son iguales" << endl;
  } else {
    cout << "Las cadenas son diferentes" << endl;
  }
}

/* PROBLEMA - 5
Haga una funcion que reciba un numero entero (int) y lo convierta a cadena de
caracteres. Use parametros por referencia para retornar la cadena. Escriba un
programa de prueba que utilice dicha funcion. Por ejemplo, si el programa
recibe un int con valor 123, la cadena que se retorne debe ser "123"
*/

void int_a_cadena(int numero, char cadena[]) {
  int i = 0;
  bool esNegativo = false;

  // Caso especial para el 0
  if (numero == 0) {
    cadena[i++] = '0';
    cadena[i] = '\0';
    return;
  }

  // Manejo de numeros negativos
  if (numero < 0) {
    esNegativo = true;
    numero = -numero;
  }

  // Extraer digitos (quedaran en orden inverso)
  while (numero > 0) {
    cadena[i++] = (numero % 10) + '0';
    numero /= 10;
  }

  // Si era negativo, agregamos el signo
  if (esNegativo) {
    cadena[i++] = '-';
  }

  cadena[i] = '\0';

  // Voltear la cadena
  for (int j = 0; j < i / 2; j++) {
    char temp = cadena[j];
    cadena[j] = cadena[i - j - 1];
    cadena[i - j - 1] = temp;
 }
}

/* PROBLEMA - 7
Escriba un programa que reciba una cadena de caracteres y elimine los caracteres
repetidos. Por ejemplo, si se recibe "bananas" debe mostrar "bans". La salida
del programa debe ser: Original: bananas. Sin repetidos: bans.
*/

void caracter_repetido() {
  // Reservamos memoria dinamicamente usando 'new' (Memoria en el Heap)
  char *cadena = new char[100];
  char *cadena_sin_repetidos = new char[100];

  // IMPORTANTE: Inicializar para evitar leer basura de la memoria
  cadena_sin_repetidos[0] = '\0';

  cin.ignore();

  cout << "Ingrese una cadena: ";
  cin.getline(cadena, 100);

  int i = 0;
  int k = 0;
  while (cadena[i] != '\0') {
    int j = 0;
    bool encontrado = false;
    while (cadena_sin_repetidos[j] != '\0') {
      if (cadena[i] == cadena_sin_repetidos[j]) {
        encontrado = true;
        break;
      }
      j++;
    }

    if (!encontrado) {
      cadena_sin_repetidos[k++] = cadena[i];
      cadena_sin_repetidos[k] = '\0'; // Mantener el fin de cadena
    }
    i++;
  }

  cout << "Original: " << cadena << endl;
  cout << "Sin repetidos: " << cadena_sin_repetidos << endl;

  // IMPORTANTE: Liberar la memoria dinamica usando 'delete[]'
  delete[] cadena;
  delete[] cadena_sin_repetidos;
}

/* PROBLEMA - 9
Escribir un programa que reciba un numero n y una cadena de caracteres
numericos; el programa debe separar la cadena de caracteres en grupos de n
cifras, sumarlos e imprimir el resultado. En caso de no poder dividirse
exactamente en grupos de n cifras, se debe rellenar con ceros a la izquierda del
primer numero. Por ejemplo, si N = 3 y se lee el arreglo 87512395, la suma
seria 087+512+395 = 994. La salida del programa debe ser: Original: 87512395.
Suma: 994.
*/

void suma_de_cadena() {
  int n;
  char *cadena = new char[100];

  cin.ignore();
  cout << "Ingrese la cadena numerica: ";
  cin.getline(cadena, 100);
  cout << "Ingrese el tamano de cada grupo (n): ";
  cin >> n;

  // 1. Calcular la longitud de la cadena
  int longitud = 0;
  while (cadena[longitud] != '\0') {
    longitud++;
  }

  // 2. Calcular cuantos ceros necesitamos rellenar al inicio
  //    para que la longitud sea multiplo exacto de n
  int resto = longitud % n;
  int ceros = (resto == 0) ? 0 : n - resto;

  // 3. Crear una nueva cadena con los ceros de relleno al inicio
  int longitud_final = longitud + ceros;
  char *cadena_rellena = new char[longitud_final + 1];

  // Colocar los ceros al inicio
  for (int i = 0; i < ceros; i++) {
    cadena_rellena[i] = '0';
  }
  // Copiar la cadena original despues de los ceros
  for (int i = 0; i < longitud; i++) {
    cadena_rellena[ceros + i] = cadena[i];
  }
  cadena_rellena[longitud_final] = '\0';

  // 4. Separar en grupos de n digitos y sumar
  int suma = 0;
  int num_grupos = longitud_final / n;

  for (int grupo = 0; grupo < num_grupos; grupo++) {
    // Convertir el grupo actual de chars a entero
    int valor_grupo = 0;
    for (int d = 0; d < n; d++) {
      // Cada char digito se convierte a int restando el caracter '0'
      valor_grupo = valor_grupo * 10 + (cadena_rellena[grupo * n + d] - '0');
    }
    suma += valor_grupo;
  }

  cout << "Original: " << cadena << endl;
  cout << "Suma: " << suma << endl;

  // 5. Liberar toda la memoria dinamica reservada
  delete[] cadena;
  delete[] cadena_rellena;
}