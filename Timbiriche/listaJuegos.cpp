/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "listaJuegos.h"
#include <sstream>
using std::stringstream;

nodoJuego::nodoJuego(juego* d, nodoJuego* s) : dato(d), siguiente(s)
{}

nodoJuego::~nodoJuego(){}

void nodoJuego::setDato(juego* d) { dato = d; }

void nodoJuego::setSiguiente(nodoJuego* s) { siguiente = s; }

juego* nodoJuego::getDato() { return dato; }

nodoJuego* nodoJuego::getSiguiente() { return siguiente; }

listaJuegos::listaJuegos() : primero(nullptr), actual(nullptr), n(0)
{}

listaJuegos::~listaJuegos(){
	if (primero) delete primero;
	if (actual) delete actual;
}

int listaJuegos::getN() { return n; }

juego* listaJuegos::recuperarJuego() {
	juego* j = actual->getDato();
	actual = actual->getSiguiente();
	return j;
}

bool listaJuegos::existe(int id) {
	inicializarActual();
	juego* j;
	while (actual) {
		j = actual->getDato();
		if (*j == id) return true;
		actual = actual->getSiguiente();
	}
	return false;
}

bool listaJuegos::existenPartidas() {
	if (n != 0)
		return true;
	else return false;
}

void listaJuegos::agregar(juego* j) {
	if (!primero) {
		primero = new nodoJuego(j, primero);
		n++;
	}
	else {
		nodoJuego* aux = primero;
		while (aux->getSiguiente())
			aux = aux->getSiguiente();
		aux->setSiguiente(new nodoJuego(j, NULL));
		n++;
	}
}

juego* listaJuegos::obtenerPartida(int id) {
	inicializarActual();
	juego* j;
	while (actual) {
		j = actual->getDato();
		if (*j == id) return j;
		actual = actual->getSiguiente();
	}
	return nullptr;
}

void listaJuegos::inicializarActual() {
	actual = primero;
}

string listaJuegos::toString(){
	stringstream s;
	inicializarActual();
	juego* j = NULL;
	while (actual) {
		j = actual->getDato();
		s << j->toStringJuego() << '\n';
		actual = actual->getSiguiente();
	}
	return s.str();
}
