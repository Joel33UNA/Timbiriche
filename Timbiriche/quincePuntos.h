/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "campoComposite.h"
#pragma once
class quincePuntos : public campoComposite {
public:
	quincePuntos();
	virtual ~quincePuntos();
	void draw() { throw; }
	string toString() const;
	virtual bool operator == (string);
};

