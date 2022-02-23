/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "campoJuego.h"
#include <sstream>
#include <typeinfo>
using std::stringstream;

campoJuego::campoJuego() : campoComposite(0, 0), tableros(new campoComposite* [3]), k(0) {
	for (int i = 0; i < 3; i++)
		tableros[i] = NULL;
}

campoJuego::~campoJuego() {
	for (int i = 0; i < k; i++) delete tableros[i];
}

int campoJuego::calculaMayorFilas()
{
	int mayor = 0;
	if (k == 0) {
		return mayor;
	}
	for (int i = 0; i < k; i++) {
		if (tableros[i]->getN() > mayor) {
			mayor = tableros[i]->getN();
		}
	}
	return mayor;
}

ostream& operator<<(ostream& out, componente& c) {
	out << c.toString();
	return out;
}

int campoJuego::getK() {
	return k;
}

bool campoJuego::lleno() {
	return campoComposite::lleno();
}

int campoJuego::comprobarGanador() {
	int contador1 = 0, contador2 = 0;
	string clase;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (tablero[i][j]) {
				clase = typeid(*(tablero[i][j])).name();
				if (clase == "class numero") {
					if (*tablero[i][j] == 1) contador1++;
					if (*tablero[i][j] == 2) contador2++;
				}
			}
		}
	if (contador1 > contador2) return 1;
	else if (contador1 < contador2) return 2;
	else return 0;
}

void campoJuego::agregarAlContenedor(campoComposite* c) {
	if (k < 3) tableros[k++] = c; 
}

void campoJuego::draw() {
	delete tablero;

	setN(this->calculaMayorFilas());
	tablero = new componente * *[n];

	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += tableros[i]->getM();
	}

	setM(sum + (k - 1));

	for (int i = 0; i < n; i++) {
		tablero[i] = new componente * [m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tablero[i][j] = nullptr;
		}
	}

	int q = 0, limite = 0;

	for (int r = 0; r < k; r++) {

		limite += tableros[r]->getM();
		if (r > 0) {
			limite++;
		}

		for (q; q < limite; q += 2) {
			for (int w = 0; w < tableros[r]->getN(); w += 2) {
				delete tablero[w][q];
				tablero[w][q] = new punto();
			}
		}
		q = limite + 1;
	}

	for (int h = 0; h < m; h += 2) {
		for (int l = 1; l < n - 1; l += 2) {
			if (tablero[l - 1][h] != nullptr && tablero[l + 1][h] != nullptr) {
				tablero[l][h] = new espacio1();
			}
		}
	}

	for (int p = 1; p < m - 1; p += 2) {
		for (int t = 0; t < n; t++) {
			if (tablero[t][p - 1] != nullptr && tablero[t][p + 1] != nullptr) {
				tablero[t][p] = new espacio2();
			}
		}
	}
}

bool campoJuego::rellenar(bool x) {
	int contador = 0;
	string espacio, vertical1, horizontal1, vertical2, horizontal2;
	for (int i = 1; i < n - 1; i = i + 2)
		for (int j = 1; j < m - 1; j = j + 2) {
			if (tablero[i][j]) {
				espacio = typeid(*(tablero[i][j])).name();
				if (i % 2 == 1 && j % 2 == 1 && espacio == "class espacio2") {
					horizontal1 = typeid(*(tablero[i - 1][j])).name();
					horizontal2 = typeid(*(tablero[i + 1][j])).name();
					vertical1 = typeid(*(tablero[i][j - 1])).name();
					vertical2 = typeid(*(tablero[i][j + 1])).name();
					if (horizontal1 == "class lineaHorizontal" && horizontal2 == "class lineaHorizontal" && vertical1 == "class lineaVertical" && vertical2 == "class lineaVertical") {
						delete tablero[i][j];
						tablero[i][j] = new numero((int)x + 1);
						contador++;
					}
				}
			}
		}
	if (contador == 0) return false;
	else return true;
}

