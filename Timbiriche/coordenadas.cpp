/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "coordenadas.h"
#include <sstream>
using std::stringstream;

coordenadas::coordenadas(int x, int y) {
	this->x = x;
	this->y = y;
}

coordenadas::~coordenadas() {}

bool coordenadas::operator==(coordenadas& c) {
	return this->x == c.x && this->y == c.y;
}

int coordenadas::getX() { return x; }

int coordenadas::getY() { return y; }

string coordenadas::archivos(){
	stringstream s;
	s << x << ' ' << y;
	return s.str();
}
