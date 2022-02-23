/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "utiles.h"

void utiles::imprimir(string s) { cout << s << endl; }

void utiles::limpiar() { system("cls"); }

void utiles::esperar(int x) { Sleep(x); }

void utiles::pausa() { system("pause"); }

void utiles::imprimirCaracter(char s) { cout<< " " << s; }

string utiles::leerString() {
	string s;
	getline(cin, s);
	return s;
}

int utiles::leerEntero() {
	int n;
	while (true) {
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cout << "Valor incorrecto... " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

int utiles::leerSeleccion(int minimo, int maximo) {
	int entrada = 0;
	while (true) {
		if (cin >> entrada) {
			if (entrada <= maximo && entrada >= minimo) {
				cin.clear();
				cin.ignore(1024, '\n');
				return entrada;
			}
			else {
				cout << "\t\t    Valor incorrecto..." << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		else {
			cout << "\t\t    Valor incorrecto..." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

void utiles::salir() {
	exit(0);
}