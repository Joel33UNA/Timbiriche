/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#pragma once
#include "estrategia.h"
class estrategiaAleatoria :
	public estrategia 
{
public:
	estrategiaAleatoria(componente***, int, int);
	virtual ~estrategiaAleatoria();
	bool operator == (string);
	jugada* recuperarJugada();
	void registrarJugadasLegales();
	//////////////////////////////////////////////////////////////////////
	virtual void establecerJugadaRival(jugada*) { throw; }
	virtual void establecerJugadaMaquina(jugada*) { throw; }
};

