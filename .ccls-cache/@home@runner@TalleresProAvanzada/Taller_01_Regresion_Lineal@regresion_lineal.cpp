// regresion_lineal.cpp
#include "regresion_lineal.h"
#include <iostream>
#include <fstream>
#include <cmath>

// Implementación de la función crearDatos
Datos* crearDatos(int n) {
    Datos* datos = new Datos;   // Crear una nueva estructura Datos
    datos->x.resize(n);         // Redimensionar el vector x para que tenga n elementos
    datos->y.resize(n);         // Redimensionar el vector y para que tenga n elementos
    datos->n = n;               // Asignar n al campo n de la estructura Datos
    return datos;               // Devolver el puntero a la estructura Datos
}

// Implementación de la función liberarDatos
void liberarDatos(Datos* datos) {
    delete datos;   // Liberar la memoria asignada a la estructura Datos
}

// Implementación de la función calcularRegresion
void calcularRegresion(Datos* datos, double& m, double& b, double alpha, int epochs) {
    m = 0.0;   // Inicializar el coeficiente m a 0
    b = 0.0;   // Inicializar el coeficiente b a 0

    // Bucle para realizar el gradiente descendente durante un número determinado de épocas
    for (int epoch = 0; epoch < epochs; ++epoch) {
        double db = 0.0;   // Inicializar el gradiente de b a 0
        double dm = 0.0;   // Inicializar el gradiente de m a 0

        // Bucle para calcular los gradientes sumando los errores de cada punto de datos
        for (int i = 0; i < datos->n; ++i) {
            double y_pred = m * datos->x[i] + b;   // Calcular la predicción de y
            double error = datos->y[i] - y_pred;   // Calcular el error de predicción
            db += error;                           // Sumar el error al gradiente de b
            dm += error * datos->x[i];             // Sumar el error ponderado por x al gradiente de m
        }

        db = -2 * db / datos->n;   // Calcular el valor medio del gradiente de b y ajustarlo
        dm = -2 * dm / datos->n;   // Calcular el valor medio del gradiente de m y ajustarlo

        // Actualizar los coeficientes m y b restando el producto de la tasa de aprendizaje y el gradiente
        b -= alpha * db;
        m -= alpha * dm;

        // Imprimir los valores de los coeficientes y los gradientes en cada época
        std::cout << "Epoch " << epoch << ": m = " << m << ", b = " << b << ", db = " << db << ", dm = " << dm << std::endl;
    }

    // Abrir un archivo de texto para guardar los errores cuadráticos medios
    std::ofstream mseFile("mse.txt");
    if (mseFile.is_open()) {
        // Calcular y escribir el error cuadrático medio de cada punto de datos
        for (int i = 0; i < datos->n; ++i) {
            double y_pred = m * datos->x[i] + b;   // Calcular la predicción de y
            double error = pow(datos->y[i] - y_pred, 2);   // Calcular el error cuadrático
            mseFile << error << std::endl;   // Escribir el error cuadrático en el archivo
        }
        mseFile.close();   // Cerrar el archivo
    }
}