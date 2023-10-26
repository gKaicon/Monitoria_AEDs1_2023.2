#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    int *v, n = 3;
    v = &n;
    cout << "Conteudo de v: " << *v << endl;
    cout << "Endereço de v: " << v << endl;
    cout << "Conteudo de n: " << n << endl;
    cout << "Endereço de n: " << &n << endl;

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}