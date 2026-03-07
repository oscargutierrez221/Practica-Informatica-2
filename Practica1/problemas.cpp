#include <iostream>

using namespace std;

/*
    PROBLEMA - 1
Escriba un programa que identique si un carácter ingresado es una vocal, una consonante o ninguna de las 2 e imprima un mensaje según el caso.

*/

int es_letra() {
    char c;

    cout << "Ingrese un caracter: ";
    cin >> c;

    c = tolower(c);

    if (c < 'a' || c > 'z') {
        cout << "No es una letra.";
    }
    else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << "Es una vocal. \n";
    }
    else {
        cout << "Es una consonante. \n";
    }

    return 0;
}

/*
    PROBLEMA - 3
Escriba un programa que debe leer un mes y un día de dicho mes para luego decir
si esa combinación de mes y día son válidos. El caso más especial es el 29 de febrero, en dicho caso
imprimir posiblemente año bisiesto.

*/

int calendario() {
    int meses, dias;

    cout << "Ingrese el mes (1-12): ";
    cin >> meses;

    cout << "Ingrese el día: ";
    cin >> dias;

    if (meses < 1 || meses > 12) {
        cout << "Mes no válido. \n";
        return 0;
    }
    else if (dias < 1 || dias > 31) {
        cout << "Día no válido. \n";
        return 0;
    }

    if (meses == 2) {
        if (dias > 29) {
            cout << "Día no válido para febrero. \n";
        }
        else if (dias == 29) {
            cout << "Posiblemente año bisiesto. \n";
        }
        else {
            cout << "Fecha válida. \n";
        }
    }
    else if (meses == 4 || meses == 6 || meses == 9 || meses == 11) {
        if (dias > 30) {
            cout << "Día no válido para este mes. \n";
        }
        else {
            cout << "Fecha válida. \n";
        }
    }
    else {
        cout << "Fecha válida. \n";
    }

    return 0;
}

/*
    PROBLEMA - 7
En la serie de Fibonacci, cada número es la suma de los 2 anteriores e inicia con 1 y
1. Ej: 1, 1, 2, 3, 5, 8, ....
Escriba un programa que reciba un número n y halle la suma de todos los números pares en la serie
de Fibonacci menores a n.

*/

int fibonacci() {
    int n, a = 1, b = 1, suma_pares = 0;

    cout << "Ingrese un numero n: ";
    cin >> n;

    while (a < n) {
        if (a % 2 == 0) {
            suma_pares += a;
        }
        int temp = a;
        a = b;
        b = temp + b;
    }

    cout << "La suma de los números pares en la serie de Fibonacci menores a " << n << " es: " << suma_pares << endl;

    return 0;
}

/*
    PROBLEMA - 9
Escriba un programa que pida un número entero N e imprima el resultado de la suma
de todos sus dígitos elevados a sí mismos

*/

int suma_digitos_elevados_a_si_mismos() {
    int N;
    cout << "Ingrese un numero entero N: ";
    cin >> N;

    int numero = (N < 0) ? -N : N; // Valor absoluto en caso de que el numero sea negativo
    int suma = 0;

    while (numero > 0) {
        int digito = numero % 10;

        int elevado = 1;
        for (int i = 0; i < digito; i++) {
            elevado *= digito;
        }

        suma += elevado;

        numero = numero / 10;
    }

    // Si el número original era 0, la suma es 0
    if (N == 0) {
        suma = 0;
    }

    cout << "La suma de elos numeros elevados a si mismos es: " << suma << endl;

    return 0;
}

/*
    PROBLEMA - 13
Escriba un programa que reciba un número y calcule la suma de todos los primos
menores que el número ingresado.

*/

int suma_primos_menores () {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    int suma = 0;

    for (int num = 2; num < n; num++) {
        // Verificar si 'num' es primo
        bool es_primo = true;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                es_primo = false;
                break;
            }
        }
        if (es_primo) {
            suma += num;
        }
    }

    cout << "La suma de todos los primos menores que " << n << " es: " << suma << endl;

    return 0;
}
