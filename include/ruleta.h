
#ifndef RULETA_H
#define RULETA_H

#include "jugador.h"
#include "apuesta.h"
#include <vector>

// Clase que representa la ruleta y su funcionamiento
class Ruleta {
private:
	vector<Apuesta> apuestas;
public:
    // Agrega una apuesta a la ruleta
	void agregarApuesta(Apuesta a);

    // Muestra todas las apuestas registradas
    void mostrarApuestas();

    // Gira la ruleta y determina los ganadores
    void girar();
};

#endif
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10