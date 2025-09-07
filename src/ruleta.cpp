
#include "../include/ruleta.h"
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <iostream>

using namespace std;

void Ruleta::agregarApuesta(Apuesta a) {
    apuestas.push_back(a);
}

void Ruleta::mostrarApuestas() {
    if (apuestas.empty()) {
        cout << "No hay apuestas registradas." << endl;
        return;
    }
    cout << "\nApuestas actuales:\n";
    for (auto& ap : apuestas) {
        ap.mostrar();
    }
}

void Ruleta::girar() {
    if (apuestas.empty()) {
            cout << "No se puede girar, no hay apuestas." << endl;
            return;
        }
        srand(time(0));
        int ganador = rand() % 37; // 0–36
        cout << "\n=== Girando la ruleta... cayó en el número " 
             << ganador << " ===\n";

        bool huboGanador = false;
        for (auto& ap : apuestas) {
            if (ap.getNumero() == ganador) {
                int premio = ap.getCantidad() * 36;
                ap.getJugador()->agregarSaldo(premio);
                cout << "🎉 " << ap.getJugador()->getNombre() 
                     << " ganó " << premio << "!" << endl;
                huboGanador = true;
            }
        }
        if (!huboGanador) {
            cout << "Nadie acertó esta vez." << endl;
        }

        apuestas.clear();
}
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10