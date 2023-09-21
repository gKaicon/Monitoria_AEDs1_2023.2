#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace chrono;

int main() {
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    ifstream leitura;
    string linha;

    leitura.open("lista.txt");
    cout << "Leitura do arquivo lista.txt" << endl;
    while (leitura >> linha)
    {
        cout << linha << endl;
    }
    leitura.clear();
    leitura.close();

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl << endl << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}