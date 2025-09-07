#include <iostream>
#include <cstdlib> // Required for system()
#include "jugador.h"
#include "apuesta.h"
#include "ruleta.h"
using namespace std;

int main() {
    vector<Jugador> jugadores;
    Ruleta ruleta;
    int opcion;

    do{
        system("clear"); // Limpiar pantalla
        // Mostrar tabla de ruleta simulada
        cout << "==============================\n";
        cout << "|         TABLA RULETA        |\n";
        cout << "==============================\n";
        cout << "                /------------\\" << endl;
        cout << "_______________|______ 0 _____|\n";
        cout << "|   1-18  |    | 1  | 2  | 3  |\n";
        cout << "|_________| 12 | 4  | 5  | 6  |\n";
        cout << "|  Pares  |____| 7  | 8  | 9  |\n";
        cout << "|_________|    | 10 | 11 | 12 |\n";
        cout << "|  negros | 12 | 13 | 14 | 15 |\n";
        cout << "|_________|____| 16 | 17 | 18 |\n";
        cout << "|  rojos  |    | 19 | 20 | 21 |\n";
        cout << "|_________| 12 | 22 | 23 | 24 |\n";
        cout << "| Impares |____| 25 | 26 | 27 |\n";
        cout << "|_________|    | 28 | 29 | 30 |\n";
        cout << "|  19-36  | 12 | 31 | 32 | 33 |\n";
        cout << "|_________|____| 34 | 35 | 36 |\n";
        cout << "               |--------------|\n";
        cout << "               | 2a1| 2a1| 2a1|\n";
        cout << "                \\------------/\n";
        cout << "==============================\n\n";

        // Menú de opciones pendientes
        cout << "MENU PRINCIPAL:\n";
        cout << "1. Agregar jugador\n";
        cout << "2. Mostrar jugadores\n";
        cout << "3. Registrar apuesta\n";
        cout << "4. Mostrar apuestas\n";
        cout << "5. Girar ruleta\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            system("clear"); // Limpiar pantalla
            // TITULO OPCION
            cout << "==============================\n";
            cout << "|      AGREGAR JUGADOR       |\n";
            cout << "==============================\n\n";
            // Solicitar datos del jugador
            string nombre;
            int saldo;
            cout << "Nombre del jugador: ";
            cin >> nombre;
            cout << "Saldo inicial: ";
            cin >> saldo;
            jugadores.push_back(Jugador(nombre, saldo));
            // system("pause"); --- IGNORE ---
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        } else if (opcion == 2) {
            system("clear");
            // TITULO OPCION
            cout << "==============================\n";
            cout << "|      MOSTRAR JUGADORES      |\n";
            cout << "==============================\n\n";
            // Mostrar información de los jugadores
            if (jugadores.empty()) cout << "No hay jugadores registrados." << endl;
            for (auto& j : jugadores) j.mostrarInfo();
            // system("pause"); --- IGNORE ---
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        } else if (opcion == 3) {
            system("clear");
            // TITULO OPCION
            cout << "==============================\n";
            cout << "|      REGISTRAR APUESTA      |\n";
            cout << "==============================\n\n";
            // Verificar que haya jugadores
            if (jugadores.empty()) {
                cout << "Primero debes agregar jugadores." << endl;
                continue;
            }
            // Registrar una apuesta
            // Actualmente solo permite apuestas a un número específico
            // Hacen falta más tipos de apuestas: color, par/impar, docena, columna, etc...
            int idx, cantidad, tipo, valor;
            cout << "Jugadores disponibles:\n";
            for (size_t i = 0; i < jugadores.size(); ++i) {
                cout << i << ": " << jugadores[i].getNombre() << endl;
            }
            cout << "\nSeleccione un jugador (0 a " << jugadores.size()-1 << "): ";
            cin >> idx;
            if (idx < 0 || idx >= jugadores.size()) {
                cout << "Jugador inválido." << endl;
                continue;
            }
            cout << "Monto a apostar: ";
            cin >> cantidad;

            cout << "\nTipo de apuesta:\n";
            cout << "1. Pleno (número exacto)\n";
            cout << "2. Color (0=Rojo, 1=Negro)\n";
            cout << "3. Par/Impar (0=Par, 1=Impar)\n";
            cout << "4. Mitad (0=1–18, 1=19–36)\n";
            cout << "5. Columna (0=1ra, 1=2da, 2=3ra)\n";
            cout << "6. Docena (0=1–12, 1=13–24, 2=25–36)\n";
            cout << "7. Cero (0)\n";
            cout << "Seleccione: ";
            cin >> tipo;

            if (tipo == 1) {
                cout << "Número (0–36): ";
                cin >> valor;
                if (valor < 0 || valor > 36) {
                    cout << "Número inválido." << endl;
                    continue;
                }
                if (jugadores[idx].apostar(cantidad)) {
                    ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, PLENO, valor));
                }
            }
            else if (tipo == 2) {
                cout << "Color (0=Rojo, 1=Negro): ";
                cin >> valor;
                if (valor != 0 && valor != 1) { cout << "Color inválido."; continue; }
                if (jugadores[idx].apostar(cantidad)) {
                    ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, COLOR, valor));
                }
            }
            else if (tipo == 3) {
                cout << "Paridad (0=Par, 1=Impar): ";
                cin >> valor;
                if (valor != 0 && valor != 1) { cout << "Valor inválido."; continue; }
                if (jugadores[idx].apostar(cantidad)) {
                    ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, PARIDAD, valor));
                }
            }
            else if (tipo == 4) {
                cout << "Mitad (0=1–18, 1=19–36): ";
                cin >> valor;
                if (valor != 0 && valor != 1) { cout << "Valor inválido."; continue; }
                if (jugadores[idx].apostar(cantidad)) {
                    ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, MITAD, valor));
                }
            }
            else if (tipo == 5) {
                cout << "Columna (0=1ra, 1=2da, 2=3ra): ";
                cin >> valor;
                if (valor < 0 || valor > 2) { cout << "Columna inválida."; continue; }
                if (jugadores[idx].apostar(cantidad)) {
                    ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, COLUMNA, valor));
                }
            }
            else if (tipo == 6) {
                cout << "Docena (0=1–12, 1=13–24, 2=25–36): ";
                cin >> valor;
                if (valor < 0 || valor > 2) { cout << "Docena inválida."; continue; }
                if (jugadores[idx].apostar(cantidad)) {
                    ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, DOCENA, valor));
                }
            }
            else if (tipo == 7) {
                valor = 0;
                if (jugadores[idx].apostar(cantidad)) {
                    ruleta.agregarApuesta(Apuesta(&jugadores[idx], cantidad, CERO, valor));
                }
            }
            else {
                cout << "Opción inválida." << endl;
            }
            // system("pause"); --- IGNORE ---
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        } else if (opcion == 4) {
            system("clear");
            // TITULO OPCION
            cout << "==============================\n";
            cout << "|      MOSTRAR APUESTAS       |\n";
            cout << "\n==============================\n\n";
            // Mostrar todas las apuestas registradas
            ruleta.mostrarApuestas();
            // system("pause"); --- IGNORE ---
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        } else if (opcion == 5) {
            system("clear");
            // TITULO OPCION
            cout << "==============================\n";
            cout << "|         GIRAR RULETA        |\n";
            cout << "==============================\n\n";
            // Girar la ruleta
            ruleta.girar();
            // system("pause"); --- IGNORE ---
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 0);

    cout << "\nGracias por jugar. ¡Hasta la próxima!" << endl;
    return 0;
}
// Compilado con C++14
// Autor: P3L1CO
// Fecha: 2024-06-10