/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#pragma once
#include <ostream>
#include <string>
using std::string;
using std::ostream;
class componente { // <Abstract Class>
public:
	componente() {}
	virtual ~componente() {}
	virtual bool operator == (int) = 0;
	virtual bool operator == (string) = 0;
	virtual string toString() const = 0;
	virtual int getN() = 0;
	virtual int getM() = 0;
};
