/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "quincePuntos.h"

quincePuntos::quincePuntos() : campoComposite(9, 5)
{}

quincePuntos::~quincePuntos() {
}

string quincePuntos::toString() const {
	return campoComposite::toString();
}

bool quincePuntos::operator==(string cls2) {
	string cls = typeid(*this).name();
	return cls == cls2;
}