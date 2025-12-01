# ===== Makefile  =====
.PHONY: all build run doc clean

all: run doc            # o solo 'run' si no quiere depender de LaTeX

build:
	mkdir -p bin results scripts documents
	g++ src/main.cpp src/simular.cpp src/graficar.cpp -Iinclude -o bin/derivadas

run: build
	./bin/derivadas

doc:
	
	pdflatex -interaction=nonstopmode -output-directory=documents ../documentos/teoria.tex
clean:
	rm -f bin/box1D resultados/* scripts/*.gp documentos/*.aux documentos/*.log documentos/*.pdf
