/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "componente.h"
class espacio1 : public componente {
public:
	espacio1();
	virtual ~espacio1();
	string toString()const;
	virtual bool operator == (string);
	////////////////////////////////////////
	virtual int getN() { throw; }
	virtual int getM() { throw; }
	virtual bool operator==(int) { throw; }

};

