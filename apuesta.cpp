
#include "apuesta.h"
#include <iostream>
using namespace std;

// Devuelve el jugador asociado
Jugador* Apuesta::getJugador() {
	return jugador;
}

// Devuelve la cantidad apostada
int Apuesta::getCantidad() {
	return cantidad;
}

// Devuelve el número apostado
int Apuesta::getNumero() {
	return numero;
}

// Modifica la cantidad apostada
void Apuesta::setCantidad(int c) {
	cantidad = c;
}

// Modifica el número apostado
void Apuesta::setNumero(int n) {
	numero = n;
}

// Muestra la información de la apuesta
void Apuesta::mostrar() const {
    if (jugador) {
        cout << jugador->getNombre() << " apostó "
             << cantidad << " al número " << numero << endl;
    } else {
        cout << "Apuesta sin jugador asociado." << endl;
    }
}
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10   