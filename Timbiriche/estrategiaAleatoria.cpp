/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "estrategiaAleatoria.h"
#include <time.h>

estrategiaAleatoria::estrategiaAleatoria(componente*** c, int n, int m) : estrategia(c, n, m)
{}

estrategiaAleatoria::~estrategiaAleatoria() {}

bool estrategiaAleatoria::operator==(string est2) {
	string clase = typeid(*this).name();
	return clase == est2;
}

jugada* estrategiaAleatoria::recuperarJugada() {
	jugada* jug = NULL;
	int aleatoria = 0;
	srand((unsigned int)time(0));
	if (jugadasLegales->getN() == 1) {
		aleatoria = 1 + rand() % (jugadasLegales->getN() + 1 - 1);
		jug = jugadasLegales->obtenerJugadaPos(aleatoria);
	}
	else {
		aleatoria = 1 + rand() % (jugadasLegales->getN() - 1);
		jug = jugadasLegales->obtenerJugadaPos(aleatoria);	
	}
	return jug;
}

void estrategiaAleatoria::registrarJugadasLegales() {
	delete jugadasLegales;
	jugadasLegales = new listaJugadasMaquina();

	string clase;
	coordenadas* corin = NULL; coordenadas* corout = NULL;
	jugada* jug = NULL;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (tablero[i][j] != nullptr) {
				clase = typeid(*(tablero[i][j])).name();
				if (clase == "class espacio2") {
					if (*tablero[i][j - 1] == "class punto" && *tablero[i][j + 1] == "class punto") {
						corin = new coordenadas(i / 2, (j - 1) / 2);
						corout = new coordenadas(i / 2, (j + 1) / 2);
						jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
					}
				}
				if (clase == "class espacio1") {
					if (*tablero[i - 1][j] == "class punto" && *tablero[i + 1][j] == "class punto") {
						corin = new coordenadas((i - 1) / 2, j / 2);
						corout = new coordenadas((i + 1) / 2, j / 2);
						jug = new jugada(corin, corout);
						jugadasLegales->agregar(jug);
					}
				}
			}
		}
	// TOCA COMPROBAR CAJITAS PARA RELLENAR
}
