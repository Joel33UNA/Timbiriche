/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "linea.h"
class lineaVertical : public linea {
public:
	lineaVertical();
	virtual ~lineaVertical();
	string toString() const;
	bool operator==(string n2);
};

