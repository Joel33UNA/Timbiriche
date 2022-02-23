/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "campoComposite.h"
#include <sstream>
using std::stringstream;

campoComposite::campoComposite(int n, int m) : componente() {
	this->n = n;
	this->m = m;
	tablero = new componente * *[n];
	for (int i = 0; i < n; i++)
		tablero[i] = new componente * [m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tablero[i][j] = nullptr;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				tablero[i][j] = new punto();
			if (i % 2 == 0 && j % 2 == 1)
				tablero[i][j] = new espacio2();
			if (i % 2 == 1 && j % 2 == 0)
				tablero[i][j] = new espacio1();
			if (i % 2 == 1 && j % 2 == 1)
				tablero[i][j] = new espacio2();
		}
}

campoComposite::~campoComposite(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			delete tablero[i][j];
	for (int i = 0; i < n; i++)
		delete[] tablero[i];
	delete[] tablero;
}

bool campoComposite::lleno() {
	string clase;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (tablero[i][j]) {
				clase = typeid(*(tablero[i][j])).name();
				if (clase == "class espacio1")
					return false;
				if (clase == "class espacio2")
					return false;
			}
		}
	return true;
}

int campoComposite::getN() { return n; }

int campoComposite::getM() { return m; }

int campoComposite::getT() { return n * m; }

void campoComposite::setN(int n) { this->n = n; }

void campoComposite::setM(int m) { this->m = m; }

string campoComposite::toString() const {
	string clase;
	stringstream s;

	s << "\t     ";
	for (int j = 0; j < (m + 1) / 2; j++)
		s << "[" << j << "]";
	s << '\n';
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			s << "\t [" << i / 2 << "]  ";
		else
			s << "\t      ";
		for (int j = 0; j < m; j++)
			if (tablero[i][j] != nullptr) {   //  Nueva modificacion
				s << tablero[i][j]->toString();
			}
			else {
				if (j % 2 == 0) {
					s << " ";
				}
				else {
					s << "  ";
				}
			}
		s << '\n';
	}
	return s.str();
}


componente*** campoComposite::getTablero() { return tablero; }

void campoComposite::setTablero(componente*** c) { tablero = c; }

