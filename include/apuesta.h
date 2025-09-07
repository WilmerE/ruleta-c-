
#ifndef APUESTA_H
#define APUESTA_H

#include "jugador.h" // Para asociar la apuesta a un jugador

// Clase que representa una apuesta realizada por un jugador a un número
class Apuesta {
private:
	Jugador* jugador; // Puntero al jugador que realiza la apuesta
	int cantidad;     // Monto apostado
	int numero;       // Número al que se apuesta
public:
	// Constructor: inicializa los atributos
	Apuesta(Jugador* j, int c, int n) : jugador(j), cantidad(c), numero(n) {}

	// Devuelve el jugador asociado
	Jugador* getJugador();

	// Devuelve la cantidad apostada
	int getCantidad();

	// Devuelve el número apostado
	int getNumero();

	// Modifica la cantidad apostada
	void setCantidad(int c);

	// Modifica el número apostado
	void setNumero(int n);

    // Muestra la información de la apuesta
    virtual void mostrar() const;
};

#endif
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10