/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "componente.h"
class espacio2 : public componente {
public:
	espacio2();
	virtual ~espacio2();
	string toString() const;
	bool operator == (string);
	///////////////////////////////////////////
	virtual int getN() { throw; }
	virtual int getM() { throw; }
	virtual bool operator==(int) { throw; }
};

