/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "archivo.h"
#include <stdlib.h>
#include <sstream>
using std::stringstream;

archivo::archivo(string r, empresaDots* e) : ruta(r), dots(e) {}

archivo::~archivo() {}

void archivo::abrirEscritura(){
	txt.open(ruta.c_str(), ios::out);
}

void archivo::abrirLectura() {
	txt.open(ruta.c_str(), ios::in);
}

void archivo::cerrar() {
	txt.close();
}

void archivo::escribirString(string text, char del) {
	txt << text << del;
}

void archivo::escribirInt(int text, char del) {
	txt << text << del;
}

string archivo::recuperarString(char del) {
	string text;
	getline(txt, text, del);
	return text;
}

int archivo::recuperarInt(char del) {
	string text;
	getline(txt, text, del);
	int integer;
	stringstream s(text);
	s >> integer;
	return integer;
}

void archivo::guardarPartida(juego* j) {
	escribirString(j->archivos(), '\n');
}

void archivo::guardarPartidas(listaJuegos* lJ) {
	lJ->inicializarActual();
	juego* j = NULL;
	int n = lJ->getN();
	escribirInt(n, '\n');
	for (int i = 0; i < n; i++) {
		j = lJ->recuperarJuego();
		guardarPartida(j);
	}
}

juego* archivo::recuperarPartida() {
	juego* j = new juego();
	int nJuego = recuperarInt(' ');
	string player1 = recuperarString('\t');
	string player2 = recuperarString('\t');
	int nTableros = recuperarInt('\t');
	string tablero; campoComposite* cp = NULL;
	for (int i = 0; i < nTableros - 1; i++) {
		tablero = recuperarString(' ');
		if (tablero == "6") cp = new seisPuntos();
		if (tablero == "9") cp = new nuevePuntos();
		if (tablero == "15") cp = new quincePuntos();
		j->agregarAlContenedorTableros(cp);
	}
	tablero = recuperarString('\t');
	if (tablero == "6") cp = new seisPuntos();
	if (tablero == "9") cp = new nuevePuntos();
	if (tablero == "15") cp = new quincePuntos();
	j->agregarAlContenedorTableros(cp);
	int nJugadas = recuperarInt('\t');
	int entradax, entraday, salidax , saliday; 
	jugada* jug = NULL; coordenadas* corin = NULL; coordenadas* corout = NULL;
	for (int i = 0; i < nJugadas - 1; i++) {
		entradax = recuperarInt(' ');
		entraday = recuperarInt(' ');
		salidax = recuperarInt(' ');
		saliday = recuperarInt('\t');
		corin = new coordenadas(entradax, entraday);
		corout = new coordenadas(salidax, saliday);
		jug = new jugada(corin, corout);
		j->agregarJugada(jug);
	}
	entradax = recuperarInt(' ');
	entraday = recuperarInt(' ');
	salidax = recuperarInt(' ');
	saliday = recuperarInt('\n');
	corin = new coordenadas(entradax, entraday);
	corout = new coordenadas(salidax, saliday);
	jug = new jugada(corin, corout);
	j->agregarJugada(jug);
	jugador* jug1 = new jugador(player1, player1);
	jugador* jug2 = new jugador(player2, player2);
	j->agregarJugador(jug1);
	j->agregarJugador(jug2);
	j->establecerNumJuego(nJuego);
	return j;
}

listaJuegos* archivo::recuperarPartidas() {
	listaJuegos* lJ = new listaJuegos();
	juego* j = NULL;
	int n = recuperarInt('\n');
	for (int i = 0; i < n; i++) {
		j = recuperarPartida();
		lJ->agregar(j);
	}
	return lJ;
}