bool campoJuego::partida(coordenadas* x1y1, coordenadas* x2y2) {
	int x1 = x1y1->getX() * 2;
	int y1 = x1y1->getY() * 2;
	int x2 = x2y2->getX() * 2;
	int y2 = x2y2->getY() * 2;
	if (0 <= x1 && x1 < n && 0 <= x2 && x2 < n) {
		if (0 <= y1 && y1 < m && 0 <= y2 && y2 < m) {
			if (tablero[x1][y1] && tablero[x2][y2]) {
				if (x1 == x2) {
					if (y1 == y2 + 2) {
						string clase1 = typeid(*(tablero[x1][y1])).name();
						string clase2 = typeid(*(tablero[x2][y2])).name();
						if (clase1 == "class punto" && clase2 == "class punto") {
							// Se ha comprobado la coordenada insertada sea class punto
							string claseLinea = typeid(*(tablero[x1][y2 + 1])).name();
							if (claseLinea != "class lineaHorizontal") { //Comprobando que no exista linea
								delete tablero[x1][y2 + 1];
								tablero[x1][y2 + 1] = new lineaHorizontal();
								return true;
							}
							else return false;
						}
						else return false;
					}
					if (y1 == y2 - 2) {
						string clase1 = typeid(*(tablero[x1][y1])).name();
						string clase2 = typeid(*(tablero[x2][y2])).name();
						if (clase1 == "class punto" && clase2 == "class punto") {
							string claseLinea = typeid(*(tablero[x1][y1 + 1])).name();
							if (claseLinea != "class lineaHorizontal") { //Comprobando que no exista linea
								delete tablero[x1][y1 + 1];
								tablero[x1][y1 + 1] = new lineaHorizontal();
								return true;
							}
							else return false;
						}
						else return false;
					}
					else return false;
				}
				if (y1 == y2) {
					if (x1 == x2 + 2) {
						string clase1 = typeid(*(tablero[x1][y1])).name();
						string clase2 = typeid(*(tablero[x2][y2])).name();
						if (clase1 == "class punto" && clase2 == "class punto") {
							string claseLinea = typeid(*(tablero[x2 + 1][y1])).name();
							if (claseLinea != "class lineaVertical") { //Comprobando que no exista linea
								delete tablero[x2 + 1][y1];
								tablero[x2 + 1][y1] = new lineaVertical();
								return true;
							}
							else return false;
						}
						else return false;
					}
					if (x1 == x2 - 2) {
						string clase1 = typeid(*(tablero[x1][y1])).name();
						string clase2 = typeid(*(tablero[x2][y2])).name();
						if (clase1 == "class punto" && clase2 == "class punto") {
							string claseLinea = typeid(*(tablero[x1 + 1][y1])).name();
							if (claseLinea != "class lineaVertical") { //Comprobando que no exista linea
								delete tablero[x1 + 1][y1];
								tablero[x1 + 1][y1] = new lineaVertical();
								return true;
							}
							else return false;
						}
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

int campoJuego::getN() { return campoComposite::getN(); }

int campoJuego::getM() { return campoComposite::getM(); }

void campoJuego::setN(int n) { campoComposite::setN(n); }

void campoJuego::setM(int m) { campoComposite::setM(m); }

componente*** campoJuego::getTablero() {
	return campoComposite::getTablero();
}

void campoJuego::setTablero(componente*** c) {
	campoComposite::setTablero(c);
}

string campoJuego::toString() const {
	return campoComposite::toString();
}

string campoJuego::archivos(){
	stringstream s;
	for (int i = 0; i < k - 1; i++){
		if (*tableros[i] == "class seisPuntos") s << "6 ";
		if (*tableros[i] == "class nuevePuntos") s << "9 ";
		if (*tableros[i] == "class quincePuntos") s << "15 ";
	}
	if (*tableros[k - 1] == "class seisPuntos") s << "6\t";
	if (*tableros[k - 1] == "class nuevePuntos") s << "9\t";
	if (*tableros[k - 1] == "class quincePuntos") s << "15\t";
	return s.str();
}
