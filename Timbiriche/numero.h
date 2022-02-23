/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "componente.h"
class numero : public componente {
private:
	int num;
public:
	numero(int);
	virtual ~numero();
	string toString() const;
	bool operator ==(int);
	bool operator == (string);
	///////////////////////////////
	virtual int getN() { throw; }
	virtual int getM() { throw; }
	
};

