/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "estrategia.h"

estrategia::estrategia(componente*** t, int N, int M) 
	: tablero(t), n(N), m(M), jugadasLegales(new listaJugadasMaquina()), jugadasIlegales(new listaJugadasMaquina())
{}

estrategia::~estrategia() { delete jugadasLegales; }

void estrategia::registrarJugadasIlegales() {
	delete jugadasIlegales;
	jugadasIlegales = new listaJugadasMaquina();

	int contador = 0;
	string clase;
	coordenadas* corin = NULL; coordenadas* corout = NULL;
	jugada* jug = NULL;

	for (int i = 1; i < n - 1; i = i + 2)
		for (int j = 1; j < m - 1; j = j + 2) {
			contador = 0;
			if (tablero[i][j]) {
				clase = typeid(*(tablero[i][j])).name();
				if (clase == "class espacio2") {
					if (*tablero[i][j - 1] == "class lineaVertical") // Izquierda
						contador++;
					if (*tablero[i][j + 1] == "class lineaVertical") // Derecha
						contador++;
					if (*tablero[i - 1][j] == "class lineaHorizontal") // Arriba
						contador++;
					if (*tablero[i + 1][j] == "class lineaHorizontal") // Abajo
						contador++;
					if (contador == 2) {
						if (*tablero[i - 1][j] == "class espacio2") {
							corin = new coordenadas((i - 1) / 2, (j - 1) / 2);
							corout = new coordenadas((i - 1) / 2, (j + 1) / 2);
							jug = new jugada(corin, corout);
							jugadasIlegales->agregar(jug);
						}
						if (*tablero[i + 1][j] == "class espacio2") {
							corin = new coordenadas((i + 1) / 2, (j - 1) / 2);
							corout = new coordenadas((i + 1) / 2, (j + 1) / 2);
							jug = new jugada(corin, corout);
							jugadasIlegales->agregar(jug);
						}
						if (*tablero[i][j - 1] == "class espacio1") {
							corin = new coordenadas((i - 1) / 2, (j - 1) / 2);
							corout = new coordenadas((i + 1) / 2, (j - 1) / 2);
							jug = new jugada(corin, corout);
							jugadasIlegales->agregar(jug);
						}
						if (*tablero[i][j + 1] == "class espacio1") {
							corin = new coordenadas((i - 1) / 2, (j + 1) / 2);
							corout = new coordenadas((i + 1) / 2, (j + 1) / 2);
							jug = new jugada(corin, corout);
							jugadasIlegales->agregar(jug);
						}
					}
				}
			}
		}
}

jugada* estrategia::haycajita() {
	coordenadas* corin = NULL; coordenadas* corout = NULL; jugada* jug = NULL;
	string clase;
	int contador = 0;
	for (int i = 1; i < n - 1; i+=2)
		for (int j = 1; j < m - 1; j+=2) {
			contador = 0;
			if (tablero[i][j] != nullptr) {
				clase = typeid(*(tablero[i][j])).name();
				if (clase == "class espacio2") {
					if (*tablero[i - 1][j] == "class lineaHorizontal")
						contador++;
					if (*tablero[i + 1][j] == "class lineaHorizontal")
						contador++;
					if (*tablero[i][j - 1] == "class lineaVertical")
						contador++;
					if (*tablero[i][j + 1] == "class lineaVertical")
						contador++;
					if (contador == 3) {
						if (*tablero[i - 1][j] == "class espacio2") {
							corin = new coordenadas((i - 1) / 2, (j - 1) / 2);
							corout = new coordenadas((i - 1) / 2, (j + 1) / 2);
							jug = new jugada(corin, corout);
							return jug;
						}
						if (*tablero[i + 1][j] == "class espacio2") {
							corin = new coordenadas((i + 1) / 2, (j - 1) / 2);
							corout = new coordenadas((i + 1) / 2, (j + 1) / 2);
							jug = new jugada(corin, corout);
							return jug;
						}
						if (*tablero[i][j - 1] == "class espacio1") {
							corin = new coordenadas((i - 1) / 2, (j - 1) / 2);
							corout = new coordenadas((i + 1) / 2, (j - 1) / 2);
							jug = new jugada(corin, corout);
							return jug;
						}
						if (*tablero[i][j + 1] == "class espacio1") {
							corin = new coordenadas((i - 1) / 2, (j + 1) / 2);
							corout = new coordenadas((i + 1) / 2, (j + 1) / 2);
							jug = new jugada(corin, corout);
							return jug;
						}
					}
				}
			}
		}
	return nullptr; //PROBAR MÉTODO DE HAY CAJITA?
}
