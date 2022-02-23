/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "juego.h"
#include "utiles.h"
#include "interfaz.h"
#include <sstream>
using std::stringstream;

juego::juego() 
	: jugadores(new coleccionJugadores(2)), tablero(new campoJuego()), player1(""), player2(""),
	jugadas(new listaJugadas())
{
	static int n = 1;
	numJuego = n;
	n++;
}

juego::~juego() { delete jugadores, tablero, jugadas; }

ostream& operator<<(ostream& out, juego& j) {
	out << j.toString();
	return out;
}

componente*** juego::getTablero(){
	return tablero->getTablero();
}

int juego::getN() {
	return tablero->getN();
}

int juego::getM() {
	return tablero->getM();
}

void juego::setJugadas(listaJugadas* lJ) {
	delete jugadas;
	jugadas = lJ;
}

bool juego::operator == (int id) {
	return this->numJuego == id;
}

void juego::agregarAlContenedorTableros(campoComposite* c) {
	tablero->agregarAlContenedor(c);
}

jugada* juego::recuperarJugada() {
	return jugadas->recuperarJugada();
}

void juego::agregarJugador(jugador* j) {
	jugadores->agregar(j);
	if (jugadores->getK() == 1)
		player1 = jugadores->jugador1();
	if (jugadores->getK() == 2)
		player2 = jugadores->jugador2();
}

void juego::agregarJugada(jugada* j){
	jugadas->agregar(j);
}

string juego::jugador1() {
	return jugadores->jugador1();
}

string juego::jugador2() {
	return jugadores->jugador2();
}

void juego::establecerNumJuego(int n) {
	numJuego = n;
}

void juego::agregarAlContenedor(campoComposite* c){
	tablero->agregarAlContenedor(c);
}

void juego::jugarVSHumano() {
	string aux; stringstream s1, s2;
	player1 = jugador1(); player2 = jugador2();
	s1 << "\n\nJuega " << player1 << '\n';
	s2 << "\n\nJuega " << player2 << '\n';
	string juega = s1.str();
	coordenadas* c1 = NULL;
	coordenadas* c2 = NULL;
	bool player = 0;
	while (!tablero->lleno()) {
		utiles::limpiar();
		utiles::imprimir(toString());
		utiles::imprimir(juega);
		utiles::imprimir("\nDigite la primera coordenada x (fila): ");
		int x1 = utiles::leerEntero();
		utiles::imprimir("Digite la primera coordenada y (columna): ");
		int y1 = utiles::leerEntero();
		utiles::imprimir("Digite la segunda coordenada x (fila): ");
		int x2 = utiles::leerEntero();
		utiles::imprimir("Digite la segunda coordenada y (columna): ");
		int y2 = utiles::leerEntero();
		c1 = new coordenadas(x1, y1);
		c2 = new coordenadas(x2, y2);
		if (tablero->partida(c1, c2)) {
			if (!rellenar(player)) { // SI NO RELLENÓ CAJITA, ENTONCES CAMBIAMOS DE JUGADOR
				if (player == 0) {
					juega = s2.str();
					player = 1;
				}
				else {
					juega = s1.str();
					player = 0;
				}
			}
			agregarJugada(new jugada(c1, c2));
		}
		else {
			utiles::imprimir("\nCoordenadas incorrectas...");
			utiles::esperar(1500);
		}
	}
	utiles::limpiar();
	utiles::imprimir(toString());
	if (comprobarGanador() == "EMPATE")
		utiles::imprimir("\nEs un empate!");
	else {
		utiles::imprimir("\nEl ganador es: ");
		utiles::imprimir(comprobarGanador());
	}
	utiles::pausa(); // SI LLEGA ACÁ ES QUE SE LLENÓ LA MATRIX
}

