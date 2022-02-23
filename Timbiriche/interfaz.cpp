/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "interfaz.h"
#include <sstream>
using std::stringstream;

string interfaz::iniciar() {
	stringstream s;
	s << "\t\t__________ TIMBIRICHE _________________________________________\n";
	s << "\t\t__________BIENVENIDO(A)________________________________________\n";
	s << "\t\t_______________________________________________________________\n\n";
	s << "\t\t           1) Men\243 de Empresa Dots.                            \n";
	s << "\t\t           2) Cargar una partida.                              \n";
	s << "\t\t           0) Salir.                                           \n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::menu() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n\n";
	s << "\t\t           1) Suscribirse.                                      \n";
	s << "\t\t           2) Jugar.                                            \n";
	s << "\t\t           3) Cambio de d\241a.                                    \n";
	s << "\t\t           4) Visualizar suscriptores activos                  \n";
	s << "\t\t           0) Retroceder.                                      \n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::modalidad() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t___________MODALIDAD DE JUEGO__________________________________\n";
	s << "\t\t_______________________________________________________________\n\n";
	s << "\t\t           1) Humano contra humano.                               \n";
	s << "\t\t           2) Humano contra m\240quina.                           \n";
	s << "\t\t           0) Retroceder.                                      \n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::estrategia() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t___________ESTRATEGIA DE IA____________________________________\n";
	s << "\t\t_______________________________________________________________\n\n";
	s << "\t\t           1) Juego aleatorio.                                 \n";
	s << "\t\t           2) Juego cercano.                                   \n";
	s << "\t\t           3) Juego periferico.                                \n";
	s << "\t\t           4) Juego central.                                   \n";
	s << "\t\t           5) Juego islas.                                     \n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::combinaciones() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t______Digite el n\243mero de tableros para jugar [1, 3]___________\n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::tipoTablero(int n) {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t____Digite el tama\244o del tablero # " << n << " __________________________\n";
	s << "\t\t_______________________________________________________________\n\n";
	s << "\t\t           1) 6 puntos (3x2).                                  \n";
	s << "\t\t           2) 9 puntos (3x3).                                  \n";
	s << "\t\t           3) 15 puntos (5x3).                                \n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::solicitarIdentificacion() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t     Digite su identificaci\242n:                                 \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::solicitarIdentificacion1() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t     Digite la identificacion del jugador 1:                   \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::solicitarIdentificacion2() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t     Digite la identificacion del jugador 2:                   \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::minimo(){
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t  SE REQUIERE LA CANTIDAD NECESARIA DE SUCRIPTORES PARA JUGAR!            \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::mismoJugador() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t         NO SE PUEDE JUGAR CON EL MISMO JUGADOR!               \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::entradaErronea() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t        ENTRADA ERRONEA, VALOR DIGITADO NO EXISTE!             \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::solicitarNombre() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t     Digite su nombre:                                         \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::usuarioExistente(){
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t                  USUARIO EXISTENTE!                            \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::correcto() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t                     LISTO!                                    \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::listaLlena() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t				 LO SENTIMOS, LISTA LLENA!                            \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::listaVacia() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t				 LO SENTIMOS, LISTA VACIA!                       \n";
	s << "\t\t_______________________________________________________________\n";
	return s.str();
}

string interfaz::cerrar() {
	stringstream s;
	s << "\t\t_______________________________________________________________\n";
	s << "\t\t.................GRACIAS POR JUGAR.............................\n";
	s << "\t\t_______________________________________________________________\n\n";
	return s.str();
}