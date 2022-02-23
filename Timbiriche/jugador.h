/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;

class jugador {
protected:
	string nombre;
	string identificacion;
	string codigo;
	double monedas;
	bool activo;
public:
	jugador(string, string);
	virtual ~jugador();
	bool operator == (string);
	void update(string);
	string toString();
	string obtenerNombre();
	void graphic();
};

