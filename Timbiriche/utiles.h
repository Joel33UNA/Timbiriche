/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

class utiles { //<Static Class>
public:
	static void imprimir(string);
	static void limpiar();
	static void esperar(int);
	static void pausa();
	static void imprimirCaracter(char);
	static string leerString();
	static int leerEntero();
	static int leerSeleccion(int, int);
	static void salir();
};

