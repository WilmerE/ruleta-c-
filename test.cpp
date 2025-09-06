#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===== Clase base =====
class Participante {
protected:
    string nombre;
public:
    Participante(string n = "") : nombre(n) {}
    virtual void mostrarInfo() {
        cout << "Participante: " << nombre << endl;
    }
    string getNombre() { return nombre; }
};

// ===== Clase Jugador =====
class Jugador : public Participante {
private:
    int saldo;
public:
    Jugador(string n, int s = 100) : Participante(n), saldo(s) {}
    
    bool apostar(int cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
            return true;
        } else {
            cout << nombre << " no tiene suficiente saldo para apostar." << endl;
            return false;
        }
    }

    void agregarSaldo(int cantidad) { saldo += cantidad; }

    int getSaldo() { return saldo; }

    void mostrarInfo() override {
        cout << "Jugador: " << nombre << " | Saldo: " << saldo << endl;
    }
};

// ===== Clase Apuesta =====
class Apuesta {
private:
    Jugador* jugador;
    int cantidad;
    int numero;
public:
    Apuesta(Jugador* j, int c, int n) : jugador(j), cantidad(c), numero(n) {}

    Jugador* getJugador() { return jugador; }
    int getCantidad() { return cantidad; }
    int getNumero() { return numero; }

    void mostrar() {
        cout << jugador->getNombre() << " apostó " 
             << cantidad << " al número " << numero << endl;
    }
};

// ===== Clase Ruleta =====
class Ruleta {
private:
    vector<Apuesta> apuestas;
public:
    void agregarApuesta(Apuesta a) { apuestas.push_back(a); }

    void mostrarApuestas() {
        if (apuestas.empty()) {
            cout << "No hay apuestas registradas." << endl;
            return;
        }
        cout << "\nApuestas actuales:\n";
        for (auto& ap : apuestas) {
            ap.mostrar();
        }
    }

    void girar() {
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
};

// ===== Programa principal con menú =====
int main() {
    vector<Jugador> jugadores;
    Ruleta ruleta;
    int opcion;

    do {
        cout << "\n=== MENU RULETA ===\n";
        cout << "1. Agregar jugador\n";
        cout << "2. Mostrar jugadores\n";
        cout << "3. Registrar apuesta\n";
        cout << "4. Mostrar apuestas\n";
        cout << "5. Girar ruleta\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre;
            int saldo;
            cout << "Nombre del jugador: ";
            cin >> nombre;
            cout << "Saldo inicial: ";
            cin >> saldo;
            jugadores.push_back(Jugador(nombre, saldo));
        } 
        else if (opcion == 2) {
            if (jugadores.empty()) cout << "No hay jugadores registrados." << endl;
            for (auto& j : jugadores) j.mostrarInfo();
        } 
        else if (opcion == 3) {
            if (jugadores.empty()) {
                cout << "Primero debes agregar jugadores." << endl;
                continue;
            }
            int idx, cantidad, numero;
            cout << "Seleccione jugador (0 a " << jugadores.size()-1 << "): ";
            cin >> idx;
            if (idx < 0 || idx >= jugadores.size()) {
                cout << "Jugador inválido." << endl;
                continue;
            }
            cout << "Monto a apostar: ";
            cin >> cantidad;
            cout << "Número (0–36): ";
            cin >> numero;

            if (numero < 0 || numero > 36) {
                cout << "Número inválido." << endl;
                continue;
            }

            if (jugadores[idx].apostar(cantidad)) {
                ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, numero));
            }
        } 
        else if (opcion == 4) {
            ruleta.mostrarApuestas();
        } 
        else if (opcion == 5) {
            ruleta.girar();
        }
    } while (opcion != 0);

    cout << "Gracias por jugar. ¡Hasta la próxima!" << endl;
    return 0;
}

// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10