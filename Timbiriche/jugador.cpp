/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "jugador.h"
#include <sstream>
using std::stringstream;

jugador::jugador(string nom, string id) 
	: nombre(nom), identificacion(id), codigo("..."), monedas(1000), activo(true)
{}

jugador::~jugador(){}

bool jugador::operator==(string id) {
	return (this->identificacion == id);
}

void jugador::update(string cod) {
	codigo = cod;
}

string jugador::toString() {
	stringstream s;
	s << "...........................\n";
	s << "Jugador: " << nombre << '\n';
	s << "Identificaci\242n: " << identificacion << '\n';
	s << "C\242digo asignado: " << codigo << '\n';
	if (activo)
		s << "Se encuentra activo(a)\n";
	else
		s << "Se encuentra inactivo(a)\n";
	//s << "Monedas: " << monedas << '\n';
	s << "............................\n";
	return s.str();
}

string jugador::obtenerNombre() {
	return nombre;
}

void jugador::graphic()
{
}
