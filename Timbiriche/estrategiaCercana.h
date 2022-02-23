/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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

