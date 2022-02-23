/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include "interfaz.h"
#include "empresaDots.h"
#include "utiles.h"
#include "seisPuntos.h"
#include "nuevePuntos.h"
#include "quincePuntos.h"
#include "archivo.h"
#include "estrategia.h"
#include "estrategiaAleatoria.h"
#include "estrategiaCercana.h"
#include "estrategiaPeriferica.h"
#include "estrategiaCentral.h"
#include "estrategiaIslas.h"

class control {
private:
	empresaDots* dots;
public:
	control();
	virtual ~control();
	void cargar();
	void controlIniciar();
	void controlMenu();
	void controlLeer();
	void controlDatos();
	void controlModalidad();
	void controlVSHumano();
	void controlVSMaquina();
	void controlCambio();
	void controlVisualizar();
	void controlCerrar();
};

