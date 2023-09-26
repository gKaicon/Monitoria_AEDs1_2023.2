#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

struct Nome
{
    char primeiro_nome[35];
    char ultimo_nome[35];
};

struct Pessoa
{
    int idade;
    double salario;
    Nome nm;
    char sx;
};

// Uma struct pode ser entendida como um "tipão"
// que armazena vários tipos

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    Pessoa p;

    // abaixo tem que prestar a atenção em como você vai acessar e atribuir
    // valores para os tipos, sejam eles, tipos do próprio C++, ou tipos que você
    // criou em forma de struct
    cout << "Digite o primeiro nome da pessoa: ";
    cin.getline(p.nm.primeiro_nome, 35); // primeiro_nome é uma variavel da struct nome, 
                                         // nm é a variavel que usamos para acessa-la na struct pessoa
    cout << "Digite o(s) sobrenome(s) da pessoa: ";
    cin.getline(p.nm.ultimo_nome, 35);
    // abaixo as atribuições serão feitas de forma "simples"
    cout <<  "Digite a idade da pessoa: ";
    cin >> p.idade;
    cout <<  "Digite o salario da pessoa:";
    cin >> p.salario;
    cout <<  "Digite o sexo da pessoa: ";
    cin >> p.sx;
    cout << "Informações da pessoa cadastrada" << endl;
    cout << "Nome: " << p.nm.primeiro_nome << " " << p.nm.ultimo_nome << endl; 
    cout << "Idade: " << p.idade << endl;
    cout << "Salário: " << p.salario << endl;
    cout << "Sexo: " << p.sx << endl;

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}
