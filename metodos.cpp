
#include <iostream> 

#include <cmath> 

#include <iomanip> 

#include <cstdlib> 

 

 

using namespace std; 

 

// Definición de la función f(x) = ln(x+1) + x - 2 

double funcion(double x) { 

     

    if (x <= -1.0) { 

        

        cerr << "Error: El argumento de ln(x+1) debe ser positivo (x > -1)." << endl; 

        return NAN;  

    } 

    // log(x) en C++ es el logaritmo natural (ln) 

    return log(x + 1.0) + x - 2.0; 

} 

 

// Función principal del método de bisección 

void biseccion(double a, double b, double tolerancia, int max_iteraciones) { 

    double fa = funcion(a); 

    double fb = funcion(b); 

 

    // lo usamos para ver si hay cambio de signo en el intervalo 

    if (fa * fb >= 0) { 

        cout << "mal, tienen que tener distintos signos [" << a << ", " << b << "]." << endl; 

        cout << "f(" << a << ") = " << fa << ", f(" << b << ") = " << fb << endl; 

        cout << "Busca otro intervalo inicial." << endl; 

        return; 

    } 

 

    double c, fc; // c es el punto medio 

    int iteracion = 0; 

     

    //  encabezdo de la tabla 

    cout << "\n---------------------------------------------------------------------" << endl; 

    cout << setw(10) << "Iteración"  

              << setw(15) << "a"  

              << setw(15) << "b"  

              << setw(15) << "c"  

              << setw(15) << "f(c)"  

              << setw(15) << "|b-a|" << endl; 

    cout << "---------------------------------------------------------------------" << endl; 

 

    while (iteracion < max_iteraciones) { 

         

        c = (a + b) / 2.0; 

        fc = funcion(c); 

 

        //  resultados de la iteración 

        cout << fixed << setprecision(8); 

        cout << setw(10) << iteracion + 1  

                  << setw(15) << a  

                  << setw(15) << b  

                  << setw(15) << c  

                  << setw(15) << fc 

                  << setw(15) << abs(b - a) << endl; 

 

         

        if (abs(b - a) / 2.0 < tolerancia) { 

            cout << "\n---------------------------------------------------------------------" << endl; 

            cout << " Convergencia alcanzada." << endl; 

            cout << "Raiz aproximada: " << c << endl; 

            cout << "Numero de iteraciones: " << iteracion + 1 << endl; 

            return; 

        } 

 

        

        if (fa * fc < 0) { 

            // La raíz esta en [a, c]. Entoces se actualiza b 

            b = c; 

             

        } else {  

            a = c; 

            fa = fc; // Actualizamos f(a) para la siguiente iteracion 

        } 

 

        iteracion++; 

    } 

 

     

    cout << "\n---------------------------------------------------------------------" << endl; 

    cout << " Se alcanzo el número maximo de iteraciones (" << max_iteraciones << ")." << endl; 

    cout << "La ultima aproximacion es: " << c << endl; 

    cout << "La tolerancia requerida no se logro." << endl; 

} 

 

int main() { 

     

    double a, b, tolerancia; 

    int max_iteraciones; 

 

    cout << " Metodo de Biseccion para f(x) = ln(x+1) + x - 2 ---" << endl; 

 

    // Pedir el intervalo al usuario 

    cout << "Ingrese el extremo inferior a del intervalo: "; 

    cin >> a; 

    cout << "Ingrese el extremo superior b del intervalo: "; 

    cin >> b; 

 

     

    cout << "Ingrese la tolerancia, ej: 0.0001: "; 

    cin >> tolerancia; 

    cout << "Ingrese el numero maximo de iteraciones ej: 50: "; 

    cin >> max_iteraciones; 

 

     

    biseccion(a, b, tolerancia, max_iteraciones); 

 

    return 0; 

} 