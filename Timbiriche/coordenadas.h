/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include <string>
using std::string;
class coordenadas {
private:
	int x;
	int y;
public:
	coordenadas(int, int);
	virtual ~coordenadas();
	bool operator == (coordenadas&); // Método para comparar coordenadas ajenas con estas
	int getX();
	int getY();
	string archivos();
};

