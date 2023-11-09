#ifndef PRATICA_HABITANTES
#define PRATICA_HABITANTES

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

struct Habitante
{
    double salario;
    int idade;
    int numFilho;
    char sexo;
};

const int qtdH = 5;
Habitante h[qtdH];
double somaSa, somaFi, mediaSa, mediaFi, maiorSa, percMulher, qtdMulher = 0;
ofstream escrita;
ifstream leitura;

void formataDecimal();
void calculaRelatorio();
void MostraRelatorio();
void MostrarRegistros();
void salvaRelatorio();
void salvaDados();
void carregaDados();
void menu();
void PreencheSruct();

#endif