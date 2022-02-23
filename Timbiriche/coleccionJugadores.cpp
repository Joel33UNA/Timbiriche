/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "coleccionJugadores.h"
#include <sstream>
using std::stringstream;

coleccionJugadores::coleccionJugadores(int tam) {
	n = tam;
	k = 0;
	vector = new jugador * [n];
	for (int i = 0; i < n; i++)
		vector[i] = NULL;
}

coleccionJugadores::~coleccionJugadores() {
	for (int i = 0; i < k; i++)
		delete vector[i];
	delete[] vector;
}

jugador* coleccionJugadores::operator[](int pos) {
	return vector[pos];
}

int coleccionJugadores::getK() { return k; }

bool coleccionJugadores::vacio() {
	return k == 0;
}

bool coleccionJugadores::minimo(){
	return k > 1;
}

bool coleccionJugadores::minimo1() {
	return k > 0;
}

bool coleccionJugadores::existe(string id) {
	if (k == 0) return false;
	else
		for (int i = 0; i < k; i++)
			if (*vector[i] == id)
				return true;
	return false;
}

bool coleccionJugadores::agregar(jugador* dato) {
	if (k < n) { 
		vector[k++] = dato; 
		return true; 
	}
	else return false;
}

void coleccionJugadores::update(string cod) {
	for (int i = 0; i < k; i++)
		vector[i]->update(cod);
}

string coleccionJugadores::jugador1() {
	return vector[0]->obtenerNombre();
}

string coleccionJugadores::jugador2() {
	return vector[1]->obtenerNombre();
}

jugador* coleccionJugadores::recuperar(string id) {
	for (int i = 0; i < k; i++)
		if (*vector[i] == id)
			return vector[i];
	return nullptr;
}

string coleccionJugadores::toString() {
	stringstream s;
	for (int i = 0; i < k; i++)
		s << i + 1 << ") " << vector[i]->toString() << '\n';
	return s.str();
}

string coleccionJugadores::VS() {
	stringstream s;
	s << vector[0]->obtenerNombre() << "\tVS\t" << vector[1]->obtenerNombre() << "\n\n";
	return s.str();
}