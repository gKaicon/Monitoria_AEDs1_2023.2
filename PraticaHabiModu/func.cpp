#include "cabec.hpp"

void formataDecimal()
{
    cout.precision(2);
    cout << fixed;
}

void calculaRelatorio()
{
    // média de salário da população
    // média de número de filhos da população
    // percentual de mulheres com salário abaixo de 1000
    // maior salário
    for (int i = 0; i < 5; i++)
    {
        somaFi += h[i].numFilho;
        somaSa += h[i].salario;
        if (((h[i].sexo == 'F') || (h[i].sexo == 'f')) && (h[i].salario > 1000))
            qtdMulher++;
        if (h[i].salario > maiorSa)
            maiorSa = h[i].salario;
    }
    mediaSa = somaSa / qtdH;
    mediaFi = somaFi / qtdH;
    percMulher = qtdMulher * 100 / qtdH;
}

void MostraRelatorio()
{
    cout << "Média de Salário da população: R$ " << mediaSa << "\n";
    cout << "Média de números de filhos da população: " << mediaFi << "\n";
    cout << "Percentual de mulheres com salário acima de R$ 1000.00:  " << percMulher << "% \n";
    cout << "Maior Salário: R$ " << maiorSa << endl;
}

void MostrarRegistros()
{
    for (int i = 0; i < qtdH; i++)
    {
        cout << "\nRegistro " << i + 1 << "° \n";
        cout << "\tSalário: R$ " << h[i].salario << endl;
        cout << "\tIdade: " << h[i].idade << endl;
        cout << "\tQuantidade de filhos: " << h[i].numFilho << endl;
        cout << "\tSexo: " << h[i].sexo << endl;
    }
}

void salvaRelatorio()
{
    escrita.open("Relatorio.txt");
    escrita << "Média de Salário da população: R$ " << mediaSa << "\n";
    escrita << "Média de números de filhos da população: " << mediaFi << "\n";
    escrita << "Percentual de mulheres com salário acima de R$ 1000.00:  " << percMulher << "% \n";
    escrita << "Maior Salário: R$ " << maiorSa << endl;
    escrita.close();
}

void salvaDados()
{
    escrita.open("ListaDados.txt");
    escrita.clear();
    for (int i = 0; i < qtdH; i++)
    {
        escrita << h[i].salario << endl;
        escrita << h[i].idade << endl;
        escrita << h[i].numFilho << endl;
        escrita << h[i].sexo << endl;
    }
    escrita.close();
}

void carregaDados()
{
    leitura.open("ListaDados.txt"); // Abre o arquivo em modo binario, ou cria se não existir
    if (leitura.fail())
    { // Se falhar
        cout << "ERROR!";
        leitura.clear(); // Fecha
    }
    while (!leitura.eof())
    {
        for (int i = 0; i < 5; i++)
        {
            leitura >> h[i].salario;
            leitura >> h[i].idade;
            leitura >> h[i].numFilho;
            leitura >> h[i].sexo;
        }
    }
    leitura.close(); // Fecha após carregado
}

void menu()
{
    system("cls");
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                   MENU                       *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*  1 - INCLUIR MANUALMENTE                     *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  2 - MOSTRAR REGISTROS                       *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  3 - INCLUIR DO CODIGO                       *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  4 - MOSTRAR ULTIMO RELATORIO                *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  5 - INCLUIR DO ARQUIVO                      *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  0 - SAIR                                    *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
    cout << "\nOpção: ";
}

void PreencheSruct()
{
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
    salvaDados();
    calculaRelatorio();
    MostraRelatorio();
    system("PAUSE");
}