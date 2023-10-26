#include <iostream>
#include <windows.h>
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace chrono;

void manipulaMatriz(int **apontadorMatriz, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++){
            (apontadorMatriz)[i][j] = (apontadorMatriz)[i][j] * 2;
        }
    }
}

int main() {
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    int qtd = 3;

    int **m1;

    //inicio da criação da matriz com alocação dinamica
    m1 = new int *[qtd];
    for (int i = 0; i < qtd; i++)   
        m1[i] = new int[qtd];
    //finalização criação da matriz com alocação dinamica

    for (int i = 0; i < qtd; i++)//preenchimento da matriz
        for (int j = 0; j < qtd; j++)
            m1[i][j] = rand()%10;  

    cout << "Matriz preenchida. " << endl; 
    for (int i = 0; i < qtd; i++){
        //impressão da matriz, após preenchida
        for (int j = 0; j < qtd; j++)
            cout << m1[i][j] << "\t";
        cout << "\n";
    }
    //manipulação da matriz
    manipulaMatriz(m1, qtd);    
    cout << "Matriz manipulada. " << endl; 
    for (int i = 0; i < qtd; i++){
        //impressão da matriz, após manipulada
        for (int j = 0; j < qtd; j++)
            cout << m1[i][j] << "\t";
        cout << "\n";
    }
 
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}