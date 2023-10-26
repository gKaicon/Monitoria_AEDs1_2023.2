#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

int **criarMatriz(int linhas, int colunas)
{
    int **matriz;
    matriz = new int *[linhas];
    for (int i = 0; i < colunas; i++)
        matriz[i] = new int[colunas];
    return matriz;
}

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    int **matriz = criarMatriz(3, 2);
    for (int i = 0; i < 3; i++)
    {
        // preenchimento da matriz
        for (int j = 0; j < 2; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        // preenchimento da matriz
        for (int j = 0; j < 2; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Tempo de Execução : " << tempo.count() << " segundos " << endl;
    return 0;
}
