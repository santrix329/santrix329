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
            cout << " Ingresa la cedula del estudiante, (8 digitos)" << endl;
            cin >> cedula;
            cout << " Ingresa la edad del estudiante, (de 9 a 18) " << endl;
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
    int opcion;
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
   
system("cls");
    cout << "\n Revision de estudiantes\n";

for (int i = 0; i < cantidad; i++) {
    int decision;
    
    cout << "\n  Estudiante " << (i + 1) << endl;
    estudiantes[i].mostrarDatos();         // seria en esta parte, cuando llamo a la funcion donde ya se guardo nos datos, no aparece
                                           // el nombre del primer estudiante, los demas estudiantes si aparecen correctamente
    cout << "\nQue desea hacer con este estudiante?\n";
    cout << "1. Mantener en la lista\n";
    cout << "2. Eliminar de la lista\n";
    cout << "Opcion: ";
    cin >> decision;
    cin.ignore();
    
    if (decision == 2) {
        
        for (int j = i; j < cantidad - 1; j++) {
            estudiantes[j] = estudiantes[j + 1];
        }
        cantidad--;  
        
        cout << "Estudiante eliminado.\n";
    }
}


cout << "\n lista final de estudiantes\n";
for (int i = 0; i < cantidad; i++) {
    cout << " Estudiante " << (i + 1)  << endl;
    estudiantes[i].mostrarDatos();
}

    return 0;
}