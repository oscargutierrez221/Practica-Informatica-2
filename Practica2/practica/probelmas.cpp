#include "probelmas.h"
#include <iostream>
using namespace std;

char sala[15][20];

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
  // Decidi usar memoria dinamica porque no sabia que tan larga seria la cadena
  char *cadena = new char[100];
  char *cadena_sin_repetidos = new char[100];

  // Para evitar leer basura
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

  // delete [] para liberar la memoria ocupada
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
    char cadena[100];

    cin.ignore();
    cout << "Ingrese la cadena numerica: ";
    cin.getline(cadena, 100);
    cout << "Ingrese n: ";
    cin >> n;

    int len = 0;
    while (cadena[len] != '\0') len++;

    int ceros = (len % n == 0) ? 0 : n - len % n;  // ceros que faltan a la izquierda
    int grupos = (len + ceros) / n;
    int suma = 0;
    int original = 0;  // posicion en cadena original

    for (int g = 0; g < grupos; g++) {
        int num = 0;
        for (int d = 0; d < n; d++) {
            if (g == 0 && d < ceros) {
                num = num * 10;           // agregar 0 (relleno)
            } else {
                num = num * 10 + (cadena[original++] - '0');  // digito real
            }
        }
        suma += num;
    }

    cout << "Original: " << cadena << endl;
    cout << "Suma: " << suma << endl;
}

/* PROBLEMA - 11
Escriba un programa que permita manejar las reservas de asientos en una sala de
cine. Los asientos de la sala de cine est ́an organizados en 15 filas con 20
asientos cada una. El programa debe mostrar una representaci ́on de la sala que
indique qu ́e asientos est ́an disponibles y cu ́ales se encuentran reservados.
Adem ́as, debe permitir realizar reservas o cancelaciones al ingresar a la fila
(letras A-O) y el n ́umero del asiento (n ́umeros 1-20). Un ejemplo de visualizaci
́on de una secci ́on de la sala es el siguiente: 1 2 3 4 5 6 7 8 9 ... A + - - - -
- - - - B - - - - - - - - - C - - - - - - - - + D - - - - - - - - - E - - - - -
- - - - F - - - - - - - - - G - - - - - - - - - H - - - - - - - - -
.
.
.
Donde ”+” representa los asientos reservados y ”-” representa los asientos
disponibles
*/

void mostrar_sala() {
  char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                   'I', 'J', 'K', 'L', 'M', 'N', 'O'};

  cout << "   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20"
       << endl;

  for (int i = 0; i < 15; i++)
  {
    cout << letras[i] << "  ";
    for (int j = 0; j < 20; j++)
    {
      if (sala[i][j] == '+')
        {
        cout << "+  ";
      }
      else {
        cout << "-  ";
      }
    }
    cout << endl;
  }
}

void reservar_asiento() {
  char letra;
  int asiento;
  int fila;

  cout << "Ingrese la fila (A-O): ";
  cin >> letra;

  fila = letra - 'A';
  if (fila < 0 || fila > 14)
  {
    cout << "Fila invalida." << endl;
    return;
  }

  cout << "Ingrese el numero de asiento (1-20): ";
  cin >> asiento;

  if (asiento < 1 || asiento > 20)
  {
    cout << "Asiento invalido." << endl;
    return;
  }

  sala[fila][asiento - 1] = '+';
  cout << "Asiento " << letra << asiento << " reservado." << endl;
}

void cancelar_asiento() {
  char letra;
  int asiento;
  int fila;

  cout << "Ingrese la fila (A-O): ";
  cin >> letra;

  fila = letra - 'A';
  if (fila < 0 || fila > 14)
  {
    cout << "Fila invalida." << endl;
    return;
  }

  cout << "Ingrese el numero de asiento (1-20): ";
  cin >> asiento;

  if (asiento < 1 || asiento > 20)
  {
    cout << "Asiento invalido." << endl;
    return;
  }

  sala[fila][asiento - 1] = '-';
  cout << "Asiento " << letra << asiento << " cancelado." << endl;
}

void cine() {
  for (int i = 0; i < 15; i++)
    {
    for (int j = 0; j < 20; j++)
      {
      sala[i][j] = '-';
    }
  }

  int opcion;
  do {
    cout << "\nSala de cine" << endl;
    cout << "1. Reservar asiento" << endl;
    cout << "2. Cancelar asiento" << endl;
    cout << "3. Mostrar sala" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      reservar_asiento();
      break;
    case 2:
      cancelar_asiento();
      break;
    case 3:
      mostrar_sala();
      break;
    case 4:
      break;
    default:
      cout << "Opcion invalida." << endl;
    }
  } while (opcion != 4);
}

/* PROBLEMA - 13
Falto el punto, no supe como proceder a hacerlo
*/

