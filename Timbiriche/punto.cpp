/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#include "punto.h"
#include <sstream>
using std::stringstream;

punto::punto() : componente()
{}

punto::~punto(){}

string punto::toString() const{
	stringstream s;
	s << char(254);
	return s.str();
}

bool punto::operator==(string n2) {
	string n = typeid(*this).name();
	return n == n2;
}