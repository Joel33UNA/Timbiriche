/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "estrategiaPeriferica.h"
#include "coordenadas.h"
#include <time.h>

estrategiaPeriferica::estrategiaPeriferica(componente***c, int n, int m) : estrategia(c, n, m)
{}

estrategiaPeriferica::~estrategiaPeriferica()
{}

bool estrategiaPeriferica::operator==(string est2) {
	string clase = typeid(*this).name();
	return clase == est2;
}

jugada* estrategiaPeriferica::recuperarJugada() {
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

void estrategiaPeriferica::registrarJugadasLegales() {
	delete jugadasLegales;
	jugadasLegales = new listaJugadasMaquina();
	coordenadas* corin = NULL; coordenadas* corout = NULL;
	jugada* j = NULL;
	int contador = 0;


	static int auxi = 0, auxj = 0, auxn = n, auxm = m;

	for (int i = auxi; i < auxn; i++) {
		for (int j = auxj; j < auxm; j++) {
			if (tablero[i][j] != nullptr) {
				if (i == auxi) {
					if (*tablero[i][j] == "class espacio2" && *tablero[i][j - 1] == "class punto" && *tablero[i][j + 1] == "class punto") {
						corin = new coordenadas(i / 2, (j - 1) / 2);
						corout = new coordenadas(i / 2, (j + 1) / 2);
						if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
							jugada* jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
							contador++;
						}
					}
				}
				if (i == auxn - 1) {
					if (*tablero[i][j] == "class espacio2" && *tablero[i][j - 1] == "class punto" && *tablero[i][j + 1] == "class punto") {
						corin = new coordenadas(i / 2, (j - 1) / 2);
						corout = new coordenadas(i / 2, (j + 1) / 2);
						if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
							jugada* jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
							contador++;
						}
					}
				}
				if (j == auxj) {
					if (*tablero[i][j] == "class espacio1" && *tablero[i - 1][j] == "class punto" && *tablero[i + 1][j] == "class punto") {
						corin = new coordenadas((i - 1) / 2, j / 2);
						corout = new coordenadas((i + 1) / 2, j / 2);
						if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
							jugada* jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
							contador++;
						}
					}
				}
				if (j == auxm - 1) {
					if (*tablero[i][j] == "class espacio1" && *tablero[i - 1][j] == "class punto" && *tablero[i + 1][j] == "class punto") {
						corin = new coordenadas((i - 1) / 2, j / 2);
						corout = new coordenadas((i + 1) / 2, j / 2);
						if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
							jugada* jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
							contador++;
						}
					}
				}
				if (i <= n - 4) {
					if (*tablero[i][j] == "class espacio2" &&  tablero[i + 1][j] == nullptr) {
						corin = new coordenadas(i / 2, (j - 1) / 2);
						corout = new coordenadas(i / 2, (j + 1) / 2);
						if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
							jugada* jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
							contador++;
						}
					}
				}
				if (j > 1 && j < m) {
					if (*tablero[i][j] == "class espacio1" && tablero[i][j - 1] == nullptr) {
						corin = new coordenadas((i + 1) / 2, j / 2);
						corout = new coordenadas((i - 1) / 2, j / 2);
						if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
							jugada* jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
							contador++;
						}
					}
					if (*tablero[i][j] == "class espacio1" && tablero[i][j + 1] == nullptr) {
						corin = new coordenadas((i + 1) / 2, j / 2);
						corout = new coordenadas((i - 1) / 2, j / 2);
						if (jugadasIlegales->compararCoordenadas(corin, corout) == false) {
							jugada* jug = new jugada(corin, corout);
							jugadasLegales->agregar(jug);
							contador++;
						}
					}
				}
			}
		}
	} // VERIFICAR JUGADAS LEGALES...

	if (contador == 0) {
		auxi++; auxj++; auxn--; auxm--;
	}
}