void juego::jugarVSMaquina(estrategia* e) {
	estrategia* nueva = NULL;
	bool cambio = false;
	while (true) {
		if (cambio == true) {
			delete e;
			e = cambiarEstrategia();
			cambio = false;
		}
		if (*e == "class estrategiaAleatoria") {
			string aux; stringstream s1, s2;
			player1 = jugador1(); player2 = jugador2();
			s1 << "\n\nJuega " << player1 << '\n';
			s2 << "\n\nJuega " << player2 << '\n';
			string juega = s1.str();
			coordenadas* c1 = NULL;
			coordenadas* c2 = NULL;
			jugada* j = NULL;
			bool player = 0;
			while (!tablero->lleno()) {
				if (player == 0) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Aleatoria->");
					utiles::imprimir("\nSi desea cambiar estrategia digite \"-1\" en todas las coordenadas...");
					utiles::imprimir("\n\nDigite la primera coordenada x (fila): ");
					int x1 = utiles::leerEntero();
					utiles::imprimir("Digite la primera coordenada y (columna): ");
					int y1 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada x (fila): ");
					int x2 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada y (columna): ");
					int y2 = utiles::leerEntero();
					if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
						cambio = true;
						break;
					}
					c1 = new coordenadas(x1, y1);
					c2 = new coordenadas(x2, y2);
					if (tablero->partida(c1, c2)) {
						if (!rellenar(player)) { // SI NO RELLENÓ CAJITA, ENTONCES CAMBIAMOS DE JUGADOR
							juega = s2.str();
							player = 1;
						}
						agregarJugada(new jugada(c1, c2));
					}
					else {
						utiles::imprimir("\nCoordenadas incorrectas...");
						utiles::esperar(1500);
					}
				}
				if (player == 1) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Aleatoria->");
					e->registrarJugadasLegales();
					utiles::imprimir("\n\nPensando...");
					utiles::esperar(1000);
					j = e->recuperarJugada();
					tablero->partida(j->obtenerEntrada(), j->obtenerSalida());
					if (!rellenar(player)) {
						juega = s1.str();
						player = 0;
					}
					agregarJugada(j);
				}
			}
			if (cambio == false) {
				utiles::limpiar();
				utiles::imprimir(toString());
				if (comprobarGanador() == "EMPATE")
					utiles::imprimir("\nEs un empate!");
				else {
					utiles::imprimir("\nEl ganador es: ");
					utiles::imprimir(comprobarGanador());
				}
				utiles::pausa();
				break;
			}
		}
		if (*e == "class estrategiaPeriferica") {
			string aux; stringstream s1, s2;
			player1 = jugador1(); player2 = jugador2();
			s1 << "\n\nJuega " << player1 << '\n';
			s2 << "\n\nJuega " << player2 << '\n';
			string juega = s1.str();
			coordenadas* c1 = NULL;
			coordenadas* c2 = NULL;
			jugada* j = NULL;
			bool player = 0;
			while (!tablero->lleno()) {
				if (player == 0) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Periferica->");
					utiles::imprimir("\nSi desea cambiar estrategia digite \"-1\" en todas las coordenadas...");
					utiles::imprimir("\n\nDigite la primera coordenada x (fila): ");
					int x1 = utiles::leerEntero();
					utiles::imprimir("Digite la primera coordenada y (columna): ");
					int y1 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada x (fila): ");
					int x2 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada y (columna): ");
					int y2 = utiles::leerEntero();
					c1 = new coordenadas(x1, y1);
					c2 = new coordenadas(x2, y2);
					if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
						cambio = true;
						break;
					}
					if (tablero->partida(c1, c2)) {
						if (!rellenar(player)) { // SI NO RELLENÓ CAJITA, ENTONCES CAMBIAMOS DE JUGADOR
							juega = s2.str();
							player = 1;
						}
						agregarJugada(new jugada(c1, c2));
					}
					else {
						utiles::imprimir("\nCoordenadas incorrectas...");
						utiles::esperar(1500);
					}
				}
				if (player == 1) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Periferica->");
					e->registrarJugadasIlegales();
					e->registrarJugadasLegales();
					utiles::imprimir("\n\nPensando...");
					utiles::esperar(1000);
					if (e->haycajita())
						j = e->haycajita();
					else
						j = e->recuperarJugada();
					tablero->partida(j->obtenerEntrada(), j->obtenerSalida());
					if (!rellenar(player)) {
						juega = s1.str();
						player = 0;
					}
					agregarJugada(j);
				}
			}
			if (cambio == false) {
				utiles::limpiar();
				utiles::imprimir(toString());
				if (comprobarGanador() == "EMPATE")
					utiles::imprimir("\nEs un empate!");
				else {
					utiles::imprimir("\nEl ganador es: ");
					utiles::imprimir(comprobarGanador());
				}
				utiles::pausa();
				break;
			}
		}
		if (*e == "class estrategiaCercana") {
			string aux; stringstream s1, s2;
			player1 = jugador1(); player2 = jugador2();
			s1 << "\n\nJuega " << player1 << '\n';
			s2 << "\n\nJuega " << player2 << '\n';
			string juega = s1.str();
			coordenadas* c1 = NULL;
			coordenadas* c2 = NULL;
			jugada* j = NULL;
			jugada* jugadaHumano = NULL;
			bool player = 0;
			while (!tablero->lleno()) {
				if (player == 0) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Cercana->");
					utiles::imprimir("\nSi desea cambiar estrategia digite \"-1\" en todas las coordenadas...");
					utiles::imprimir("\n\nDigite la primera coordenada x (fila): ");
					int x1 = utiles::leerEntero();
					utiles::imprimir("Digite la primera coordenada y (columna): ");
					int y1 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada x (fila): ");
					int x2 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada y (columna): ");
					int y2 = utiles::leerEntero();
					if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
						cambio = true;
						break;
					}
					c1 = new coordenadas(x1, y1);
					c2 = new coordenadas(x2, y2);
					if (tablero->partida(c1, c2)) {
						if (!rellenar(player)) { // SI NO RELLENÓ CAJITA, ENTONCES CAMBIAMOS DE JUGADOR
							juega = s2.str();
							player = 1;
						}
						jugadaHumano = new jugada(c1, c2);
						agregarJugada(jugadaHumano);
					}
					else {
						utiles::imprimir("\nCoordenadas incorrectas...");
						utiles::esperar(1500);
					}
				}
				if (player == 1) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Cercana->");
					e->establecerJugadaRival(jugadaHumano);
					e->registrarJugadasIlegales();
					e->registrarJugadasLegales();
					utiles::imprimir("\n\nPensando...");
					utiles::esperar(1000);
					if (e->haycajita())
						j = e->haycajita();
					else
						j = e->recuperarJugada();
					tablero->partida(j->obtenerEntrada(), j->obtenerSalida());
					if (!rellenar(player)) {
						juega = s1.str();
						player = 0;
					}
					agregarJugada(j);
				}
			}
			if (cambio == false) {
				utiles::limpiar();
				utiles::imprimir(toString());
				if (comprobarGanador() == "EMPATE")
					utiles::imprimir("\nEs un empate!");
				else {
					utiles::imprimir("\nEl ganador es: ");
					utiles::imprimir(comprobarGanador());
				}
				utiles::pausa();
				break;
			}
		}
		if (*e == "class estrategiaCentral") {
			string aux; stringstream s1, s2;
			player1 = jugador1(); player2 = jugador2();
			s1 << "\n\nJuega " << player1 << '\n';
			s2 << "\n\nJuega " << player2 << '\n';
			string juega = s1.str();
			coordenadas* c1 = NULL;
			coordenadas* c2 = NULL;
			jugada* j = NULL;
			bool player = 0;
			while (!tablero->lleno()) {
				if (player == 0) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Central->");
					utiles::imprimir("\nSi desea cambiar estrategia digite \"-1\" en todas las coordenadas...");
					utiles::imprimir("\n\nDigite la primera coordenada x (fila): ");
					int x1 = utiles::leerEntero();
					utiles::imprimir("Digite la primera coordenada y (columna): ");
					int y1 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada x (fila): ");
					int x2 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada y (columna): ");
					int y2 = utiles::leerEntero();
					if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
						cambio = true;
						break;
					}
					c1 = new coordenadas(x1, y1);
					c2 = new coordenadas(x2, y2);
					if (tablero->partida(c1, c2)) {
						if (!rellenar(player)) { // SI NO RELLENÓ CAJITA, ENTONCES CAMBIAMOS DE JUGADOR
							juega = s2.str();
							player = 1;
						}
						agregarJugada(new jugada(c1, c2));
					}
					else {
						utiles::imprimir("\nCoordenadas incorrectas...");
						utiles::esperar(1500);
					}
				}
				if (player == 1) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Central->");
					e->registrarJugadasIlegales();
					e->registrarJugadasLegales();
					utiles::imprimir("\n\nPensando...");
					utiles::esperar(1000);
					if (e->haycajita())
						j = e->haycajita();
					else
						j = e->recuperarJugada();
					tablero->partida(j->obtenerEntrada(), j->obtenerSalida());
					if (!rellenar(player)) {
						juega = s1.str();
						player = 0;
					}
					agregarJugada(j);
				}
			}
			if (cambio == false) {
				utiles::limpiar();
				utiles::imprimir(toString());
				if (comprobarGanador() == "EMPATE")
					utiles::imprimir("\nEs un empate!");
				else {
					utiles::imprimir("\nEl ganador es: ");
					utiles::imprimir(comprobarGanador());
				}
				utiles::pausa();
				break;
			}
		}
		if (*e == "class estrategiaIslas") {
			string aux; stringstream s1, s2;
			player1 = jugador1(); player2 = jugador2();
			s1 << "\n\nJuega " << player1 << '\n';
			s2 << "\n\nJuega " << player2 << '\n';
			string juega = s1.str();
			coordenadas* c1 = NULL;
			coordenadas* c2 = NULL;
			jugada* j = NULL;
			jugada* jugadaMaquina = nullptr;
			bool player = 0;
			while (!tablero->lleno()) {
				if (player == 0) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					utiles::imprimir("\nEstrategia Islas->");
					utiles::imprimir("\nSi desea cambiar estrategia digite \"-1\" en todas las coordenadas...");
					utiles::imprimir("\n\nDigite la primera coordenada x (fila): ");
					int x1 = utiles::leerEntero();
					utiles::imprimir("Digite la primera coordenada y (columna): ");
					int y1 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada x (fila): ");
					int x2 = utiles::leerEntero();
					utiles::imprimir("Digite la segunda coordenada y (columna): ");
					int y2 = utiles::leerEntero();
					if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
						cambio = true;
						break;
					}
					c1 = new coordenadas(x1, y1);
					c2 = new coordenadas(x2, y2);
					if (tablero->partida(c1, c2)) {
						if (!rellenar(player)) { // SI NO RELLENÓ CAJITA, ENTONCES CAMBIAMOS DE JUGADOR
							juega = s2.str();
							player = 1;
						}
						agregarJugada(new jugada(c1, c2));
					}
					else {
						utiles::imprimir("\nCoordenadas incorrectas...");
						utiles::esperar(1500);
					}
				}
				if (player == 1) {
					utiles::limpiar();
					utiles::imprimir(toString());
					utiles::imprimir(juega);
					e->establecerJugadaMaquina(jugadaMaquina);
					e->registrarJugadasIlegales();
					e->registrarJugadasLegales();
					utiles::imprimir("\nEstrategia Islas->");
					utiles::imprimir("\n\nPensando...");
					utiles::esperar(1000);
					if (e->haycajita())
						j = e->haycajita();
					else
						j = e->recuperarJugada();
					tablero->partida(j->obtenerEntrada(), j->obtenerSalida());
					if (!rellenar(player)) {
						juega = s1.str();
						player = 0;
					}
					jugadaMaquina = j;
					agregarJugada(jugadaMaquina);
				}
			}
			if (cambio == false) {
				utiles::limpiar();
				utiles::imprimir(toString());
				if (comprobarGanador() == "EMPATE")
					utiles::imprimir("\nEs un empate!");
				else {
					utiles::imprimir("\nEl ganador es: ");
					utiles::imprimir(comprobarGanador());
				}
				utiles::pausa();
				break;
			}
		}
	}
}

