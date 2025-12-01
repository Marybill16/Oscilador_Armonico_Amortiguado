# ===== Makefile  =====
.PHONY: all build run doc clean

all: run doc            # o solo 'run' si no quiere depender de LaTeX

build:
	mkdir -p bin results scripts documents
	g++ src/main.cpp src/simular.cpp src/graficar.cpp -Iinclude -o bin/derivadas

run: build
	cd bin && ./derivadas

doc:
	
	pdflatex -interaction=nonstopmode -output-directory=documents ../documents/teoria.tex
clean:
	rm -f bin/box1D results/* scripts/*.gp documents/*.aux documents/*.log documents/*.pdf
