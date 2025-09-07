
// Evita que el archivo se incluya más de una vez
#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H


#include <string> // Para usar el tipo string
using namespace std; // Facilita el uso de string sin std::


// Clase base para representar un participante genérico
class Participante {
protected:
    string nombre; // Nombre del participante
public:
    // Constructor: permite inicializar el nombre (por defecto vacío)
    Participante(string n = "") : nombre(n) {}

    // Método virtual: muestra información del participante (puede ser redefinido en subclases)
    virtual void mostrarInfo();

    // Devuelve el nombre del participante
    string getNombre();
};


#endif
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10