#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

const int MAX_LIVROS = 100;

struct Livro
{
    int codigo;
    string nome;
    //autor
    //ano de publicação
};

struct ListaDeLivros
{
    int quantidade = 0;
    Livro livros[MAX_LIVROS];
};

ListaDeLivros lista;

void inserirInicio(Livro li);
void inserirFim(Livro li);
void inserirEmUmaPosicao(Livro li, int posicao);

void removerInicio();
void removerFim();
void removerDeUmaPosicao(int posicao);

void mostrarLista();

Livro leDoTeclado();

int menu();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    int opcao, posicao;
    Livro livro;
    do
    {
        switch (menu())
        {
        case 1:
            livro = leDoTeclado();
            inserirInicio(livro);
            break;
        case 2:
            livro = leDoTeclado();
            cout << "Em qual posicao? ";
            cin >> posicao;
            inserirEmUmaPosicao(livro, posicao);
            break;
        case 3:
            livro = leDoTeclado();
            inserirFim(livro);
            break;
        case 4:
            removerInicio();
            break;
        case 5:
            cout << "Em qual posicao? ";
            cin >> posicao;
            removerDeUmaPosicao(posicao);
            break;
        case 6:
            removerFim();
            break;
        case 7:
            mostrarLista();
            break;
        }
    } while (opcao != 0);
    cout << "Saindo..." << endl;
}

void inserirInicio(Livro li)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        for (int i = lista.quantidade; i > 0; i--)
        {
            lista.livros[i] = lista.livros[i - 1];
        }
        lista.livros[0] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}
void inserirFim(Livro li)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        lista.livros[lista.quantidade] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}
void inserirEmUmaPosicao(Livro li, int posicao)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        for (int i = lista.quantidade; i > posicao; i--)
        {
            lista.livros[i] = lista.livros[i - 1];
        }
        lista.livros[posicao] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}

void removerInicio()
{
    if (lista.quantidade > 0)
    {
        cout << "Removendo ";
        cout << lista.livros[0].codigo << ' ';
        cout << lista.livros[0].nome << endl;
        for (int i = 0; i < lista.quantidade; i++)
        {
            lista.livros[i] = lista.livros[i + 1];
        }
        lista.quantidade = lista.quantidade - 1;
    }
}
void removerFim()
{
    if (lista.quantidade > 0)
    {
        cout << "Removendo ";
        cout << lista.livros[lista.quantidade - 1].codigo << ' ';
        cout << lista.livros[lista.quantidade - 1].nome << endl;
        lista.quantidade = lista.quantidade - 1;
    }
}
void removerDeUmaPosicao(int posicao)
{
    if (lista.quantidade > 0 && posicao < lista.quantidade)
    {
        cout << "Removendo ";
        cout << lista.livros[posicao].codigo << ' ';
        cout << lista.livros[posicao].nome << endl;
        for (int i = posicao; i < lista.quantidade; i++)
        {
            lista.livros[i] = lista.livros[i + 1];
        }
        lista.quantidade = lista.quantidade - 1;
    }
}

void mostrarLista()
{
    cout << endl;
    cout << "++++++ CONTEÚDO DA LISTA ++++++ " << endl;
    for (int i = 0; i < lista.quantidade; i++)
    {
        cout << lista.livros[i].codigo << ' ';
        cout << lista.livros[i].nome << endl;
        //autor
        //ano de publicação
    }
    cout << endl;
}

Livro leDoTeclado()
{
    Livro livro;
    cout << "Códido: ";
    cin >> livro.codigo;
    cout << "Nome: ";
    cin >> livro.nome;
    //autor
    //ano de publicação
    return livro;
}

int menu()
{
    int opcao;
    cout << "+++++ OPERAÇÕES +++++ " << endl;
    cout << "1 - Inserir no início." << endl;
    cout << "2 - Inserir em uma posição." << endl;
    cout << "3 - Inserir no final." << endl;
    cout << "4 - Remover no início." << endl;
    cout << "5 - Remover em uma posição." << endl;
    cout << "6 - Remover no final." << endl;
    cout << "7 - Mostrar lista." << endl;
    // adicionar o editar
    // trocar elemento
    // exportar e importar em txt
    cout << "0 - Sair." << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}