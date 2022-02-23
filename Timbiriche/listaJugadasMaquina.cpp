/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "listaJugadasMaquina.h"
#include <sstream>
using std::stringstream;

nodoMaquina::nodoMaquina(jugada* d,  nodoMaquina* s) : dato(d), siguiente(s)
{}

nodoMaquina::~nodoMaquina() {}

void nodoMaquina::setDato(jugada* d) { dato = d; }

void nodoMaquina::setSiguiente(nodoMaquina* s) { siguiente = s; }

jugada* nodoMaquina::getDato() { return dato; }

nodoMaquina* nodoMaquina::getSiguiente() { return siguiente; }

listaJugadasMaquina::listaJugadasMaquina() : primero(nullptr), actual(nullptr), n(0)
{}

listaJugadasMaquina::~listaJugadasMaquina(){
	nodoMaquina* actuall = NULL;
	while (primero) {
		actual = primero;
		n--;
		primero = actual->getSiguiente();
		delete actuall;
	}
}

int listaJugadasMaquina::getN() { return n; }

bool listaJugadasMaquina::compararCoordenadas(coordenadas* x1y1, coordenadas* x2y2){
	nodoMaquina* aux = primero;
	jugada* j;
	while (aux) {
		j = aux->getDato();
		if (j->compararCoordenadas(x1y1, x2y2))
			return true;
		aux = aux->getSiguiente();
	}
	return false;
}

bool listaJugadasMaquina::existenLegales() {
	if (n != 0)
		return true;
	else return false;
}

void listaJugadasMaquina::agregar(jugada* j){
	if (!primero) {
		if (!existe(j)) {
			primero = new nodoMaquina(j, primero);
			n++;
		}
	}
	else if (!existe(j)){
		nodoMaquina* aux = primero;
		while (aux->getSiguiente())
			aux = aux->getSiguiente();
		aux->setSiguiente(new nodoMaquina(j, NULL));
		n++;
	}
}

bool listaJugadasMaquina::existe(jugada* j){
	if (!primero)
		return false;
	else {
		nodoMaquina* aux = primero;
		jugada* dato;
		while (aux) {
			dato = aux->getDato();
			if (*dato == *j)
				return true;
			aux = aux->getSiguiente();
		}
		return false;
	}
}

jugada* listaJugadasMaquina::obtenerJugadaPos(int pos){
	inicializarActual();
	int contador = 1;
	while (actual && contador < pos) {
		actual = actual->getSiguiente();
		contador++;
	}
	if (contador == pos)
		return actual->getDato();
	else return nullptr;
}

void listaJugadasMaquina::inicializarActual() {
	actual = primero;
}