/* PROBLEMA - 15
Elabore un programa que permita hallar la intersecci ́on entre un par de rect
́angulos. Represente los rect ́angulos como arreglos de 4 datos de la siguiente
manera: (a) Los primeros 2 datos corresponden a las coordenadas de la esquina
superior izquierda del rect ́angulo (x,y). (b) Los siguientes 2 datos representan
el ancho y la altura del rect ́angulo

El programa debe recibir 2 arreglos que representen los rect ́angulos A y B. Por
referencia, debe retornar un rect ́angulo C (con la misma estructura descrita
anteriormente) que corresponda a la intersecci ́on entre A y B. Por ejemplo, si
se ingresan los rect ́angulos A y B representados por los arreglos {0, 0, 8, 4} y
{5, 2, 6, 7}, el rect ́angulo C debe ser el arreglo {5, 0, 3, 4}
*/

void interseccion_rectangulos() {
  int *rectanguloA = new int[4];
  int *rectanguloB = new int[4];
  int *rectanguloC = new int[4];

  cout << "Ingrese el rectangulo A (x y ancho altura): ";
  cin >> rectanguloA[0] >> rectanguloA[1] >> rectanguloA[2] >> rectanguloA[3];

  cout << "Ingrese el rectangulo B (x y ancho altura): ";
  cin >> rectanguloB[0] >> rectanguloB[1] >> rectanguloB[2] >> rectanguloB[3];

  // Calcular la interseccion
  // Esquina izquierda de C: el maximo de las esquinas izquierdas de A y B
  if (rectanguloA[0] > rectanguloB[0])
  {
    rectanguloC[0] = rectanguloA[0];
  }
  else
  {
    rectanguloC[0] = rectanguloB[0]; // 2
  }

  // Esquina superior de C: el minimo de las esquinas superiores de A y B
  if (rectanguloA[1] < rectanguloB[1])
  {
    rectanguloC[1] = rectanguloA[1]; // 0
  }
  else
  {
    rectanguloC[1] = rectanguloB[1];
  }

  // Borde derecho de cada rectangulo
  int derechaA = rectanguloA[0] + rectanguloA[2]; // 0 + 2 = 2
  int derechaB = rectanguloB[0] + rectanguloB[2]; // 2 + 5 = 7

  // Ancho de C: minimo de los bordes derechos menos la x de C
  if (derechaA < derechaB)
  {
    rectanguloC[2] = derechaA - rectanguloC[0]; // 2 - 2 = 0
  }
  else
  {
    rectanguloC[2] = derechaB - rectanguloC[0];
  }

  // Borde inferior de cada rectangulo
  int abajoA = rectanguloA[1] + rectanguloA[3]; // 0 + 2 = 2
  int abajoB = rectanguloB[1] + rectanguloB[3]; // 2 + 5 = 7

  // Altura de C: minimo de los bordes inferiores menos la y de C
  if (abajoA < abajoB)
  {
    rectanguloC[3] = abajoA - rectanguloC[1];
  }
  else
  {
    rectanguloC[3] = abajoB - rectanguloC[1];
  }

  // Verificar si hay interseccion
  if (rectanguloC[2] <= 0 || rectanguloC[3] <= 0)
  {
    cout << "Los rectangulos no se intersectan." << endl;
  }
  else
  {
    cout << "Rectangulo de interseccion C: {" << rectanguloC[0] << ", "
         << rectanguloC[1] << ", " << rectanguloC[2] << ", " << rectanguloC[3]
         << "}" << endl;
  }

  delete[] rectanguloA;
  delete[] rectanguloB;
  delete[] rectanguloC;
}

/* PROBLEMA - 17
Dos n ́umeros a y b (con a ̸ = b) son amigables si la suma de los divisores de a
(excluy ́endose a s ́ı mismo) es igual a b, y al sumar los divisores de b el
resultado es a. Ej.: los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55
y 110; y suman 284. Los divisores de 284 son 1, 2, 4, 71 y 142, y suman 220.
Entonces, 220 y 284 son amigables. Escriba un programa que reciba un n ́umero y
halle la suma de todos los n ́umeros amigables menores al n ́umero ingresado. La
salida del programa cuando se ingresa el n ́umero 300 debe ser: El resultado de
la suma es: 504
*/

void numeros_amigables() {
  int n;
  int m;
  cout << "Ingrese un numero: ";
  cin >> n;
  cout << "Ingrese un segundo numero: ";
  cin >> m;

  int suma_n = 0;
  int suma_m = 0;

  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      suma_n += i;
    }
  }

  for (int i = 1; i < m; i++) {
    if (m % i == 0) {
      suma_m += i;
    }
  }

  if (suma_n == m && suma_m == n) {
    cout << "La suma de los divisores de " << n << " es " << suma_n << endl;
    cout << "La suma de los divisores de " << m << " es " << suma_m << endl;
    cout << "Por lo tanto, los numeros son amigables." << endl;
  } else {
    cout << "La suma de los divisores de " << n << " es " << suma_n << endl;
    cout << "La suma de los divisores de " << m << " es " << suma_m << endl;
    cout << "Por lo tanto, los numeros no son amigables." << endl;
  }
}

/* PROBLEMA - 19
 Me encuentro en imposibilidad de realizarlo
*/