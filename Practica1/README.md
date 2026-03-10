# Práctica de Informática 2 - Ejercicios y Problemas en C++

Este repositorio contiene un proyecto en C++ desarrollado como una aplicación de consola bajo el framework Qt (archivo `.pro`). Incluye la resolución de diversos ejercicios básicos e intermedios de algoritmia y lógica de programación mediante un menú interactivo.

## Estructura del Proyecto

El proyecto se divide en diferentes archivos fuente para organizar la lógica:

- **`Practica.pro` / `Practica.pro.user`**: Archivos de configuración del proyecto generados por Qt Creator. Definen que es una aplicación de consola en C++17.
- **`Menu.cpp`**: Contiene la función `main` y presenta un menú iterativo para seleccionar y ejecutar cualquiera de los programas.
- **`Ejercicios.cpp`**: Archivo que contiene la implementación de los ejercicios orientados a prácticas de lógica, ciclos e iteraciones (operaciones aritméticas básicas, validaciones simples).
- **`problemas.cpp`**: Archivo que alberga problemas un poco más avanzados, abarcando validación de fechas, la serie de Fibonacci, y el manejo y descomposición de números y caracteres.

## Catálogo de Ejercicios y Problemas

El menú está dividido en dos grandes secciones:

### Ejercicios (de `Ejercicios.cpp`)
1. **Residuo de la división:** Calcula el módulo entre dos números ingresados ($a \pmod b$).
2. **Mayor y menor de dos números:** Compara dos valores numéricos e indica cuál es el mayor.
3. **División con redondeo:** Realiza la división $A / B$ redondeando al entero más cercano.
4. **Suma de números:** Suma todos los números en el rango $[0, N]$.
5. **Área y perímetro de un círculo:** Calcula, dado un radio $N$, el área y el perímetro usando $\pi \approx 3.1416$.
6. **Tabla de multiplicar:** Muestra la tabla del 1 al 10 para un número $N$.
7. **Divisores de un número:** Imprime todos los divisores enteros de $N$.
8. **Suma constante:** Suma los números ingresados por el usuario hasta que se ingrese un $0$.
9. **Mayor constante:** Encuentra el número mayor dentro de una serie ingresada hasta escribir $0$.
10. **Determinar número primo:** Verifica si un número ingresado es primo.
11. **Convertir mayúsculas y minúsculas:** Cambia el caso de un carácter ingresado (si es letra).
12. **Mínimo común múltiplo:** Calcula el MCM entre dos números ingresados usando el MCD.
13. **Contador de números en cadena:** Cuenta el número de dígitos que conforman un valor numérico.
14. **Calculadora simple:** Recibe dos operandos y un operador (`+`, `-`, `*`, `/`) y muestra el resultado de su operación.

### Problemas (de `problemas.cpp`)
15. **Es vocal o consonante:** Clasifica el carácter ingresado como vocal, consonante o "no letra".
16. **Combinación de meses y días:** Verifica si una combinación numérica de mes y día forma una fecha válida del calendario, identificando la particularidad del 29 de febrero como año bisiesto.
17. **Suma de la serie de Fibonacci:** Suma los números *pares* de la serie de Fibonacci que son estrictamente menores a $N$.
18. **Suma de los dígitos elevados a sí mismos:** Separa los dígitos de un dígito base, eleva cada dígito a sí mismo y los suma.
19. **Suma de primos menores:** Calcula la suma de todos los números primos que sean estrictamente menores a un tope ingresado.

## Compilación y Ejecución

*Nota: En el código actual, `Menu.cpp` incluye directamente a `Ejercicios.cpp` y `problemas.cpp` a través de macros como `#include "Ejercicios.cpp"`.*

### Mediante terminal (GCC/G++)
Debido a la inclusión directa dentro del Main, puedes compilar directamente solo el archivo `Menu.cpp`:
```bash
g++ Menu.cpp -o app_practica
./app_practica
```

### Mediante Qt Creator
1. Abre el archivo `Practica.pro` en Qt Creator.
2. Configura un Kit por defecto.
3. Compila presionando (Ctrl+B) y ejecuta con (Ctrl+R).

## Consideraciones

* Se evitan importaciones directas desde bibliotecas gráficas (`QtCore`, `QtWidgets`), ya que esta práctica se centra puramente en el desarrollo y destreza de la lógica de programación (aplicación configurada como de **consola** y utilizando `iostream`).
* El programa fue configurado usando la especificación `c++17`.
