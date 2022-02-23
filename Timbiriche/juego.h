/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "jugador.h"
#include "jugada.h"
#include "estrategiaAleatoria.h"
#include "coleccionJugadores.h"
#include "listaJugadas.h"
#include "campoJuego.h"
#include "estrategiaAleatoria.h"
#include "estrategiaCentral.h"
#include "estrategiaCercana.h"
#include "estrategiaIslas.h"
#include "estrategiaPeriferica.h"
#include "campoComposite.h"
#include "coordenadas.h"
#include "interfaz.h"
#include "utiles.h"
#include <ostream>
using std::ostream;
#pragma once

class juego{
private:
	coleccionJugadores* jugadores;
	listaJugadas* jugadas;
	campoJuego* tablero;
	int numJuego;
	string player1;
	string player2;
public:
	juego();
	virtual ~juego();
	friend ostream& operator << (ostream&, juego&);
	componente*** getTablero();
	int getN();
	int getM();
	void setJugadas(listaJugadas*);
	bool operator == (int);
	void agregarAlContenedorTableros(campoComposite*);
	jugada* recuperarJugada();
	void agregarJugador(jugador*);
	void agregarJugada(jugada*);
	string jugador1();
	string jugador2();
	void establecerNumJuego(int);
	void agregarAlContenedor(campoComposite*);
	void jugarVSHumano();
	void jugarVSMaquina(estrategia*);
	estrategia* cambiarEstrategia();
	string comprobarGanador();
	string toString() const;
	void partida(coordenadas*, coordenadas*);
	void draw();
	bool rellenar(bool);
	void reproducir(); //.........
	string toStringJuego();
	string archivos();
};

