/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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

