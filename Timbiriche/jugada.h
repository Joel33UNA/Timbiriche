/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "coordenadas.h"
#include <string>
using std::string;
#pragma once
class jugada {
private:
	coordenadas* entrada;
	coordenadas* salida;
public:
	jugada(coordenadas*, coordenadas*);
	virtual ~jugada();
	bool operator == (jugada&);
	coordenadas* obtenerEntrada();
	coordenadas* obtenerSalida();
	bool compararCoordenadas(coordenadas*, coordenadas*); //Método para comparar las coordenadas con otra jugada
	string archivos();
};