#include <iostream>
#include <string>
using namespace std;

class Registro {
    private:
       
        string nombre;
        string cedula;
        int edad;

        public:

        void pedirdatos() {
            cout << " Ingresa el nombre completo del estudiante " << endl;
            cin.ignore();
            getline(cin, nombre);
            
            
            cout << " Ingresa la cedula del estudiante " << endl;
            cin >> cedula;
            
            cout << " Ingresa la edad del estudiante " << endl;
            cin >> edad;
            

            system("cls");
            
            
            
        }
            
        void mostrarDatos() {
             static int i = 0;
            i++;
            cout << "\n Datos del estudiante: " << i << " \n";
            cout << " Estudiante: " << nombre << "\n";
            cout << " Cedula : " << cedula << " \n";
            cout << " Edad : " << edad << " \n";
        }

        bool cedulavalida() {
            if (cedula.length() == 8) {
                return true;
            } else {
                return false;       
        
            }
        }

        bool edadvalida() {
            if (edad >= 9 && edad <= 18) {
                return true;
            } else {
                return false;
            }
        }
};



int main() {
    int cantidad;
    cout << " Cuantos estudiantes vas  registrar? \n";
    cin >> cantidad;
    
    Registro* estudiantes = new Registro[cantidad];

    for(int i = 0; i < cantidad; i++) {
        cout << "\n Registro de estudiante " << (i + 1) << " \n";
        estudiantes[i].pedirdatos();
        if (!estudiantes[i].cedulavalida() || !estudiantes[i].edadvalida()) {
            cout << " Datos invalidos \n";
            cout << " Debe repetir el estudiante " << (i + 1) << " \n";
            i--;
        }
    }

    cout << "\n Lista de estudiantes registrados: \n";
    for(int i = 0; i < cantidad; i++) {
        estudiantes[i].mostrarDatos();
    }
    delete[] estudiantes;
    return 0;
}
    