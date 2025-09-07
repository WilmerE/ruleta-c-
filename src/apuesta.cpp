
#include "../include/apuesta.h"
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

// Devuelve el tipo de apuesta
TipoApuesta Apuesta::getTipo() {
    return tipo;
}

// Devuelve el valor de la apuesta
int Apuesta::getValor() {
	return valor;
}

// Modifica la cantidad apostada
void Apuesta::setCantidad(int c) {
	cantidad = c;
}

// Modifica el valor de la apuesta
void Apuesta::setValor(int v) {
	valor = v;
}

// Muestra la información de la apuesta
void Apuesta::mostrar() const {
    cout << jugador->getNombre() << " apostó " << cantidad << " en ";
    switch(tipo) {
        case COLOR: cout << (valor == 0 ? "Rojo" : "Negro"); break;
        case PARIDAD: cout << (valor == 0 ? "Par" : "Impar"); break;
        case MITAD: cout << (valor == 0 ? "1-18" : "19-36"); break;
        case COLUMNA: cout << "Columna " << (valor+1); break;
        case DOCENA: cout << "Docena " << (valor+1); break;
        case CERO: cout << "Cero (0)"; break;
        case PLENO: cout << "número " << valor; break;
        default: cout << "Apuesta desconocida"; break;
    }
    cout << endl;
}
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10   