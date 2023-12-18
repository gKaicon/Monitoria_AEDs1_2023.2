#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

// questão 7

struct Estudante
{
    string ra;
    string nome[128];
    string cpf[14];
    Estudante *proximo;
};

Estudante *inicio, fim;

void ListarEdudantes()
{
    Estudante *aux;
    aux = inicio;
    while (aux != NULL)
    {
        cout << "RA: " << aux->ra << "\tCPF: " << aux->cpf << "\tNome: " << aux->nome;
        aux = aux->proximo;
    }
    cout << "Todos os registro foram exibidos";
}

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2);
    srand(time(NULL));

    // questão 1, letra a
    Estudante *e;
    e = new Estudante[1];
    Estudante *e;
    e = new Estudante;
    // questão 1, letra b
    Estudante *e;
    int tamanho;
    cout << "Informe o tamanho do vetor: ";
    cin >> tamanho;
    e = new Estudante[tamanho];

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Tempo de Execução:" << setprecision(2) << tempo.count() << " segundos" << endl;
    // system("taskkill /f /im cmd.exe");
    return 0;
}