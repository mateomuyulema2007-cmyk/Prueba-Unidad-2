#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <algorithm>
using namespace std;

struct HistorialAhorcado {
    string palabra;
    bool gano;
    int intentosRestantes;
    int puntos;
};

class Evaluacion {
private:
    float funcionalidad, defensa, estructura, innovacion;
public:
    Evaluacion() : funcionalidad(0), defensa(0), estructura(0), innovacion(0) {}
    
    bool setNotas(float f, float d, float e, float i) {
        if (f+d+e > 10.0) return false; 
        funcionalidad = f; defensa = d; estructura = e; innovacion = i;
        return true;
    }
    float getSumaBase() const { return funcionalidad + defensa + estructura; }
    float getInnovacion() const { return innovacion; }
    float menorCriterio() const { return min({funcionalidad, defensa, estructura, innovacion}); }
};

class GrupoProyecto {
private:
    string codigo, tema, integrantes, observaciones;
    int avance, retrasos;
    float notaFinal;
    Evaluacion eval;

public:
    GrupoProyecto() : codigo(""), tema(""), integrantes(""), observaciones(""), avance(0), retrasos(0), notaFinal(0) {}

    void registrar(string c, string t, string inst, int av, int ret, string obs) {
        codigo = c; tema = t; integrantes = inst; avance = av; retrasos = ret; observaciones = obs;
    }

    void setEvaluacion(Evaluacion e) { 
        eval = e; 
        notaFinal = eval.getSumaBase() + eval.getInnovacion() - (retrasos * 0.5f);
        if (notaFinal > 10) notaFinal = 10;
        if (notaFinal < 0) notaFinal = 0;
    }

    string getCodigo() const { return codigo; }
    string getTema() const { return tema; }
    float getNota() const { return notaFinal; }
    string getObs() const { return observaciones; }
    float getMenorCriterio() const { return eval.menorCriterio(); }

    void mostrarFila() {
        cout << codigo << "\t" << avance << "%\t" << notaFinal << "\t" << tema << endl;
    }
};

int validarEntero(string msg) {
    int v;
    while (true) {
        cout << msg;
        if (cin >> v) return v;
        cout << "Entrada invalida.\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float calcularPromedioRecursivo(GrupoProyecto grupos[], int n) {
    if (n <= 0) return 0;
    if (n == 1) return grupos[0].getNota();
    return (grupos[n-1].getNota() + (n-1) * calcularPromedioRecursivo(grupos, n-1)) / n;
}

void ordenarManual(GrupoProyecto arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j].getNota() < arr[j+1].getNota() || 
              (arr[j].getNota() == arr[j+1].getNota() && arr[j].getObs().length() > arr[j+1].getObs().length())) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void buscarGrupo(GrupoProyecto grupos[], int cant) {
    string clave;
    cout << "Buscar por codigo o tema: "; cin.ignore(); getline(cin, clave);
    for(int i=0; i<cant; i++) {
        if(grupos[i].getCodigo() == clave || grupos[i].getTema() == clave) {
            cout << "Encontrado -> "; grupos[i].mostrarFila();
        }
    }
}

class ModuloAhorcado {
private:
    vector<HistorialAhorcado> historial;
    string facil[3] = {"GRUPO", "AVANCE", "TEMA"};
    string dificil[3] = {"INNOVACION", "PENALIZACION", "ESTADISTICAS"};
    int puntajeTotal = 0;

public:
    void mostrarMenu() {
        int op;
        do {
            system("cls");
            cout << "--- AHORCADO: GESTION DE PROYECTOS ---\n";
            cout << "1. Jugar (CPU)\n2. Ver Historial\n3. Ver Puntaje Total\n4. Volver\nOpcion: ";
            op = validarEntero("");
            if (op == 1) iniciarJuego();
            if (op == 2) verHistorial();
            if (op == 3) cout << "Puntaje acumulado: " << puntajeTotal << endl;
            if (op != 4) system("pause");
        } while (op != 4);
    }

