/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "numero.h"
#include <sstream>
using std::stringstream;

numero::numero(int x) : num(x), componente()
{}

numero::~numero() {}

string numero::toString() const{
	stringstream s;
	s << num << " ";
	return s.str();
}

bool numero::operator==(int x) {
	return num == x;
}

bool numero::operator==(string n2) {
	string n = typeid(*this).name();
	return n == n2;
}
