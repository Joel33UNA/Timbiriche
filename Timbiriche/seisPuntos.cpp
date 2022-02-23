/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "seisPuntos.h"

seisPuntos::seisPuntos() : campoComposite(5, 3)
{}

seisPuntos::~seisPuntos() {
}

string seisPuntos::toString() const {
	return campoComposite::toString();
}

bool seisPuntos::operator==(string cls2) {
	string cls = typeid(*this).name();
	return cls == cls2;
}