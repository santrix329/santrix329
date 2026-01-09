#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "=== Registro de Candidatos ===\n";
    cout << "Vamos a registrar 5 candidatos para la votación.\n";

    string candidatos[5];

    for(int i = 0; i < 5; i++) {

        cout <<" Ingrese el nombre del candidato " << i + 1 << ": ";
        getline(cin, candidatos[i]);
        cout << " El candidato numero " << i + 1 << " es : " << candidatos[i] << "\n";
        
    }
    


    system("cls");
    cout << " Registro completado para todos candidato.\n";
    cout << "=== Configuración de la Votación ===\n";
    cout << "Necesitamos saber cuántos votantes habrá.\n";
    int num_votantes;
    int intentos = 0; 
    
        cout << " Ingrese el número de votantes (al menos 1) y menor o igual a 20: ";
        cin >> num_votantes;
        if(num_votantes >= 1 && num_votantes <= 20 ) {
            cout << " Número de votantes aceptado: " << num_votantes << "\n";
              
        }
        else {
        cout << " Error: Debe ser al menos 1 y menor o igual a 20. Intente nuevamente.\n";
        
    }

    cout << "\n=== Iniciando la votación ===\n";
    cout << "Cada votante elegirá un candidato.\n"; 
    for(int i = 0; i < num_votantes; i++) {
        cout << " Turno del votante número " << i + 1 << " de " << num_votantes << ".\n";
        cout << " Aquí está la lista de candidatos:\n";
        for(int j = 0; j < 5; j++) {
            cout << j + 1 << ". " << candidatos[j] << "\n";
        }
        cout << " Ingrese el número del candidato (1-5):\n";
        int voto;
        cin >> voto;
        
    }

    
}