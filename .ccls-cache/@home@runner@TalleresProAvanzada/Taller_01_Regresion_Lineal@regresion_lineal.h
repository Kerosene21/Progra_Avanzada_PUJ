// regresion_lineal.h
// Definición de guardas para evitar inclusiones múltiples del archivo de cabecera
#ifndef REGRESION_LINEAL_H
#define REGRESION_LINEAL_H

// Incluir la librería vector para usar el contenedor vector
#include <vector>
using namespace std;

// Definición de la estructura Datos que contiene los vectores x, y y el número de puntos de datos n
struct Datos {
    vector<double> x;  // Vector que contiene los valores de la variable independiente
    vector<double> y;  // Vector que contiene los valores de la variable dependiente
    int n;             // Número de puntos de datos
};

// Declaración de la función para crear una estructura Datos con n puntos
Datos* crearDatos(int n);

// Declaración de la función para liberar la memoria asignada a una estructura Datos
void liberarDatos(Datos* datos);

// Declaración de la función para calcular la regresión lineal usando gradiente descendente
void calcularRegresion(Datos* datos, double& m, double& b, double alpha, int epochs);

// Fin de las guardas
#endif // REGRESION_LINEAL_H