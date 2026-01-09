#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.ignore(256, '\n'); // Ignorar la primera línea

    
    string candidatos[4];

    // Iniciar el proceso de ingreso de candidatos
    cout << "=== Empezamos con el registro de candidatos ===\n";
    cout << "tenemos que registra a los 4 candidatos uno por uno.\n";

    // Bucle para ingresar datos de cada candidato
    for(int i = 0; i < 4; i++) {
        cout << "Por favor, ingrese el nombre completo del candidato numero " << i + 1 << ":\n";
        getline(cin, candidatos[i]);
        cout << "El candidato numero " << i + 1 << " es: " << candidatos[i] << "\n";
        cout << "el registro se ha completado para este candidato.\n\n";
    }

    // Iniciar la configuración de la votación
    cout << "=== Configurando la votación ===\n";
    cout << "Necesitamos saber cuantos votantes va a ver.\n";
    int num_votantes;
    int intentos = 0;
    while(intentos < 10) {
        cout << "Ingrese el numero de votantes (por lo menos 1): ";
        cin >> num_votantes;
        if(num_votantes >= 1) {
            cout << "Numero de votantes aceptado: " << num_votantes << "\n";
            cin.ignore(); // Limpiar el buffer
            break;
        }
        cout << "Error: Debe ser al menos 1. Intente otra vez.\n";
        intentos = intentos + 1;
    }

    // Inicializar contadores de votos
    int votos[4] = {0};
    int votos_nulos = 0;
    bool votacion_activa = true;

    // Empezar el proceso de votación
    cout << "\n=== Iniciando la votacion ===\n";
    cout << "Cada votante va a elegir un cadidato.\n";
    for(int i = 0; i < num_votantes && votacion_activa; i++) {
        cout << "Es el turno del votante número " << i + 1 << " de " << num_votantes << ".\n";
        cout << "Aquí está la lista de candidatos:\n";
        for(int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << candidatos[j] << "\n";
        }
        cout << "Por favor, ingrese el número del candidato (1-4):\n";
        int voto;
        cin >> voto;
        if(voto == 0) {
            cout << "Votación terminada por el usuario.\n";
            votacion_activa = false;
        } else if(voto >= 1 && voto <= 4) {
            votos[voto - 1] = votos[voto - 1] + 1;
            cout << "Voto registrado para " << candidatos[voto - 1] << ".\n";
        } else {
            votos_nulos = votos_nulos + 1;
            cout << "Se registró un voto nulo.\n";
        }
        cout << "Cantidad de votos nulos hasta ahora: " << votos_nulos << "\n\n";
        cin.ignore(); // Limpiar el buffer después de cada voto
    }

    // Mostrar los resultados finales
    cout << "\n=== Resultados de la Eleccion ===\n";
    cout << "Vamos a ver cómo quedó la votacion.\n";
    int total_votos = num_votantes;
    int total_votos_validos = total_votos - votos_nulos;
    cout << "Total de votos emitidos: " << total_votos << "\n";
    cout << "Total de votos válidos: " << total_votos_validos << "\n";
    cout << "Total de votos nulos: " << votos_nulos << "\n\n";

    // Mostrar los votos de cada candidato
    int max_votos = 0;
    int ganador = -1;
    for(int i = 0; i < 4; i++) {
        cout << "Candidato " << i + 1 << ": " << candidatos[i] << "\n";
        cout << "Votos validos recibidos: " << votos[i] << "\n";
        if(votos[i] > max_votos) {
            max_votos = votos[i];
            ganador = i;
        }
    }

    // Decidir y mostrar al ganador
    cout << "\n";
    if(max_votos > 0 && max_votos > total_votos_validos / 2) {
        cout << "El ganador es: " << candidatos[ganador] << "\n";
        cout << "Con " << max_votos << " votos validos.\n";
    } else if(max_votos > 0) {
        cout << "No hubo mayoria absoluta.\n";
        cout << "El que mas votos tuvo fue: " << candidatos[ganador] << "\n";
        cout << "Con " << max_votos << " votos válidos.\n";
    } else {
        cout << "No hubo ganador porque todos los votos fueron nulos.\n";
    }

    cout << "\nEl programa ha terminado.\n";
    return 0;
}