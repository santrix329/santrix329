#include <iostream>


using namespace std;

class Cuadrado {
public:
    float base;
    float altura;

    Cuadrado(float b, float h) {
        base = b;
        altura = h;
    }
    float area() {
        return base * altura;
    }
};

int main() {

    float b, h;
    
    cout << "Ingrese la base del cuadrado  ";
    cin >> b;
    cout << "Ingrese la altura del cuadrado: ";
    cin >> h;

    Cuadrado cuadrado(b, h);
    cout << "El área del cuadrado es: " << cuadrado.area() << endl;

    

    Cuadrado triangulo(b, h);
    cout << "El área del triángulo es: " << triangulo.area() / 2 << endl;
   

    
    
    int option;
    switch (option) {
        case 1:  cout << "Área del cuadrado: " << cuadrado.area() << endl;
            break;
        case 2:  cout << "Área del triángulo: " << triangulo.area() / 2 << endl;
            break;
        default: cout << "Opción no válida." << endl;
            break;
    }
   
}

    
    