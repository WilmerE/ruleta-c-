
#ifndef JUGADOR_H
#define JUGADOR_H

#include "participante.h" // Hereda de Participante

// Clase Jugador, derivada de Participante
class Jugador : public Participante {
private:
	int saldo; // Saldo del jugador
public:
	// Constructor: inicializa nombre y saldo
	Jugador(string n, int s) : Participante(n), saldo(s) {}

    // Realiza una apuesta si el jugador tiene suficiente saldo
    bool apostar(int cantidad);

	// Devuelve el saldo actual
	int getSaldo();

	// Modifica el saldo
	void agregarSaldo(int cantidad);

    // Muestra la información del jugador (sobrescribe mostrarInfo de Participante)
	void mostrarInfo() override;
};

#endif
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10