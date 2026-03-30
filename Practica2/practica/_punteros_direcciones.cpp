#include "_punteros_direcciones.h"
#include <iostream>
using namespace std;

/* - EJERCICIO #1

Con ayuda del debugger, examine la representación en memoria del arreglo
- ¿Cuál es la dirección de memoria?
- ¿Cuantos bytes se dedican para almacenar cada el de array?
- ¿Cuál es la dirección y el contrenido de memoria del elemento array[3]?
- Describa el efecto que tiene la función fun_b sobre el arreglo array.
*/

void fun_a(int *px, int *py) {
  int tmp = *px;
  *px = *py;
  *py = tmp;
}

void fun_b(int a[], int tam) {
  int f, l;
  int *b = a;
  for (f = 0, l = tam - 1; f < l; f++, l--) {
    fun_a(&b[f], &b[l]);
    cout << b[f] << " " << b[l] << endl;
  }
}

/* - EJERCICIO #2

 Se tiene la siguiente declaracion e inicializacion:

unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};

Complete la numeracion de las direcciones de memoria (en notacion hexadecimal)
para cada uno de los 8 elementos de b. Puede seleccionar un valor arbitrario
para la primera posicion de memoria del arreglo. Determine el valor de las
siguientes expresiones:
• b
• b+2
• *(b+2)
• *(b+2)+1
• *(*(b+2)+1)
• b[3][1]
• *b++
*/
void arreglo_2() {
  unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};
  cout << "Direccion de memoria de " << b << endl;
  cout << "Direccion de memoria de b+2: " << b + 2 << endl;
  cout << "Valor de *(b + 2): " << *(b + 2) << endl;
  cout << "Valor de *(b + 2) + 1: " << *(b + 2) + 1 << endl;
  cout << "Valor de *(*(b + 2) + 1): " << *(*(b + 2) + 1) << endl;
  cout << "Valor de b[3][1]: " << b[3][1] << endl;
  cout << "Valor de *b: " << *b << endl;
}
