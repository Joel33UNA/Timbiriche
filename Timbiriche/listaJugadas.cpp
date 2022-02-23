/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "listaJugadas.h"
#include <sstream>
using std::stringstream;

nodoJugadas::nodoJugadas(jugada* d, nodoJugadas* s) : dato(d), siguiente(s)
{}

nodoJugadas::~nodoJugadas() {}

void nodoJugadas::setDato(jugada* d) { dato = d; }

void nodoJugadas::setSiguiente(nodoJugadas* s) { siguiente = s; }

jugada* nodoJugadas::getDato() { return dato; }

nodoJugadas* nodoJugadas::getSiguiente() { return siguiente; }


listaJugadas::listaJugadas() : primero(nullptr), actual(nullptr), n(0)
{}

listaJugadas::~listaJugadas() {
	if (primero) delete primero;
	if (actual) delete actual;
}

jugada* listaJugadas::recuperarJugada() { // INICIALIZAR ACTUAL ANTES, SIEMPRE!
	jugada* j = actual->getDato();
	actual = actual->getSiguiente();
	return j;
}

int listaJugadas::getN() {
	return n;
}

void listaJugadas::agregar(jugada* j) {
	if (!primero){
		primero = new nodoJugadas(j, primero);
		n++;
	}
	else {
		nodoJugadas* aux = primero;
		while (aux->getSiguiente())
			aux = aux->getSiguiente();
		aux->setSiguiente(new nodoJugadas(j, NULL));
		n++;
	}
}

void listaJugadas::inicializarActual() {
	actual = primero;
}

string listaJugadas::archivos() {
	inicializarActual();
	stringstream s;
	jugada* j;
	while (actual) {
		j = actual->getDato();
		if (actual->getSiguiente() == NULL)
			s << j->archivos(); // SI LLEGAMOS AL FINAL, PONDREMOS UN SALTO DE LINEA MANUALMENTE
		else
			s << j->archivos() << '\t'; // DE LO CONTRARIO CONTINUAREMOS ESCRIBIENDO TABS
		actual = actual->getSiguiente();
	}
	return s.str();
}
