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

/*
    Ejercicio - 19
Escriba un programa que pida un número N e imprima si es o no un número primo.

*/

int numero_primo() {
    int n;
    cout << "Ingresa un numero: ";
    cin >> n;

    if (n < 2) {
        cout << "No es primo" << endl;
        return 0;
    }

    bool esPrimo = true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { // si el resultado es 0, entonces n no es primo
            esPrimo = false;
            break;
        }
    }

    if (esPrimo)
        cout << n << " es primo" << endl;
    else
        cout << n << " no es primo" << endl;

    return 0;
}

/*
    EJERCICIO - 21
Escriba un programa que pida un carácter C, si es una letra la debe convertir de
mayúscula a minúscula y viceversa e imprimirla

*/

int mayus_minus() {
    char a;

    cout << "Ingrese la letra a convertir: ";
    cin >> a;

    if (a >= 'a' && a <= 'z') {
        // Convertir a mayúscula
        char mayuscula = a - ('a' - 'A');
        cout << "La letra convertida a mayuscula es: " << mayuscula << endl;
    }
    else if (a >= 'A' && a <= 'Z') {
        // Convertir a minúscula
        char minuscula = a + ('a' - 'A');
        cout << "La letra convertida a minuscula es: " << minuscula << endl;
    }
    else {
        cout << "El caracter ingresado no es una letra." << endl;
    }


    return 0;
}

/*
    EJERCICIO - 23
Escriba un programa que pida dos números A y B e imprima en pantalla el mínimo
común múltiplo entre los dos.

*/

int MIC() {
    int a, b, temp;
    int num1, num2; // Variables para guardar los originales

    cout << "Ingrese el primer numero: ";
    cin >> a;
    num1 = a; // Guardamos original

    cout << "Ingrese el segundo numero: ";
    cin >> b;
    num2 = b; // Guardamos original

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    // La formula = (num1 * num2) / MCD
    cout << "El minimo comun multiplo es: " << (num1 * num2) / a << endl;

    return 0;
}

/*
    EJERCICIO - 25
Escriba un programa que pida un número N e imprima en pantalla la cantidad de
dígitos de N

*/

int contar(){
    int a, contador = 0;

    cout << "Ingrese el numero: ";
    cin >> a;

    // Usamos valor absoluto por si el usuario ingresa un número negativo
    if (a < 0) a = -a;

    do {
        contador++;    // Contamos el dígito actual
        a = a / 10;    // Eliminamos el último dígito
    } while (a != 0);  // Solo se detiene cuando el número llega a cero absoluto

    cout << "El numero tiene: " << contador << " digitos" << endl;
    return 0;
}

/*
    EJERCICIO - 27
Escriba un programa que actúe como una calculadora con operaciones de suma,
resta, multiplicación y división, el usuario debe ingresar los operandos y la operación a realizar

*/

int calculadora() {
    float num1, num2, resultado;
    char operacion;

    cout << "Ingresa el primer numero: ";
    cin >> num1;

    cout << "Ingresa la operacion (+, -, *, /): ";
    cin >> operacion;

    cout << "Ingresa el segundo numero: ";
    cin >> num2;

    switch (operacion) {
    case '+':
        resultado = num1 + num2;
        break;
    case '-':
        resultado = num1 - num2;
        break;
    case '*':
        resultado = num1 * num2;
        break;
    case '/':
        // No se puede dividir por 0
        if (num2 != 0) {
            resultado = num1 / num2;
        } else {
            cout << "Error: No se puede dividir por cero." << endl;
            return 1; // Termina el programa con error
        }
        break;
    default:
        cout << "Operacion no valida." << endl;
        return 1;
    }

    cout << "El resultado es: " << resultado << endl;

    return 0;
}

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
        cout << "Es una vocal.";
    }
    else {
        cout << "Es una consonante.";
    }

    return 0;
}







































