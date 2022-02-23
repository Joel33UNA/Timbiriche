/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/
#pragma once
#include "juego.h"

class nodoJuego {
private:
	juego* dato;
	nodoJuego* siguiente;
public:
	nodoJuego(juego*, nodoJuego*);
	virtual ~nodoJuego();
	void setDato(juego*);
	void setSiguiente(nodoJuego*);
	juego* getDato();
	nodoJuego* getSiguiente();
};

class listaJuegos{
private:
	nodoJuego* primero;
	nodoJuego* actual;
	int n;
public:
	listaJuegos();
	virtual ~listaJuegos();
	int getN();
	juego* recuperarJuego();
	bool existe(int);
	bool existenPartidas();
	void agregar(juego*);
	juego* obtenerPartida(int);
	void inicializarActual();
	string toString();
};

