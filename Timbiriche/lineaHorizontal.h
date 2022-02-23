/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "linea.h"
class lineaHorizontal : public linea {
public:
	lineaHorizontal();
	virtual ~lineaHorizontal();
	string toString() const;
	bool operator==(string n2);
};

