#pragma once
#include <string>

using namespace std;

int leerArchivo(const string &nombreArchivo, double tiempo[], double posicion[]);

void calcularDerivadas(const double tiempo[], const double posicion[], double velocidad[], double momentum[], int n);

void generarArchivoSalida(const string &archivoSalida, const double tiempo[], 
                         const double posicion[], const double velocidad[], const double momentum[], int n);
                         
void graficarDatos(const string &archivoSalida);
