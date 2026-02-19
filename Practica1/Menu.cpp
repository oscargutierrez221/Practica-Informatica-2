#include <iostream>
#include "Ejercicios.cpp"

using namespace std;

int main() {
    int numero;

    do {
        // 1. Mostrar el menú
        cout << "\n----- Bienvenido al menu de ejercicios -----\n" << endl;
        cout << "Ingrese el numero del ejercicio que desea ejecutar" << endl;
        cout << "1 - Residuo de la division entre A y B" << endl;
        cout << "2 - Mayor y menor de dos numeros" << endl;
        cout << "3 - Division con redondeo" << endl;
        cout << "4 - Suma de numeros" << endl;
        cout << "5 - Area y perimetro de un circulo" << endl;
        cout << "6 - Tabla de multiplicar" << endl;
        cout << "7 - Divisores de un numero" << endl;
        cout << "8 - Suma constante hasta ingresar cero" << endl;
        cout << "9 - Mayor constante hasta ingresar cero" << endl;
        cout << "10 - Determinar numero primo" << endl;
        cout << "11 - Convertir mayusculas y minusculas" << endl;
        cout << "12 - Minimo comun multiplo" << endl;
        cout << "13 - Contar cantidad de numeros en una cadena" << endl;
        cout << "14 - Calculadora simple" << endl;
        cout << "0 - Salir\n" << endl;
        cout << "Opcion: ";

        cin >> numero;

        // 2. Elejir
        switch (numero) {
        case 1:
            cout << "\n -- Residuo de divisiones -- \n" << endl;
            residuo();
            break;
        case 2:
            cout << "\n -- Mayor y menor de dos numeros -- \n" << endl;
            mayor_menor();
            break;
        case 3:
            cout << "\n -- Division con redondeo -- \n" << endl;
            redondeo();
            break;
        case 4:
            cout << "\n -- Suma de numeros -- \n" << endl;
            suma();
            break;
        case 5:
            cout << "\n -- Area y Perimetro de un circulo -- \n" << endl;
            area_perimetro();
            break;
        case 6:
            cout << "\n -- Tabla de multiplicar -- \n" << endl;
            tabla();
            break;
        case 7:
            cout << "\n -- Divisores de un numero -- \n" << endl;
            divisor();
            break;
        case 8:
            cout << "\n -- Suma constante -- \n" << endl;
            suma_constante();
            break;
        case 9:
            cout << "\n -- Mayor constante hasta ingresar 0 -- \n" << endl;
            mayor_constante();
            break;
        case 10:
            cout << "\n -- Determinar numero primo -- \n" << endl;
            numero_primo();
            break;
        case 11:
        cout << "\n -- Convertir mayuscas y minusculas -- \n" << endl;
            mayus_minus();
            break;
        case 12:
            cout << "\n -- Minimo comun multiplo -- \n";
            MIC();
            break;
        case 13:
            cout << "\n -- Contador de numeros en cadena -- \n ";
            contar();
            break;
        case 14:
            cout << "\n -- Calculadora simple -- \n";
            calculadora();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida, intente de nuevo." << endl;
            break;
        }

    } while (numero != 0);

    return 0;
}