    void iniciarJuego() {
        int nivel = validarEntero("Nivel (1. Facil, 2. Dificil): ");
        srand(time(0));
        string secreta = (nivel == 1) ? facil[rand()%3] : dificil[rand()%3];
        string progreso(secreta.length(), '_');
        int intentos = 6;
        string usadas = "";

        while (intentos > 0 && progreso != secreta) {
            system("cls");
            cout << "Nivel: " << ((nivel==1)?"Facil":"Dificil") << " | Intentos: " << intentos << endl;
            cout << "Palabra: " << progreso << "\nLetras usadas: " << usadas << endl;
            cout << "Ingrese letra: "; 
            char letra; cin >> letra; letra = toupper(letra);

            if (!isalpha(letra) || usadas.find(letra) != string::npos) {
                cout << "Invalido o repetido.\n"; system("pause"); continue;
            }
            usadas += letra;

            if (secreta.find(letra) != string::npos) {
                for(int i=0; i<secreta.length(); i++) if(secreta[i]==letra) progreso[i]=letra;
            } else {
                intentos--;
                cout << "¡Incorrecto!\n";
            }
        }
        
        bool gano = (progreso == secreta);
        int puntos = gano ? intentos*10 : 0;
        puntajeTotal += puntos;
        cout << (gano ? "¡GANASTE!" : "PERDISTE") << ". La palabra era: " << secreta << " | Puntos: " << puntos << endl;
        historial.push_back({secreta, gano, intentos, puntos});
    }

    void verHistorial() {
        cout << "\n--- RESUMEN DE PARTIDAS ---\n";
        for(auto const& h : historial) {
            cout << "Palabra: " << h.palabra << " | Resultado: " << (h.gano?"Gano":"Perdio") 
                 << " | Puntos: " << h.puntos << endl;
        }
    }
};

int main() {
    GrupoProyecto grupos[50];
    ModuloAhorcado juego;
    int cant = 0, op;

    do {
        system("cls");
        cout << "=== MENU ===\n";
        cout << "1. Registrar Grupo y Evaluacion\n2. Reporte (Ordenado por Nota)\n";
        cout << "3. Estadisticas (Promedio Recursivo)\n4. Buscar Grupo\n5. Criterio de menor desempeño\n";
        cout << "6. Modulo Ahorcado\n7. Salir\nOpcion: ";
        op = validarEntero("");

        if (op == 1) {
            string c, t, inst, obs; int av, ret;
            cout << "Cod: "; cin >> c; 
            cout << "Integrantes: "; cin.ignore(); getline(cin, inst);
            cout << "Tema: "; getline(cin, t);
            av = validarEntero("% Avance: ");
            ret = validarEntero("Retrasos: ");
            cout << "Observaciones: "; cin.ignore(); getline(cin, obs);
            
            grupos[cant].registrar(c, t, inst, av, ret, obs);

            Evaluacion e;
            float f, d, est, inn;
            cout << "Notas -> Funcionalidad: "; cin >> f;
            cout << "Defensa: "; cin >> d;
            cout << "Estructura:";
                        cout << "Estructura: "; cin >> est;
            cout << "Innovacion (Bono 0-2): "; cin >> inn;
            
            if(e.setNotas(f, d, est, inn)) {
                grupos[cant].setEvaluacion(e);
                cant++;
                cout << "Registro exitoso.\n";
            } else cout << "Error: Suma base supera 10.\n";
            system("pause");
        }
        else if (op == 2) {
            ordenarManual(grupos, cant);
            cout << "COD\tAVANCE\tNOTA\tTEMA\n";
            for(int i=0; i<cant; i++) grupos[i].mostrarFila();
            system("pause");
        }
        else if (op == 3) {
            if(cant > 0) cout << "Promedio General (Recursivo): " << calcularPromedioRecursivo(grupos, cant) << endl;
            else cout << "No hay grupos registrados.\n";
            system("pause");
        }
        else if (op == 4) {
            buscarGrupo(grupos, cant);
            system("pause");
        }
        else if (op == 5) {
            if(cant > 0) {
                float menor = grupos[0].getMenorCriterio();
                for(int i=1; i<cant; i++) {
                    menor = min(menor, grupos[i].getMenorCriterio());
                }
                cout << "El criterio de menor desempeño entre todos los grupos fue: " << menor << endl;
            } else {
                cout << "No hay grupos registrados.\n";
            }
            system("pause");
        }
        else if (op == 6) {
            juego.mostrarMenu();
        }
    } while (op != 7);

    return 0;
}

