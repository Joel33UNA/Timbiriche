/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "jugador.h"
#include "juego.h"
#include "coleccionJugadores.h"
#include "listaJuegos.h"
#pragma once
class empresaDots {
private:
	coleccionJugadores* suscriptores;
	listaJuegos* partidas;
	string codigo;
	string dia;
public:
	empresaDots();
	virtual ~empresaDots();
	void establecerPartidas(listaJuegos*);
	juego* obtenerPartida(int);
	listaJuegos* obtenerPartidas();
	void agregarJuego(juego*);
	bool attach(jugador*);
	void setCodigo();
	string generarCodigoAleatorio();
	void notify();
	bool vacio();
	bool minimo();
	bool minimo1();
	bool existenPartidas();
	bool existeJugador(string);
	bool existeJuego(int);
	jugador* recuperarJugador(string);
	string toString();
	string toStringPartidas();
};

