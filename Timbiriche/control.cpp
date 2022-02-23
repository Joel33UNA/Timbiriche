/*
UNIVERSIDAD NACIONAL DE COSTA RICA
EIF-204  -  PROGRAMACIÓN II
ESTUDIANTES: JOEL ZAMORA Y DIEGO JIMÉNEZ
PROFESOR: SANTIAGO CAAMAÑO POLINI
*/

#include "control.h"

control::control() : dots(new empresaDots())
{}

control::~control() { delete dots; }

void control::cargar() {
	archivo a("juegos.txt", dots);
	a.abrirLectura();
	dots->establecerPartidas(a.recuperarPartidas());
	a.cerrar();
	controlIniciar();
}

void control::controlIniciar() {
	int opcion = 0;
	do {
		utiles::limpiar();
		utiles::imprimir(interfaz::iniciar());
		opcion = utiles::leerSeleccion(0, 2);
		switch (opcion) {
		case 1: controlMenu(); break;
		case 2: controlLeer(); break; // FALTA
		case 0: controlCerrar(); break; // FALTA GUARDAR
		}
	} while (opcion != 0);
}

void control::controlMenu() {
	int opcion = 0;
	do {
		utiles::limpiar();
		utiles::imprimir(interfaz::menu());
		opcion = utiles::leerSeleccion(0, 4);
		switch (opcion) {
		case 1: controlDatos(); break;
		case 2: controlModalidad(); break; // FALTA
		case 3: controlCambio(); break;
		case 4: controlVisualizar(); break;
		case 0: controlIniciar(); break;
		}
	} while (opcion != 0);
}

void control::controlLeer() {
	if (dots->existenPartidas()) {
		utiles::limpiar();
		utiles::imprimir(dots->toStringPartidas());
		utiles::imprimir("\nDigite el n\243mero del juego que desea reproducir: ");
		int cod = utiles::leerEntero();
		if (dots->existeJuego(cod)) {
			juego* part = dots->obtenerPartida(cod);
			part->reproducir();
		}
		else {
			utiles::limpiar();
			utiles::imprimir(interfaz::entradaErronea());
			utiles::esperar(1500);
		}
	}
	else {
		utiles::limpiar();
		utiles::imprimir(interfaz::listaVacia());
		utiles::pausa();
	}
}

void control::controlDatos() {
	utiles::limpiar();
	utiles::imprimir(interfaz::solicitarIdentificacion());
	string identificacion = utiles::leerString();
	utiles::limpiar();
	utiles::imprimir(interfaz::solicitarNombre());
	string nombre = utiles::leerString();
	if (!dots->existeJugador(identificacion)) {
		jugador* jug = new jugador(nombre, identificacion);
		if (dots->attach(jug)) {
			dots->notify();
			utiles::limpiar();
			utiles::imprimir(interfaz::correcto());
			utiles::esperar(1500);
		}
		else {
			utiles::limpiar();
			utiles::imprimir(interfaz::listaLlena());
			utiles::esperar(1500);
		}
	}
	else {
		utiles::limpiar();
		utiles::imprimir(interfaz::usuarioExistente());
		utiles::esperar(1500);
	}
}

void control::controlModalidad() {
	int opcion = 0;
	do {
		utiles::limpiar();
		utiles::imprimir(interfaz::modalidad());
		opcion = utiles::leerSeleccion(0, 2);
		switch (opcion) {
		case 1: controlVSHumano(); break;
		case 2: controlVSMaquina(); break;
		case 0: controlMenu(); break;
		}
	} while (opcion != 0);
}

