/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "estrategiaCentral.h"
#include <time.h>

estrategiaCentral::estrategiaCentral(componente*** c, int n, int m) : estrategia(c, n, m)
{}

estrategiaCentral::~estrategiaCentral()
{}

bool estrategiaCentral::operator==(string est2) {
	string clase = typeid(*this).name();
	return clase == est2;
}

jugada* estrategiaCentral::recuperarJugada() {
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

void estrategiaCentral::registrarJugadasLegales() {
	delete jugadasLegales;
	jugadasLegales = new listaJugadasMaquina();
	coordenadas* corin = NULL; coordenadas* corout = NULL;
	jugada* jug = NULL;
	int contador = 0;
	bool jerarquiaPrincipal = false; // Este booleano es el que indica si hay jugadas más centrales posibles

	static int auxi = 2, auxj = 2, auxn = n - 2, auxm = m - 2;


	if (n == 5 && m == 3) {   // Caso específico de que sea solo una matriz 3 x 2
		if (*tablero[2][1] == "class espacio2") {
			corin = new coordenadas(1, 0);
			corout = new coordenadas(1, 1);
			if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
				jug = new jugada(corin, corout);
				jugadasLegales->agregar(jug);
			}
		}
		else {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (tablero[i][j] != nullptr) {
						if (*tablero[i][j] == "class espacio2") {
							if (*tablero[i][j - 1] == "class punto" && *tablero[i][j + 1] == "class punto") {
								corin = new coordenadas(i / 2, (j - 1) / 2);
								corout = new coordenadas(i / 2, (j + 1) / 2);
								jug = new jugada(corin, corout);
								jugadasLegales->agregar(jug);
							}
						}
						if (*tablero[i][j] == "class espacio1") {
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
	else {
		for (int i = auxi; i < auxn; i++) {     // Casos generales
			for (int j = auxj; j < auxm; j++) {
				if (tablero[i][j] != nullptr) {
					if (i >= 2 && i <= n - 2 && j >= 2 && j <= m - 2) {
						if (*tablero[i][j] == "class espacio2") {
							if (tablero[i + 1][j]) {
								if (*tablero[i][j - 1] == "class punto" && *tablero[i][j + 1] == "class punto") {
									corin = new coordenadas(i / 2, (j - 1) / 2);
									corout = new coordenadas(i / 2, (j + 1) / 2);
									if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
										jug = new jugada(corin, corout);
										jugadasLegales->agregar(jug);
										contador++;
										jerarquiaPrincipal = true;
									}
								}
							}
						}
						if (tablero[i][j - 1] && tablero[i][j + 1]) {
							if (*tablero[i][j] == "class espacio1") {
								if (*tablero[i - 1][j] == "class punto" && *tablero[i + 1][j] == "class punto") {
									corin = new coordenadas((i - 1) / 2, j / 2);
									corout = new coordenadas((i + 1) / 2, j / 2);
									if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
										jug = new jugada(corin, corout);
										jugadasLegales->agregar(jug);
										contador++;
										jerarquiaPrincipal = true;
									}
								}
							}
						}
					}
				}
			}
		}
		if (jerarquiaPrincipal == false) {
			for (int i = auxi; i < auxn; i++) {
				for (int j = auxj; j < auxm; j++) {
					if (tablero[i][j]) {
						if (i >= 2 && i <= n - 2 && j >= 2 && j <= m - 2) {
							if (*tablero[i][j] == "class punto" && i != 0 && j != 0 && i != n - 1 && j != m - 1) {
								if (tablero[i - 1][j] && *tablero[i - 1][j] == "class espacio1") {
									corin = new coordenadas((i - 2) / 2, j / 2);
									corout = new coordenadas(i / 2, j / 2);
									if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
										jug = new jugada(corin, corout);
										jugadasLegales->agregar(jug);
										contador++;
									}
								}
								if (tablero[i + 1][j] && *tablero[i + 1][j] == "class espacio1") {
									if (tablero[i + 1][j - 1] && tablero[i + 1][j + 1]) {
										corin = new coordenadas((i + 2) / 2, j / 2);
										corout = new coordenadas(i / 2, j / 2);
										if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
											jug = new jugada(corin, corout);
											jugadasLegales->agregar(jug);
											contador++;
										}
									}
								}
								if (tablero[i][j - 1] && *tablero[i][j - 1] == "class espacio2") {
									if (tablero[i + 1][j - 1]) {
										corin = new coordenadas(i / 2, (j - 2) / 2);
										corout = new coordenadas(i / 2, j / 2);
										if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
											jug = new jugada(corin, corout);
											jugadasLegales->agregar(jug);
											contador++;
										}
									}
								}
								if (tablero[i][j + 1] && *tablero[i][j + 1] == "class espacio2") {
									if (tablero[i + 1][j + 1]) {
										corin = new coordenadas(i / 2, (j + 2) / 2);
										corout = new coordenadas(i / 2, j / 2);
										if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
											jug = new jugada(corin, corout);
											jugadasLegales->agregar(jug);
											contador++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (contador == 0) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (tablero[i][j] != nullptr) {
					if (*tablero[i][j] == "class espacio2") {
						if (*tablero[i][j - 1] == "class punto" && *tablero[i][j + 1] == "class punto") {
							corin = new coordenadas(i / 2, (j - 1) / 2);
							corout = new coordenadas(i / 2, (j + 1) / 2);
							jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
						}
					}
					if (*tablero[i][j] == "class espacio1") {
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