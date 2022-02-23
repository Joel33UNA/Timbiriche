/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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