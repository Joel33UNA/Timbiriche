/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "lineaVertical.h"
#include <sstream>
using std::stringstream;

lineaVertical::lineaVertical() : linea() {
}

lineaVertical::~lineaVertical() {}

string lineaVertical::toString()const {
	stringstream s;
	s << "|";
	return s.str();
}

bool lineaVertical::operator==(string n2) {
	string n = typeid(*this).name();
	return n == n2;
}