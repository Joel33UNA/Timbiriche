/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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