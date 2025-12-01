#include "../include/funciones.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>


using namespace std;

void graficarDatos(const string &archivoSalida) {
    string script = 
        "set terminal pngcairo size 800,600\n"
        "set output '../resultados/graficas/derivadas_grafico.png'\n"
        "set xlabel 'Tiempo'\n"
        "set ylabel 'Valores'\n"
        "set key outside\n"
        "plot '" + archivoSalida + "' using 1:2 with lines title 'Posicion', \\\n"
        "     '' using 1:3 with lines title 'velocidad', \\\n"
        "     '' using 1:4 with lines title 'momentum'\n";
    
    ofstream scriptFile("../scripts/graficar_derivadas.gnuplot");
    if (scriptFile.is_open()) {
        scriptFile << script;
        scriptFile.close();
        system("gnuplot ../scripts/graficar_derivadas.gnuplot");
        cout << "Gr?fico generado: derivadas_grafico.png" << endl;
    } else {
        cerr << "Error: No se pudo crear el archivo de script gnuplot" << endl;
    }
}
