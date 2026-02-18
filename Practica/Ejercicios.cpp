#include <iostream>

using namespace std;

/*
    EJERCICIO - 1

Escriba un programa que pida dos números A y B e imprima en pantalla el residuo
de la división A/B

*/

int residuo(){
    int a, b;

    cout << "Ingrese el primer numero: ";
    cin >> a;

    cout << "Ingrese el segundo numero: ";
    cin >> b;

    if (b == 0) {
        cout << "Error: No es posible dividir por cero." << endl;
    } else {
        cout << "El residuo de la division entre " << a << " y " << b << " es: " << a % b << endl;
    }
    return 0;
};

/*
    EJERCICIO - 3

Escriba un programa que pida dos números A y B e imprima en pantalla el mayor.

*/

int mayor_menor() {
    int a, b;

    cout << "Ingrese el primer numero: ";
    cin >> a;

    cout << "Ingrese el segundo numero: ";
    cin >> b;

    if (a > b) {
        cout << "El numero mayor es: " << a << endl;
    } else if (b > a) {
        cout << "El numero mayor es: " << b << endl;
    } else {
        cout << "Los numeros son iguales" << endl;
    }
    return 0;
};

/*
    EJERCICIO - 5

Escriba un programa que pida dos números A y B e imprima en pantalla la división
A/B con redondeo

*/

int redondeo() {
    float a, b;

    cout << "Ingrese el primer numero: ";
    cin >> a;

    cout << "Ingrese el segundo numero: ";
    cin >> b;

    if (b == 0) {
        cout << "Error: No es posible dividir por 0." << endl;
    } else {
        float resultado = a / b;
        int aprox = (int)(resultado + 0.5);

        cout << "El resultado de la division entre " << a << " Y " << b << " es: " << aprox << endl;
    }
    return 0;
};

/*
    EJERCICIO - 7

Escriba un programa que pida un número N e imprima en pantalla la suma de todos
los números entre 0 y N (incluyéndose el mismo)

*/

int suma(){
    int a;
    int total = 0;
    cout << "Ingrese un numero: ";
    cin >> a;

    int limite = a;

    for (int i = 0; i <= limite; i++) {
        total += i;
    }

    cout << "La suma de los numeros entre 0 y " << a << " es: " << total << endl;

    return 0;
};

/*
    EJERCICIO - 9

Escriba un programa que pida un número N e imprima el perímetro y área de un
círculo con radio N. Nota: use 3.1416 como una aproximación de pi.

*/

int area_perimetro() {
    double N, area, perimetro, pi = 3.1416;

    cout << "Ingrese el numero N: ";
    cin >> N;

    area = pi * N * N;
    perimetro = 2 * pi * N;

    cout << "Area: " << area << endl;
    cout << "Perimetro: " << perimetro << endl;

    return 0;
};

/*
    EJERCICIO - 11

Escriba un programa que pida un número N e imprima en pantalla su tabla de mul-
tiplicar hasta 10xN

*/

int tabla() {
    int a;

    cout << "Ingrese el numero: ";
    cin >> a;

    for (int i = 1; i <= 10; i++) {
        cout << a << " x " << i << " = " << a * i << endl;
    }

    return 0;
};

/*
    EJERCICIO - 13

Escriba un programa que pida un número N e imprima todos los divisores de N

*/

int divisor() {
    int a;

    cout << "Ingrese el numero: ";
    cin >> a;

    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            cout << i << " es un divisor de " << a << endl;
        }
    }
    return 0;
};

/*
    EJERCICIO - 15

Escriba un programa que pida constantemente números hasta que se ingrese el nú-
mero cero e imprima en pantalla la suma de todos los números ingresados.

*/

int suma_constante() {
    int a;
    int total = 0;

    cout << "Ingrese numero: ";
    cin >> a;

    while (a != 0) {
        total += a;
        cout << "Ingrese numero: ";
        cin >> a;
    }

    cout << "El resultado de la suma es: " << total << endl;
    return 0;
};

/*
    EJERCICIO 17

Escriba un programa que pida constantemente números hasta que se ingrese el nú-
mero cero e imprima en pantalla el mayor de todos los números ingresados.

*/

int mayor_constante() {
    int a;
    int mayor = 0;

    cout << "Ingrese numero: ";
    cin >> a;

    while (a != 0) {
        if (a > mayor) {
            mayor = a;
        }
        cout << "Ingrese numero: ";
        cin >> a;
    }

    cout << "El numero mayor es: " << mayor << endl;
    return 0;
};
