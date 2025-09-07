
#include "../include/participante.h" // Incluye la definición de la clase Participante
#include <iostream> // Para operaciones de entrada/salida
using namespace std; // Facilita el uso de cout y endl


// Muestra la información básica del participante en consola
void Participante::mostrarInfo() {
    cout << "Participante: " << nombre << endl;
}


// Devuelve el nombre del participante
string Participante::getNombre() {
    return nombre;
}

// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10