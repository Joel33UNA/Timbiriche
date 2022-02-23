/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "campoComposite.h"
#pragma once
class nuevePuntos : public campoComposite {
public:
	nuevePuntos();
	virtual ~nuevePuntos();
	void draw() { throw; }
	string toString() const;
	virtual bool operator == (string);
};

