/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "jugada.h"
#include <sstream>
using std::stringstream;

jugada::jugada(coordenadas* in, coordenadas* out)
	: entrada(in), salida(out)
{}

jugada::~jugada() {}

bool jugada::operator==(jugada& j2) {
	if (*this->entrada == *j2.entrada && *this->salida == *j2.salida)
		return true;
	else if (*this->entrada == *j2.salida && *this->salida == *j2.entrada)
		return true;
	else if (*this->salida == *j2.salida && *this->entrada == *j2.entrada)
		return true;
	else if (*this->salida == *j2.entrada && *this->entrada == *j2.salida)
		return true;
	else return false;
}

coordenadas* jugada::obtenerEntrada() { return entrada; }

coordenadas* jugada:: obtenerSalida() { return salida; }

bool jugada::compararCoordenadas(coordenadas* in, coordenadas* out) {
	if (*entrada == *in && *salida == *out)
		return true;
	else if (*entrada == *out && *salida == *in)
		return true;
	else return false;
}

string jugada::archivos() {
	stringstream s;
	s << entrada->archivos() << ' ' << salida->archivos();
	return s.str();
}
