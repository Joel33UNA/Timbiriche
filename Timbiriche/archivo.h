/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#pragma once
#include "empresaDots.h"
#include "seisPuntos.h"
#include "nuevePuntos.h"
#include "quincePuntos.h"
#include "jugada.h"
#include "coordenadas.h"
#include "jugador.h"
#include <string>
#include <fstream>
using namespace std;

class archivo {
private:
	string ruta;
	fstream txt;
	empresaDots* dots;
public:
	archivo(string, empresaDots*);
	virtual ~archivo();
	void abrirEscritura();
	void abrirLectura();
	void cerrar();
	void escribirString(string, char);
	void escribirInt(int, char);
	string recuperarString(char del);
	int recuperarInt(char del);
	void guardarPartida(juego*);
	void guardarPartidas(listaJuegos*);
	juego* recuperarPartida();
	listaJuegos* recuperarPartidas();
};

