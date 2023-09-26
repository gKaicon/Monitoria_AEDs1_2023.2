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

    int vet[5] = {4, 10, 5, 9, 2};
    int m1[3][3] = {{0, 4, 2}, {1, 3, 5}, {7, 9, 19}};

    // PARTE DE VETOR
    //  para percorrer um vetor usa-se apenas 1 for
    for (int i = 0; i < 5; i++)
    {
        cout << vet[i] << "\t";
    }
    cout << endl;
    // para imprimir o vetor inverso
    for (int i = 5; i > -1; i--)
    {
        cout << vet[i] << "\t";
    }
    cout << "\n";
    // valores pares do meu vetor
    for (int i = 0; i < 5; i++)
    {
        if (vet[i] % 2 == 0)
            cout << vet[i] << "\t";
    }
    cout << "\n";
    // valores ímpares do meu vetor
    for (int i = 0; i < 5; i++)
    {
        if (vet[i] % 2 != 0)
            cout << vet[i] << "\t";
    }
    cout << "\n";

    // PARTE DE MATRIZ
    //  para percorrer uma matriz usa-se 2 for's
    cout << "\n\nMatriz\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m1[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n\nDiagonal principal\n";
    // para achar a diagonal principal e para achar a diagonal secundária
    for (int i = 0; i < 3; i++) // diag Principal
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                cout << m1[i][j] << "\t";
        }
    }
    cout << "\n\nDiagonal secundaria\n";
    for (int i = 0; i < 3; i++) // diag Secundaria
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i + j) == (3 - 1))
                cout << m1[i][j] << "\t";
        }
    }
    cout << "\n\n";
    // achar a transposta de uma matriz, é fazer com que a linha da matriz
    // original se torne a coluna da nova matriz, que seria a tranposta
    // (em miudos seria imprimir a matriz em forma de coluna e não em forma de linha)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m1[j][i] << "\t";
        }
        cout << "\n";
    }
    cout << "\n\n";
    // atenção na transposta de matrizes que não são quadraticas
    int m2[3][2] = {{0, 4}, {1, 3}, {7, 9}};
    //matriz normal
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << m2[i][j] << "\t";
        }
        cout << "\n";
    }
    //matriz transposta
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m2[j][i] << "\t";
        }
        cout << "\n";
    }
    // para imprimir a matriz de trás para frente é o mesmo esquema do vetor,
    // assim como imprimir os valores pares e valores impares
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}