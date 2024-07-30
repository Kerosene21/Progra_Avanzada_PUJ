// main.cpp
#include <iostream>
#include "regresion_lineal.h"

int main() {
    int n = 5; // Número de puntos de datos

    // Crear una estructura Datos con n puntos de datos
    Datos* datos = crearDatos(n);

    // Asignar valores a los puntos de datos
    datos->x = {1.0, 2.0, 3.0, 4.0, 5.0};   // Valores de la variable independiente
    datos->y = {3.01, 5.11, 7.01, 8.95, 10.89};   // Valores de la variable dependiente

    double m, b;   // Coeficientes de la regresión lineal
    double alpha = 0.01; // Tasa de aprendizaje
    int epochs = 1000;   // Número de iteraciones

    // Calcular la regresión lineal usando gradiente descendente
    calcularRegresion(datos, m, b, alpha, epochs);

    // Imprimir los coeficientes finales
    std::cout << "Resultado final: m = " << m << ", b = " << b << std::endl;

    // Liberar la memoria asignada a la estructura Datos
    liberarDatos(datos);

    return 0; // Terminar el programa
}