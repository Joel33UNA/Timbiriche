/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#pragma once
#include "jugador.h"
class coleccionJugadores{
private:
	jugador** vector;
	int n;
	int k;
public:
	coleccionJugadores(int);
	virtual ~coleccionJugadores();
	jugador* operator[](int);
	int getK();
	bool vacio();
	bool minimo();
	bool minimo1();
	bool existe(string);
	bool agregar(jugador*);
	void update(string);
	string jugador1();
	string jugador2();
	jugador* recuperar(string);
	string toString();
	string VS();
};
