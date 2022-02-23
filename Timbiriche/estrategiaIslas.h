/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
*/

#pragma once
#include "estrategia.h"
class estrategiaIslas :
	public estrategia
{
private:
	jugada* jugadaMaquina;
public:
	estrategiaIslas(componente***, int, int);
	virtual ~estrategiaIslas();
	bool operator == (string);
	void establecerJugadaMaquina(jugada*);
	void registrarJugadasLegales();
	jugada* recuperarJugada();
	////////////////////////////////
	virtual void establecerJugadaRival(jugada*) { throw; }
};

