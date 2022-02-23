/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "estrategia.h"
class estrategiaCercana :
	public estrategia
{
private:
	jugada* jugadaRival;
public:
	estrategiaCercana(componente***, int, int);
	virtual ~estrategiaCercana();
	bool operator == (string);
	void establecerJugadaRival(jugada*);
	jugada* recuperarJugada();
	void registrarJugadasLegales();
	///////////////////////////////////////////////////////
	virtual void establecerJugadaMaquina(jugada*) { throw; }
};

