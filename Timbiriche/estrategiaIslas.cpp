/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "estrategiaIslas.h"
#include <time.h>

estrategiaIslas::estrategiaIslas(componente*** c, int n, int m)
	: estrategia(c, n, m), jugadaMaquina(nullptr)
{}

estrategiaIslas::~estrategiaIslas()
{}

bool estrategiaIslas::operator==(string es2) {
	string es = typeid(*this).name();
	return es == es2;
}

void estrategiaIslas::establecerJugadaMaquina(jugada* j){
	jugadaMaquina = j;
}

void estrategiaIslas::registrarJugadasLegales() {
	delete jugadasLegales;
	jugadasLegales = new listaJugadasMaquina();

	string clase;
	coordenadas* corin = NULL; coordenadas* corout = NULL;
	coordenadas* corin2 = NULL; coordenadas* corout2 = NULL;
	bool existeIsla = false;
	if (jugadaMaquina) {
		corin2 = jugadaMaquina->obtenerEntrada();
		corout2 = jugadaMaquina->obtenerSalida();
		if (corin2->getX() != 0 && corout2->getX() != 0) {
			if (tablero[corin2->getX() * 2 - 1][corin2->getY() * 2]) {
				if (*tablero[corin2->getX() * 2 - 1][corin2->getY() * 2] == "class espacio1") {
					corin = new coordenadas(corin2->getX(), corin2->getY());
					corout = new coordenadas(corin2->getX() - 1, corin2->getY());
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
			if (tablero[corout2->getX() * 2 - 1][corout2->getY() * 2]) {
				if (*tablero[corout2->getX() * 2 - 1][corout2->getY() * 2] == "class espacio1") {
					corin = new coordenadas(corout2->getX(), corout2->getY());
					corout = new coordenadas(corout2->getX() - 1, corout2->getY());
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
		}
		if (corin2->getY() != 0 && corout2->getY() != 0) {
			if (tablero[corin2->getX() * 2][corin2->getY() * 2 - 1]) {
				if (*tablero[corin2->getX() * 2][corin2->getY() * 2 - 1] == "class espacio2") {
					corin = new coordenadas(corin2->getX(), corin2->getY());
					corout = new coordenadas(corin2->getX(), corin2->getY() - 1);
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
			if (tablero[corout2->getX() * 2][corout2->getY() * 2 - 1]) {
				if (*tablero[corout2->getX()][corout2->getY() - 1] == "class espacio2") {
					corin = new coordenadas(corout2->getX(), corout2->getY());
					corout = new coordenadas(corout2->getX(), (corout2->getY() - 1));
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
		}
		if (corin2->getX() * 2 != n - 1 && corout2->getX() * 2 != n - 1) {
			if (tablero[corin2->getX() * 2 + 1][corin2->getY() * 2]) {
				if (*tablero[corin2->getX() * 2 + 1][corin2->getY() * 2] == "class espacio1") {
					corin = new coordenadas(corin2->getX(), corin2->getY());
					corout = new coordenadas((corin2->getX() + 1), corin2->getY());
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
			if (tablero[corout2->getX() * 2 + 1][corout2->getY() * 2]) {
				if (*tablero[corout2->getX() * 2 + 1][corout2->getY() * 2] == "class espacio1") {
					corin = new coordenadas(corout2->getX(), corout2->getY());
					corout = new coordenadas(corout2->getX() + 1, corout2->getY());
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
		}
		if (corin2->getY() * 2 != m - 1 && corout2->getY() * 2 != m - 1) {
			if (tablero[corin2->getX() * 2][corin2->getY() * 2 + 1]) {
				if (*tablero[corin2->getX() * 2][corin2->getY() * 2 + 1] == "class espacio2") {
					corin = new coordenadas(corin2->getX(), corin2->getY());
					corout = new coordenadas(corin2->getX(), corin2->getY() + 1);
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
			if (tablero[corout2->getX() * 2][corout2->getY() * 2 + 1]) {
				if (*tablero[corout2->getX() * 2][corout2->getY() * 2 + 1] == "class espacio2") {
					corin = new coordenadas(corout2->getX(), corout2->getY());
					corout = new coordenadas(corout2->getX(), corout2->getY() + 1);
					if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
						jugada* jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
						existeIsla = true;
					}
				}
			}
		}
	}
	if (existeIsla == false) {
		string clase; jugada* jug;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tablero[i][j] != nullptr) {
					clase = typeid(*(tablero[i][j])).name();
					if (clase == "class espacio2") {
						if (*tablero[i][j - 1] == "class punto" && *tablero[i][j + 1] == "class punto") {
							corin = new coordenadas(i / 2, (j - 1) / 2);
							corout = new coordenadas(i / 2, (j + 1) / 2);
							if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
								jug = new jugada(corin, corout);
								jugadasLegales->agregar(jug);
							}
						}
					}
					if (clase == "class espacio1") {
						if (*tablero[i - 1][j] == "class punto" && *tablero[i + 1][j] == "class punto") {
							corin = new coordenadas((i - 1) / 2, j / 2);
							corout = new coordenadas((i + 1) / 2, j / 2);
							if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
								jug = new jugada(corin, corout);
								jugadasLegales->agregar(jug);
							}
						}
					}
				}
			}
		}
	}
}

jugada* estrategiaIslas::recuperarJugada() {
	jugada* jug = NULL;
	int aleatoria = 0;
	srand((unsigned int)time(0));
	if (jugadasLegales->getN() == 0 && jugadasIlegales->getN() != 1) {
		aleatoria = 1 + rand() % (jugadasIlegales->getN() - 1);
		jug = jugadasIlegales->obtenerJugadaPos(aleatoria);
	}
	else if (jugadasLegales->getN() == 0 && jugadasIlegales->getN() == 1) {
		aleatoria = 1 + rand() % (jugadasIlegales->getN() + 1 - 1);
		jug = jugadasIlegales->obtenerJugadaPos(aleatoria);
	}
	else if (jugadasLegales->getN() == 1) {
		aleatoria = 1 + rand() % (jugadasLegales->getN() + 1 - 1);
		jug = jugadasLegales->obtenerJugadaPos(aleatoria);
	}
	else {
		aleatoria = 1 + rand() % (jugadasLegales->getN() - 1);
		jug = jugadasLegales->obtenerJugadaPos(aleatoria);
	}
	return jug;
}