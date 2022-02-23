/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "empresaDots.h"
#include <time.h>
#include <sstream>
using std::stringstream;

empresaDots::empresaDots() 
	: suscriptores(new coleccionJugadores(30)), partidas(new listaJuegos()), dia("domingo")
{
	codigo = generarCodigoAleatorio();
}

empresaDots::~empresaDots() { delete suscriptores, partidas; }

void empresaDots::establecerPartidas(listaJuegos* lJ){
	delete partidas;
	partidas = lJ;
}

juego* empresaDots::obtenerPartida(int id) {return partidas->obtenerPartida(id); }

listaJuegos* empresaDots::obtenerPartidas() { return partidas; }

void empresaDots::agregarJuego(juego* j) {
	partidas->agregar(j);
}

bool empresaDots::attach(jugador* j){
	return suscriptores->agregar(j);
}

void empresaDots::setCodigo() {
	static int d = 1;
	d++;
	if (d == 8) d = 1;
	if (d == 1) dia = "domingo";
	if (d == 2) dia = "lunes";
	if (d == 3) dia = "martes";
	if (d == 4) dia = "miercoles";
	if (d == 5) dia = "jueves";
	if (d == 6) dia = "viernes";
	if (d == 7) dia = "sabado";
	codigo = generarCodigoAleatorio();
	delete suscriptores;
	suscriptores = new coleccionJugadores(30);
}

string empresaDots::generarCodigoAleatorio() {
	srand((unsigned int)time(0));
	int ran = 1 + rand() % (10000);
	stringstream s;
	s << ran;
	return s.str();
}

void empresaDots::notify() {
	suscriptores->update(codigo);
}

bool empresaDots::vacio(){
	return suscriptores->vacio();
}

bool empresaDots::minimo(){
	return suscriptores->minimo();
}

bool empresaDots::minimo1() {
	return suscriptores->minimo1();
}

bool empresaDots::existenPartidas() {
	return partidas->existenPartidas();
}

bool empresaDots::existeJugador(string id){
	return suscriptores->existe(id);
}

bool empresaDots::existeJuego(int id) {
	return partidas->existe(id);
}

jugador* empresaDots::recuperarJugador(string id) {
	return suscriptores->recuperar(id);
}

string empresaDots::toString() {
	stringstream s;
	s << "______________________________\n";
	s << "______Empresa Timbiriche______\n";
	s << "C\242digo actual: " << codigo << '\n';
	s << "D\241a actual: " << dia << '\n';
	s << "Numero de suscriptores: " << suscriptores->getK() << '\n';
	s << "______________________________\n";
	s << suscriptores->toString() << '\n';
	return s.str();
}

string empresaDots::toStringPartidas(){
	stringstream s;
	s << "______________________________\n";
	s << "_____Imprimiendo partidas_____\n";
	s << "______________________________\n";
	s << partidas->toString() << '\n';
	return s.str();
}