/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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

