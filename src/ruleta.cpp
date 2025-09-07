
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
    int ganador = rand() % 37;
    cout << "\n=== Girando la ruleta... cayó en el número " 
         << ganador << " ===\n";

    // Determinar color (simplificación: pares = negro, impares = rojo)
    bool esRojo = (ganador % 2 == 1 && ganador != 0);

    for (auto& ap : apuestas) {
        bool acierto = false;
        int premio = 0;

        switch(ap.getTipo()) {
            case PLENO:
                if (ap.getValor() == ganador) {
                    premio = ap.getCantidad() * 36;
                    acierto = true;
                }
                break;
            case COLOR:
                if ((ap.getValor() == 0 && esRojo) || 
                    (ap.getValor() == 1 && !esRojo && ganador != 0)) {
                    premio = ap.getCantidad() * 2;
                    acierto = true;
                }
                break;
            case PARIDAD:
                if (ganador != 0 && (ganador % 2 == ap.getValor())) {
                    premio = ap.getCantidad() * 2;
                    acierto = true;
                }
                break;
            case MITAD:
                if ((ap.getValor() == 0 && ganador >= 1 && ganador <= 18) ||
                    (ap.getValor() == 1 && ganador >= 19 && ganador <= 36)) {
                    premio = ap.getCantidad() * 2;
                    acierto = true;
                }
                break;
            case COLUMNA:
                if (ganador != 0 && ((ganador-1) % 3 == ap.getValor())) {
                    premio = ap.getCantidad() * 3;
                    acierto = true;
                }
                break;
            case DOCENA:
                if (ganador >= ap.getValor()*12+1 && ganador <= (ap.getValor()+1)*12) {
                    premio = ap.getCantidad() * 3;
                    acierto = true;
                }
                break;
            case CERO:
                if (ganador == 0) {
                    premio = ap.getCantidad() * 36;
                    acierto = true;
                }
                break;
        }

        if (acierto) {
            ap.getJugador()->agregarSaldo(premio);
            cout << "🎉 " << ap.getJugador()->getNombre() 
                 << " ganó " << premio << "!" << endl;
        }
    }

    apuestas.clear();
}
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10