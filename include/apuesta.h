
#ifndef APUESTA_H
#define APUESTA_H

#include "jugador.h" // Para asociar la apuesta a un jugador

enum TipoApuesta {
    PLENO,
    COLOR,
    PARIDAD,
    MITAD,
    COLUMNA,
    DOCENA,
    CERO
};

// Clase que representa una apuesta realizada por un jugador a un número
class Apuesta {
private:
	Jugador* jugador; // Puntero al jugador que realiza la apuesta
	int cantidad;     // Monto apostado
	TipoApuesta tipo;
    int valor;  // depende del tipo (ej: número exacto, 0=rojo 1=negro, etc.)
public:
	// Constructor: inicializa los atributos
	Apuesta(Jugador* j, int c, TipoApuesta t, int v) : jugador(j), cantidad(c), tipo(t), valor(v) {}

	// Devuelve el jugador asociado
	Jugador* getJugador();

	// Devuelve la cantidad apostada
	int getCantidad();

	// Devuelve el tipo de apuesta
	TipoApuesta getTipo();

	// Devuelve el valor de la apuesta
	int getValor();

	// Modifica la cantidad apostada
	void setCantidad(int c);

	// Modifica el valor apostado
	void setValor(int v);

    // Muestra la información de la apuesta
    virtual void mostrar() const;
};

#endif
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10