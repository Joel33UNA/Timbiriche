/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACI�N II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIM�NEZ
PROFESOR: SANTIAGO CAAMA�O POLINI
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
	bool operator == (coordenadas&); // M�todo para comparar coordenadas ajenas con estas
	int getX();
	int getY();
	string archivos();
};

