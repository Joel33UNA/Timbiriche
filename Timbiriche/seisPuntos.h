/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#include "campoComposite.h"
#pragma once
class seisPuntos : public campoComposite {
public:
	seisPuntos();
	virtual ~seisPuntos();
	void draw() { throw; }
	string toString() const;
	virtual bool operator == (string);
};

