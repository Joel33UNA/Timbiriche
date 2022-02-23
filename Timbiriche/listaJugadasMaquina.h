/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/
#pragma once
#include "jugada.h"

class nodoMaquina {
private:
	jugada* dato;
	nodoMaquina* siguiente;
public:
	nodoMaquina(jugada*, nodoMaquina*);
	virtual ~nodoMaquina();
	void setDato(jugada*);
	void setSiguiente(nodoMaquina*);
	jugada* getDato();
	nodoMaquina* getSiguiente();
};

class listaJugadasMaquina {
private:
	nodoMaquina* primero;
	nodoMaquina* actual;
	int n;
public:
	listaJugadasMaquina();
	virtual ~listaJugadasMaquina();
	int getN();
	bool compararCoordenadas(coordenadas*, coordenadas*);
	bool existenLegales();
	void agregar(jugada*);
	bool existe(jugada*);
	jugada* obtenerJugadaPos(int);
	void inicializarActual();
};
