/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "espacio1.h"
#include <sstream>
using std::stringstream;

espacio1::espacio1()
{}

espacio1::~espacio1()
{}

string espacio1::toString() const {
	stringstream s;
	s << " ";
	return s.str();
}

bool espacio1::operator==(string n2) {
	string n = typeid(*this).name();
	return n == n2;
}
