#ifndef LISTA_ARRANJO_H
#define LISTA_ARRANJO_H

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <fstream>
#include <string.h>

const int MAX_LIVROS = 100;

using namespace std;
using namespace chrono;

struct Livro
{
    int codigo;
    string nome;
    string autor;
    int anoPublicacao;
};

struct ListaDeLivros
{
    int quantidade = 0;
    Livro livros[MAX_LIVROS];
};

void inserirInicio(Livro li);
void inserirFim(Livro li);
void inserirEmUmaPosicao(Livro li, int posicao);

void removerInicio();
void removerFim();
void removerDeUmaPosicao(int posicao);

void editarLivro(int codigo);
void trocaElemento(int posicao1, int posicao2);

void mostrarLista();

Livro leDoTeclado();

void importarArquivo();
void exportarArquivo();

void ExecutaTrocaElemento();

int menu();

#endif