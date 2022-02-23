/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "campoComposite.h"
#include "coordenadas.h"
#include "lineaVertical.h"
#include "lineaHorizontal.h"
#include "numero.h"
#pragma once
class campoJuego : public campoComposite {
private:
	campoComposite** tableros;
	int k;
public:
	campoJuego();
	virtual ~campoJuego();
	int calculaMayorFilas();
	friend ostream& operator << (ostream&, componente&);
	int getK();
	bool lleno();
	int comprobarGanador();
	void agregarAlContenedor(campoComposite*);
	void draw();
	bool rellenar(bool);
	bool partida(coordenadas*, coordenadas*);
	int getN();
	int getM();
	void setN(int);
	void setM(int);
	componente*** getTablero();
	void setTablero(componente***);
	string toString() const;
	string archivos();
	virtual bool operator == (string) { throw; }
};

