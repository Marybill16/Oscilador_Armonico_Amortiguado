#include "../include/funciones.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

// Definir un tama?o m?ximo para los arreglos
const int MAX_SIZE = 240;
// Masa usada en el experimento (kg)
const double m = 0.145;

int leerArchivo(const string &nombreArchivo, double tiempo[], double posicion[]) {
    ifstream archivo(nombreArchivo.c_str());
    
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de entrada." << endl;
        exit(1);
    }
    
    double t, x;
    int i = 0;
    
    while (archivo >> t >> x) {
        if (i >= MAX_SIZE) {
            cerr << "Error: El archivo contiene más datos de los permitidos por el tamaño máximo." << endl;
            exit(1);
        }
        
        tiempo[i] = t;
        posicion[i] = x;
        i++;
    }
    archivo.close();
    
    return i; // Devuelve el número de datos leídos
}

void calcularDerivadas(const double tiempo[], const double posicion[], double velocidad[], double momentum[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0 && i < n - 1) { // Derivada centrada
            velocidad[i] = (posicion[i + 1] - posicion[i - 1]) / (tiempo[i + 1] - tiempo[i - 1]);
        } else {
            velocidad[i] = 0.0; // No se puede calcular para los extremos
        }
    }
    for (int i = 0; i < n; ++i){
    	momentum[i] = velocidad[i] * m;
	}
}

void generarArchivoSalida(const string &archivoSalida, const double tiempo[], 
                          const double posicion[], const double velocidad[], const double momentum[], int n) {
    ofstream archivo(archivoSalida.c_str());
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de salida." << endl;
        exit(1);
    }
    
    archivo << "# Tiempo\tPosicion\tVelocidad\tMomentum" << endl;
    for (int i = 0; i < n; ++i) {
        archivo << fixed << setprecision(6) << tiempo[i] << "\t" << posicion[i] << "\t" << velocidad[i] << "\t" << momentum[i] << endl;
    }
    archivo.close();
    cout << "Archivo generado: " << archivoSalida << endl;
}
