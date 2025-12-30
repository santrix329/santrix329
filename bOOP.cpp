#include <iostream>
#include <string>

using namespace std;

class Alumno {
    public:
        string nombre;
        string carnet;

        Alumno(string n, string c) {
            nombre = n;
            carnet = c;


        } 

        void info() {
            cout << "Nombre del alumno: " << nombre << "\n";
            cout << " Carnet del alumno: " << carnet << " \n";
        }
};

int main() {

    string nombre, carnet;

    cout << "Ingrese el nombre del alumno: ";
    getline(cin, nombre);
    cout << "Ingrese el carnet de alumno: ";
    getline(cin, carnet);
    Alumno alumno(nombre, carnet);
    alumno.info();
    return 0;

}