estrategia* juego::cambiarEstrategia(){
	estrategia* e = NULL;
	int opcionEstrategia = 0;
	utiles::limpiar();
	utiles::imprimir(interfaz::estrategia());
	opcionEstrategia = utiles::leerSeleccion(1, 5);
	switch (opcionEstrategia) {
	case 1: e = new estrategiaAleatoria(getTablero(), getN(), getM()); break;
	case 2: e = new estrategiaCercana(getTablero(), getN(), getM()); break;
	case 3: e = new estrategiaPeriferica(getTablero(), getN(), getM()); break;
	case 4: e = new estrategiaCentral(getTablero(), getN(), getM()); break;
	case 5: e = new estrategiaIslas(getTablero(), getN(), getM()); break;
	}
	return e;
}

string juego::comprobarGanador() {
	int ganador = tablero->comprobarGanador();
	if (ganador == 1) return player1;
	else if (ganador == 2) return player2;
	else return "EMPATE";
}

string juego::toString() const {
	stringstream s;
	s << jugadores->VS();
	s << tablero->toString();
	return s.str();
}

void juego::partida(coordenadas* x1y1, coordenadas* x2y2) {
	tablero->partida(x1y1, x2y2);
}

void juego::draw(){
	tablero->draw();
}

bool juego::rellenar(bool x) {
	return tablero->rellenar(x);
}