void control::controlVSHumano() {
	if (dots->minimo()) {
		utiles::limpiar();
		utiles::imprimir(dots->toString());
		utiles::imprimir(interfaz::solicitarIdentificacion1());
		string identificacion1 = utiles::leerString();
		utiles::limpiar();
		utiles::imprimir(dots->toString());
		utiles::imprimir(interfaz::solicitarIdentificacion2());
		string identificacion2 = utiles::leerString();
		if (identificacion1 != identificacion2) {
			if (dots->existeJugador(identificacion1) && dots->existeJugador(identificacion2)) {
				int opcion = 0;
				juego* j = new juego();
				campoComposite* seis = NULL;
				campoComposite* nueve = NULL;
				campoComposite* quince = NULL;
				dots->agregarJuego(j);
				jugador* jug1 = dots->recuperarJugador(identificacion1);
				jugador* jug2 = dots->recuperarJugador(identificacion2);
				j->agregarJugador(jug1);
				j->agregarJugador(jug2);
				utiles::limpiar();
				utiles::imprimir(interfaz::combinaciones());
				int combinaciones = utiles::leerSeleccion(1, 3);
				for (int i = 0; i < combinaciones; i++) {
					utiles::limpiar();
					utiles::imprimir(interfaz::tipoTablero(i + 1));
					opcion = utiles::leerSeleccion(1, 3);
					switch (opcion) {
					case 1: { campoComposite* seis = new seisPuntos(); j->agregarAlContenedor(seis); break; }
					case 2: { campoComposite* nueve = new nuevePuntos(); j->agregarAlContenedor(nueve); break; }
					case 3: { campoComposite* quince = new quincePuntos(); j->agregarAlContenedor(quince); break; }
					}
				}
				j->draw();
				j->jugarVSHumano();
			}
			else {
				utiles::limpiar();
				utiles::imprimir(interfaz::entradaErronea());
				utiles::esperar(1500);
			}
		}
		else {
			utiles::limpiar();
			utiles::imprimir(interfaz::mismoJugador());
			utiles::esperar(1500);
		}
	}
	else {
		utiles::limpiar();
		utiles::imprimir(interfaz::minimo());
		utiles::esperar(1500);
	}
}

void control::controlVSMaquina() {
	if (dots->minimo1()) {
		int opcionEstrategia = 0;
		utiles::limpiar();
		utiles::imprimir(interfaz::estrategia());
		opcionEstrategia = utiles::leerSeleccion(1, 5);
		utiles::limpiar();
		utiles::imprimir(dots->toString());
		utiles::imprimir(interfaz::solicitarIdentificacion());
		string identificacion = utiles::leerString();
		utiles::limpiar();
		if (dots->existeJugador(identificacion)) {
			int opcionTableros = 0;
			juego* j = new juego();
			campoComposite* seis = NULL;
			campoComposite* nueve = NULL;
			campoComposite* quince = NULL;
			dots->agregarJuego(j);
			jugador* jug1 = dots->recuperarJugador(identificacion);
			j->agregarJugador(jug1);
			j->agregarJugador(new jugador("Computadora", "IA"));
			utiles::limpiar();
			utiles::imprimir(interfaz::combinaciones());
			int combinaciones = utiles::leerSeleccion(1, 3);
			for (int i = 0; i < combinaciones; i++) {
				utiles::limpiar();
				utiles::imprimir(interfaz::tipoTablero(i + 1));
				opcionTableros = utiles::leerSeleccion(1, 3);
				switch (opcionTableros) {
				case 1: { campoComposite* seis = new seisPuntos(); j->agregarAlContenedor(seis); break; }
				case 2: { campoComposite* nueve = new nuevePuntos(); j->agregarAlContenedor(nueve); break; }
				case 3: { campoComposite* quince = new quincePuntos(); j->agregarAlContenedor(quince); break; }
				}
			}
			j->draw();
			estrategia* e = NULL;
			switch (opcionEstrategia) {
			case 1: e = new estrategiaAleatoria(j->getTablero(), j->getN(), j->getM()); break;
			case 2: e = new estrategiaCercana(j->getTablero(), j->getN(), j->getM()); break;
			case 3: e = new estrategiaPeriferica(j->getTablero(), j->getN(), j->getM()); break;
			case 4: e = new estrategiaCentral(j->getTablero(), j->getN(), j->getM()); break;
			case 5: e = new estrategiaIslas(j->getTablero(), j->getN(), j->getM()); break;
			}
			j->jugarVSMaquina(e);
		}
		else {
			utiles::limpiar();
			utiles::imprimir(interfaz::entradaErronea());
			utiles::esperar(1500);
		}
	}
	else{
		utiles::limpiar();
		utiles::imprimir(interfaz::minimo());
		utiles::esperar(1500);
	}
}

void control::controlCambio() {
	utiles::limpiar();
	dots->setCodigo();
	utiles::imprimir(interfaz::correcto());
	utiles::esperar(1500);
}

void control::controlVisualizar() {
	utiles::limpiar();
	utiles::imprimir(dots->toString());
	utiles::pausa();
}

void control::controlCerrar() {
	archivo a("juegos.txt", dots);
	a.abrirEscritura();
	a.guardarPartidas(dots->obtenerPartidas());
	a.cerrar();
	utiles::limpiar();
	utiles::imprimir(interfaz::cerrar());
	utiles::pausa();
	utiles::salir();
}