/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#include "componente.h"
#pragma once
class punto : public componente {
public:
	punto();
	virtual ~punto();
	string toString() const;
	bool operator == (string);
	/////////////////////////////////////////////////////////////
	virtual int getN() { throw; }
	virtual int getM() { throw; }
	virtual bool operator==(int) { throw; }
};

