/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "componente.h"
#include "coordenadas.h"
#include "jugada.h"
#include "listaJugadasMaquina.h"
#include "lineaHorizontal.h"
#include "lineaVertical.h"
#include "coordenadas.h"

class estrategia {
protected:
	componente*** tablero;
	int n;
	int m;
	listaJugadasMaquina* jugadasLegales;
	listaJugadasMaquina* jugadasIlegales;
public:
	estrategia(componente***, int, int);
	virtual ~estrategia();
	virtual bool operator == (string) = 0;
	virtual jugada* recuperarJugada() = 0;
	virtual void establecerJugadaRival(jugada*) = 0;
	virtual void establecerJugadaMaquina(jugada*) = 0;
	virtual void registrarJugadasLegales() = 0;
	virtual void registrarJugadasIlegales();
	virtual jugada* haycajita();
};

