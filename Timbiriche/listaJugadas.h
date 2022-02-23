/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/
#pragma once
#include "jugada.h"

class nodoJugadas {
private:
	jugada* dato;
	nodoJugadas* siguiente;
public:
	nodoJugadas(jugada*, nodoJugadas*);
	virtual ~nodoJugadas();
	void setDato(jugada*);
	void setSiguiente(nodoJugadas*);
	jugada* getDato();
	nodoJugadas* getSiguiente();
};

class listaJugadas {
private:
	nodoJugadas* primero;
	nodoJugadas* actual;
	int n;
public:
	listaJugadas();
	virtual ~listaJugadas();
	jugada* recuperarJugada();
	int getN();
	void agregar(jugada*);
	void inicializarActual();
	string archivos();
};

