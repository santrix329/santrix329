// --- TIC-TAC-TOE GAME START ---

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

// --- Prototipos de funciones (con nombres personalizados en español) ---
void reiniciarTablero(char tablero[3][3]);
void mostrarTablero(const char tablero[3][3]);
bool esMovimientoValido(const char tablero[3][3], int fila, int columna);
void realizarMovimiento(char tablero[3][3], int fila, int columna, char fichaJugador);
bool comprobarGanador(const char tablero[3][3], char fichaJugador);
bool comprobarEmpate(const char tablero[3][3]);
void limpiarPantalla();
void esperarEnter();
void mostrarInstrucciones();

// --- Función Principal ---
int main() {
    char tablero[3][3];
    char turnoActual = 'X';
    bool finPartida = false;

    std::string nombreJugadorX;
    std::string nombreJugadorO;
    int puntosX = 0;
    int puntosO = 0;

    std::cout << "Ingresa el nombre del Jugador X: ";
    std::getline(std::cin, nombreJugadorX);

    std::cout << "Ingresa el nombre del Jugador O: ";
    std::getline(std::cin, nombreJugadorO);

    mostrarInstrucciones();
    esperarEnter();

    bool seguirJugando = true;

    while (seguirJugando) {
        reiniciarTablero(tablero);
        finPartida = false;
        turnoActual = 'X';

        while (!finPartida) {
            limpiarPantalla();

            std::cout << "Marcador:\n";
            std::cout << nombreJugadorX << " (X): " << puntosX << " victorias\n";
            std::cout << nombreJugadorO << " (O): " << puntosO << " victorias\n\n";

            mostrarTablero(tablero);

            int fila;
            int columna;
            bool entradaValida = false;

            while (!entradaValida) {
                std::cout << (turnoActual == 'X' ? nombreJugadorX : nombreJugadorO);
                std::cout << ", ingresa tu jugada (fila columna, ej: 0 1): ";

                std::cin >> fila >> columna;

                if (std::cin.fail() || fila < 0 || fila > 2 || columna < 0 || columna > 2) {
                    std::cout << "Entrada inválida. Usa números entre 0 y 2.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (esMovimientoValido(tablero, fila, columna)) {
                    entradaValida = true;
                } else {
                    std::cout << "Esa posición ya está ocupada. Intenta de nuevo.\n";
                }
            }

            realizarMovimiento(tablero, fila, columna, turnoActual);

            if (comprobarGanador(tablero, turnoActual)) {
                limpiarPantalla();
                mostrarTablero(tablero);
                std::cout << (turnoActual == 'X' ? nombreJugadorX : nombreJugadorO);
                std::cout << " gana la partida. ¡Felicidades!\n";

                if (turnoActual == 'X') {
                    puntosX++;
                } else {
                    puntosO++;
                }

                finPartida = true;
            } else if (comprobarEmpate(tablero)) {
                limpiarPantalla();
                mostrarTablero(tablero);
                std::cout << "¡Empate! Nadie gana esta vez.\n";
                finPartida = true;
            } else {
                turnoActual = (turnoActual == 'X') ? 'O' : 'X';
            }
        }

        std::cout << "\n¿Desean jugar otra partida? (s/n): ";
        char respuesta;
        std::cin >> respuesta;
        if (respuesta != 's' && respuesta != 'S') {
            seguirJugando = false;
        }
    }

    std::cout << "\nMarcador final:\n";
    std::cout << nombreJugadorX << " (X): " << puntosX << " victorias\n";
    std::cout << nombreJugadorO << " (O): " << puntosO << " victorias\n";
    std::cout << "\n¡Gracias por jugar!\n";

    esperarEnter();
    return 0;
}

void reiniciarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero(const char tablero[3][3]) {
    std::cout << "   0   1   2\n";
    std::cout << "  -------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " | " << tablero[i][0] << " | " << tablero[i][1] << " | " << tablero[i][2] << " |\n";
        std::cout << "  -------------\n";
    }
    std::cout << std::endl;
}

bool esMovimientoValido(const char tablero[3][3], int fila, int columna) {
    return tablero[fila][columna] == ' ';
}

void realizarMovimiento(char tablero[3][3], int fila, int columna, char fichaJugador) {
    tablero[fila][columna] = fichaJugador;
}

bool comprobarGanador(const char tablero[3][3], char fichaJugador) {
    for (int i = 0; i < 3; ++i) {
        if (tablero[i][0] == fichaJugador && tablero[i][1] == fichaJugador && tablero[i][2] == fichaJugador) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (tablero[0][j] == fichaJugador && tablero[1][j] == fichaJugador && tablero[2][j] == fichaJugador) {
            return true;
        }
    }
    if (tablero[0][0] == fichaJugador && tablero[1][1] == fichaJugador && tablero[2][2] == fichaJugador) {
        return true;
    }
    if (tablero[0][2] == fichaJugador && tablero[1][1] == fichaJugador && tablero[2][0] == fichaJugador) {
        return true;
    }
    return false;
}

bool comprobarEmpate(const char tablero[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void esperarEnter() {
    std::cout << "\nPresiona Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void mostrarInstrucciones() {
    std::cout << "\n\nInstrucciones:\n";
    std::cout << "Este es un juego clásico de Tres en Línea (Tic-Tac-Toe).\n";
    std::cout << "Cada jugador toma turnos para colocar su marca (X u O)\n";
    std::cout << "en un tablero de 3x3.\n";
    std::cout << "El primero en alinear tres marcas horizontal, vertical\n";
    std::cout << "o diagonalmente gana.\n";
    std::cout << "Para jugar, ingresa el número de fila y columna (0, 1 o 2).\n";
    std::cout << "Si el tablero se llena sin un ganador, es un empate.\n";
}

// --- TIC-TAC-TOE GAME END ---
