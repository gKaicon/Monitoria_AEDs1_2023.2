#include <iostream>
#include <windows.h>
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace chrono;

struct Nome
{
    char primeiro_nome[35]; // 1 byte * 35 = 35 bytes
    char ultimo_nome[35]; // 1 byte * 35 = 35 bytes
}; // Total que essa struct ocupa na memoria 70 bytes

struct Pessoa
{
    int idade; // 4 bytes
    double salario; // 8 bytes
    Nome nm; // 70 bytes
    char sx; // 1 byte
}; // Total que essa struct ocupa na memoria 83 bytes

    // BASE de quantos bytes cada tipo ocupa na memoria
    // char     --> 1 bytes
    // int      --> 4 bytes
    // float    --> 4 bytes
    // double   --> 8 bytes
    // string   --> 24 bytes

int main() {
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

 // dado que o tipo char ocupa 1 byte na memoria, o tipo int ocupa 4 bytes, 
 // e o tipo double ocupa 8 bytes,  quantos bytes a declaração do vetor 
 // abaixo ocuparia na memoria
    Pessoa p[10];

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl << endl << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}