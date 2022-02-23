/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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
