/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "lineaHorizontal.h"
#include <sstream>
using std::stringstream;

lineaHorizontal::lineaHorizontal() : linea()
{}

lineaHorizontal::~lineaHorizontal(){}

string lineaHorizontal::toString()const {
	stringstream s;
	s << "--";
	return s.str();
}

bool lineaHorizontal::operator==(string n2) {
	string n = typeid(*this).name();
	return n == n2;
}