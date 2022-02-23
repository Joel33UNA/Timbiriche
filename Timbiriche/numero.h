/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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

