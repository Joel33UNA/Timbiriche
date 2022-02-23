/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#pragma once
#include <string>
using std::string;

class interfaz {
public:
	static string iniciar();
	static string menu();
	static string modalidad();
	static string estrategia();
	static string combinaciones();
	static string tipoTablero(int);
	static string solicitarIdentificacion();
	static string solicitarIdentificacion1();
	static string solicitarIdentificacion2();
	static string minimo();
	static string mismoJugador();
	static string entradaErronea();
	static string solicitarNombre();
	static string usuarioExistente();
	static string correcto();
	static string listaLlena();
	static string listaVacia();
	static string cerrar();
};