void juego::reproducir() {
	draw();
	stringstream s1, s2;
	s1 << "\n\nJuega " << player1 << '\n';
	s2 << "\n\nJuega " << player2 << '\n';
	string juega = s1.str();
	bool player = 0;
	coordenadas* c1 = NULL;
	coordenadas* c2 = NULL;
	jugada* j = NULL;
	jugadas->inicializarActual();
	while (!tablero->lleno()) {
		utiles::limpiar();
		utiles::imprimir(toString());
		utiles::imprimir(juega);
		j = jugadas->recuperarJugada();
		c1 = j->obtenerEntrada();
		c2 = j->obtenerSalida();
		tablero->partida(c1, c2);
		if (!rellenar(player)) { // SI NO RELLENÓ CAJITA, ENTONCES CAMBIAMOS DE JUGADOR
			if (player == 0) {
				juega = s2.str();
				player = 1;
			}
			else {
				juega = s1.str();
				player = 0;
			}
		}
		utiles::pausa();
	}
	utiles::limpiar();
	utiles::imprimir(toString());
	if (comprobarGanador() == "EMPATE")
		utiles::imprimir("\nEs un empate!");
	else {
		utiles::imprimir("\nEl ganador es: ");
		utiles::imprimir(comprobarGanador());
	}
	utiles::pausa(); // SI LLEGA ACÁ ES QUE SE LLENÓ LA MATRIX
}

string juego::toStringJuego() {
	stringstream s;
	s << "Partida numero: " << numJuego << '\n';
	s << player1 << " VS " << player2 << '\n';
	return s.str();
}

string juego::archivos() {
	stringstream s;
	s << numJuego << ' ' << player1 << '\t' << player2 << '\t';
	s << tablero->getK() << '\t';
	s << tablero->archivos();
	s << jugadas->getN() << '\t';
	s << jugadas->archivos();
	return s.str();
}