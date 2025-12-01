#include "../include/funciones.h"

#include <iostream>
#include <string>

using namespace std;

// Definir un tama?o m?ximo para los arreglos
const int MAX_SIZE = 240;
// Masa usada en el experimento (kg)
const double m = 0.145;

int main() {
    // Nombre del archivo de entrada y salida
    string archivoEntrada = "../results/listas/datos_posicion_tiempo.dat";
    string archivoSalida = "../results/listas/datos_derivadas.dat";

    // Arreglos para almacenar datos
    double tiempo[MAX_SIZE], posicion[MAX_SIZE];
    double velocidad[MAX_SIZE], momentum[MAX_SIZE];

    // Leer archivo de entrada
    int n = leerArchivo(archivoEntrada, tiempo, posicion);

    // Calcular derivadas
    calcularDerivadas(tiempo, posicion, velocidad, momentum, n);

    // Generar archivo con las derivadas 
    generarArchivoSalida(archivoSalida, tiempo, posicion, velocidad, momentum, n);

    // Graficar datos
    graficarDatos(archivoSalida);

    return 0;
}
