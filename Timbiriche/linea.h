/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "componente.h"
class linea : public componente {
public:
	linea() {}
	virtual ~linea() {}
	virtual string toString() const = 0;
	virtual bool operator == (string) = 0;
	///////////////////////////////////////////////////////////////////
	virtual int getN() { throw; }
	virtual int getM() { throw; }
	virtual bool operator==(int) { throw; }
};
