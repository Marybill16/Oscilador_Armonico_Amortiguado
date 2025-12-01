set terminal pngcairo size 800,600
set output '../results/graficas/derivadas_grafico.png'
set xlabel 'Tiempo'
set ylabel 'Valores'
set key outside
plot '../results/listas/datos_derivadas.dat' using 1:2 with lines title 'Posicion', \
     '' using 1:3 with lines title 'velocidad', \
     '' using 1:4 with lines title 'momentum'
