/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
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

