/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "espacio2.h"
#include <sstream>
using std::stringstream;

espacio2::espacio2() 
{}

espacio2::~espacio2()
{}

string espacio2::toString() const {
	stringstream s;
	s << "  ";
	return s.str();
}

bool espacio2::operator==(string n2) {
	string n = typeid(*this).name();
	return n == n2;
}