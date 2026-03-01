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
    int meses, dias, año_visciento;

    return 0;
}

