
#include "jugador.h"
#include <iostream>
using namespace std;

// Realiza una apuesta si el jugador tiene suficiente saldo
bool Jugador::apostar(int cantidad) {
    if (cantidad <= saldo) {
        saldo -= cantidad;
        return true;
    } else {
        cout << nombre << " no tiene suficiente saldo para apostar." << endl;
        return false;
    }
}

// Devuelve el saldo actual
int Jugador::getSaldo() {
	return saldo;
}

// Modifica el saldo
void Jugador::agregarSaldo(int cantidad) {
	saldo += cantidad;
}

// Muestra la información del jugador
void Jugador::mostrarInfo() {
	cout << "Jugador: " << nombre << ", Saldo: " << saldo << endl;
}
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10