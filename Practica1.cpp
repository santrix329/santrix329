#include <iostream>
#include <cmath> // Esto es para usar sqrt()
using namespace std;

int main() {
    // Declaramos las variables para a, b, c, y también la discriminante
    double a, b, c;
    double discriminante, x1, x2;

    // Le Pido al usuario que ingrese los valores de a, b y c
    cout << " Ete es un programa para resolver ecuaciones de segundo grado ax^2 + bx + c = 0\n";
    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;
    cout << "Ingrese el valor de c: ";
    cin >> c;

    // Aqui vamos a mostrar la ecuación de segundo grado que vamos a resolver
    cout << "\nLa ecuacion es: " << a << "x^2 + " << b << "x + " << c << " = 0\n";

    // Verificamos si a es 0, porque entonces no sería una ecuación de segundo grado
    if (a == 0) {
        cout << "Error: 'a' no puede ser 0 en una ecuacion de segundo grado.\n";
        return 1; // Termina el programa
    }

    // Calculamos el discriminante (b^2 - 4ac)
    discriminante = b * b - 4 * a * c;
    cout << "Paso 1: Calculamos el discriminante (b^2 - 4ac)\n";
    cout << "Discriminante = " << b << "^2 - 4 * " << a << " * " << c << " = " << discriminante << "\n";

    // Verificamos si el discriminante es mayor o igual a 0
    if (discriminante >= 0) {
        // Calculamos las dos soluciones usando la fórmula resolvente
        cout << "\nPaso 2: Como el discriminante es >= 0, hay soluciones reales.\n";
        cout << "Fórmula: x = (-b ± sqrt(b^2 - 4ac)) / (2a)\n";

        // Solución 1: con el signo +
        x1 = (-b + sqrt(discriminante)) / (2 * a);
        cout << "x1 = (" << -b << " + sqrt(" << discriminante << ")) / (2 * " << a << ")\n";
        cout << "x1 = " << x1 << "\n";

        // Solución 2: con el signo -
        x2 = (-b - sqrt(discriminante)) / (2 * a);
        cout << "x2 = (" << -b << " - sqrt(" << discriminante << ")) / (2 * " << a << ")\n";
        cout << "x2 = " << x2 << "\n";

        // Si el discriminante es 0, las soluciones son iguales
        if (discriminante == 0) {
            cout << "El discriminante es 0, por lo que x1 y x2 son iguales.\n";
        }
    } else {
        // Si el discriminante es menor que 0, no hay soluciones reales
        cout << "\nPaso 2: Como el discriminante es menor que 0, no hay soluciones reales.\n";
    }

    return 0;
}