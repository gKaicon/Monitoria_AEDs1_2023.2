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

    //criação por alocação dinamica do vetor
    int *vet, tamanhoVet;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanhoVet;
    vet = new int[tamanhoVet];


    for (int i = 0; i < tamanhoVet; i++)
    {
        vet[i] = rand() % 9;
        cout << vet[i] << "\t";
    }
    //criação por alocação dinamica da matriz
    int **matriz, linha, coluna;
    cout << "\nInforme o numero de linhas: ";
    cin >> linha;
    cout << "\nInforme o numero de colunas: ";
    cin >> coluna;
    // criação da matriz
    matriz = new int *[linha];
    for (int i = 0; i < linha; i++)
    {
        matriz[i] = new int[coluna];
    }
    // preenchimento da matriz
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 9;
        }
    }
    // impressão da matriz5
    cout << "\n";
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}