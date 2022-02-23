/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "componente.h"
#include "punto.h"
#include "espacio1.h"
#include "espacio2.h"
#include "lineaHorizontal.h"
#include "lineaVertical.h"
#pragma once
#include <ostream>
using std::ostream;
class campoComposite : public componente {
protected:
	componente*** tablero;
	int n;
	int m;
public:
	campoComposite(int, int);
	virtual ~campoComposite();
	virtual bool lleno();
	virtual int getN();
	virtual int getM();
	virtual int getT();
	virtual void setN(int);
	virtual void setM(int);
	virtual void draw() = 0;
	virtual string toString() const;
	virtual componente*** getTablero();
	virtual void setTablero(componente***);
	virtual bool operator==(int) { throw; } //
	virtual bool operator == (string) = 0;
};