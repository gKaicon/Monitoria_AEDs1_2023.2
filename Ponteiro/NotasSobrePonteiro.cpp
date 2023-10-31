#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    // Notas sobre ponteiro
    // sendo *v = um ponteiro de um inteiro, e n um inteiro, temos que:
    // *v => "*", quando na declaração, significa a criação de um ponteiro
    // *v => "*", quando na atribuição, significa o conteudo de um ponteiro
    //  * => pode ser uma multiplicação. (cuidado ao fazer multiplicação do conteudo de um ponteiro, por um valor qualquer)
    //  & => quando, antes de uma variavel qualquer(porém condizente com o o tipo dela), 
    //       é o mesmo que acesso ao endereço de memoria dela.
    // && => significa operador "and/e" dentro de condições

    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    int *v, n; //declaração
    //atribuição
    n = 3;
    v = &n;
    //impressão
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