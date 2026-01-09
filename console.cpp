#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    // Configurar la consola para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Consola configurada para UTF-8.\n";
    return 0;
}