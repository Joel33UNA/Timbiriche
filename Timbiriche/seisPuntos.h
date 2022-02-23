/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
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

