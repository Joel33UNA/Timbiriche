/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#include "nuevePuntos.h"

nuevePuntos::nuevePuntos() : campoComposite(5, 5)
{}

nuevePuntos::~nuevePuntos() {}

string nuevePuntos::toString() const {
	return campoComposite::toString();
}

bool nuevePuntos::operator==(string cls2) {
	string cls = typeid(*this).name();
	return cls == cls2;
}
