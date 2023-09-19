#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

typedef struct Habitante
{
    double salario;
    int idade;
    int numFilho;
    char sexo;
};

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    double somaSa, somaFi, mediaSa, mediaFi, maiorSa, percMulher, qtdMulher = 0;
    int qtdH = 5;
    Habitante h[qtdH];

    ofstream escrita;
    ifstream leitura;

    escrita.open("ListaDados.txt");

    for (int i = 0; i < qtdH; i++)
    {
        cout << "Registro " << i+1 << "° \n";
        cout << "Informe o salário: R$ ";
        cin >> h[i].salario;
        cout << "Informe a idade: ";
        cin >> h[i].idade;
        cout << "Informe a quantidade de filhos: ";
        cin >> h[i].numFilho;
        cout << "Informe o sexo: ";
        cin >> h[i].sexo;
    }

    h[0].salario = 990.0;
    h[0].idade = 17;
    h[0].numFilho = 0;
    h[0].sexo = 'M';

    h[1].salario = 990.0;
    h[1].idade = 19;
    h[1].numFilho = 2;
    h[1].sexo = 'F';

    h[2].salario = 2000.0;
    h[2].idade = 46;
    h[2].numFilho = 2;
    h[2].sexo = 'F';

    h[3].salario = 200.0;
    h[3].idade = 18;
    h[3].numFilho = 1;
    h[3].sexo = 'F';

    h[4].salario = 990.0;
    h[4].idade = 19;
    h[4].numFilho = 4;
    h[4].sexo = 'M';

    h[5].salario = 1990.0;
    h[5].idade = 24;
    h[5].numFilho = 2;
    h[5].sexo = 'M';

    // média de salário da população
    // média de número de filhos da população
    // percentual de mulheres com salário abaixo de 1000
    // maior salário
    for (int i = 0; i < qtdH; i++)
    {
        somaFi += h[i].numFilho;
        somaSa += h[i].salario;
        if (((h[i].sexo == 'F') || (h[i].sexo == 'f')) && (h[i].salario <= 1000))
            qtdMulher++;
        if (h[i].salario > maiorSa)
            maiorSa = h[i].salario;
    }
    mediaSa = somaSa / qtdH;
    mediaFi = somaFi / qtdH;
    percMulher = qtdMulher * 100 / qtdH;

    //impressão
    system("cls");    
    for (int i = 0; i < qtdH; i++)
    {
        cout << "\nRegistro " << i + 1 << "° \n";
        cout << "\tSalário: R$ " << h[i].salario << endl;
        cout << "\tIdade: " << h[i].idade << endl;
        cout << "\tQuantidade de filhos: " << h[i].numFilho << endl;
        cout << "\tSexo: " << h[i].sexo << endl;
    }
    cout << "Média de Salário da população: R$ " << mediaSa << "\n";
    cout << "Média de números de filhos da população: " << mediaFi << "\n";
    cout << "Percentual de mulheres com salário abaixo de R$ 1000.00:  " << percMulher << "% \n";
    cout << "Maior Salário: R$ " << maiorSa << endl;
    return 0;
}