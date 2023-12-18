#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

struct nadador
{
    int cod;
    double tempoGasto;
};

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2);
    srand(time(NULL));

    // questão 3
    nadador n[10];
    ifstream leitura;
    leitura.open("entrada.txt");
    if (leitura.fail())
    { // Se falhar
        cout << "ERROR!";
        leitura.clear(); // Fecha
    }
    while (!leitura.eof())
    {
        for (int i = 0; i < 10; i++)
        {
            leitura >> n[i].cod >> n[i].tempoGasto;
        }
    }
    leitura.close();
    cout << "Dados lidos" << endl;
    int codmenor = n[0].cod, menor = n[0].tempoGasto;
    for (int i = 0; i < 10; i++)
    {
        cout << n[i].cod << " " << n[i].tempoGasto << endl;
        if(n[i].tempoGasto < menor){
            codmenor = n[i].cod;
        }
    }
    cout << "O nadador de código: " << codmenor << " gastou menos tempo" << endl;

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Tempo de Execução:" << setprecision(2) << tempo.count() << " segundos" << endl;
    // system("taskkill /f /im cmd.exe");
    return 0;
}