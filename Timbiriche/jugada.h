/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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
	bool compararCoordenadas(coordenadas*, coordenadas*); //M�todo para comparar las coordenadas con otra jugada
	string archivos();
};