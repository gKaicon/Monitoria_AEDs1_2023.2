#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <fstream>
#include <string.h>

using namespace std;
using namespace chrono;

const int MAX_LIVROS = 100;

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

ListaDeLivros lista;

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

int menu();

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    int opcao, posicao;
    Livro livro;
    do
    {
        system("cls");
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
        case 8:
            mostrarLista();
            cout << "Digite o codigo do livro que deseja editar: ";
            cin >> posicao;
            editarLivro(posicao);
            break;
        case 9:
            mostrarLista();
            int p1, p2;
            cout << "Digite os livros que deseja trocar de posição: ";
            cout << "\nPosição 1:";
            cin >> p1;
            cout << "\nPosição 2:";
            cin >> p2;
            trocaElemento(p1, p2);
            break;
        case 10:
            exportarArquivo();
        case 11:
            importarArquivo();
        case 0:
            break;
        default:
            cout << "Nenhuma das opções digitadas é válida." << endl;
            break;
        }
        system("PAUSE");
    } while (opcao != 0);
    cout << "Saindo..." << endl;
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "\nTempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
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
        cout << lista.livros[0].codigo << "\t";
        cout << lista.livros[0].nome << "\t";
        cout << lista.livros[0].autor << "\t";
        cout << lista.livros[0].anoPublicacao << "\n";
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
        cout << lista.livros[lista.quantidade - 1].codigo << "\t";
        cout << lista.livros[lista.quantidade - 1].nome << "\t";
        cout << lista.livros[lista.quantidade - 1].autor << "\t";
        cout << lista.livros[lista.quantidade - 1].anoPublicacao << "\n";
        lista.quantidade = lista.quantidade - 1;
    }
}

void removerDeUmaPosicao(int posicao)
{
    if (lista.quantidade > 0 && posicao < lista.quantidade)
    {
        cout << "Removendo ";
        cout << lista.livros[posicao].codigo << "\t";
        cout << lista.livros[posicao].nome << "\t";
        cout << lista.livros[posicao].autor << "\t";
        cout << lista.livros[posicao].anoPublicacao << "\n";
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
        cout << lista.livros[i].codigo << "\t";
        cout << lista.livros[i].nome << "\t";
        cout << lista.livros[i].autor << "\t";
        cout << lista.livros[i].anoPublicacao << "\n";
    }
    cout << endl;
}

Livro leDoTeclado()
{
    Livro livro;
    cout << "Códido: ";
    cin >> livro.codigo;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, livro.nome);
    cout << "Autor: ";
    getline(cin, livro.autor);
    cout << "Ano de publicação: ";
    cin >> livro.anoPublicacao;
    return livro;
}

void editarLivro(int codigo)
{
    if (lista.quantidade > 0)
    {
        for (int i = 0; i < lista.quantidade; i++)
        {
            if (lista.livros[i].codigo == codigo)
            {
                int opcao;
                cout << "O que deseja alterar?\n(1) - Codigo\n(2) - Nome\n(3) - Autor\n(4) - Ano de Publicação\nOpção: ";
                cin >> opcao;
                if (opcao == 1)
                {
                    cout << "Digite o novo código: ";
                    cin >> lista.livros[i].codigo;
                }
                else if (opcao == 2)
                {
                    cout << "Digite o novo nome: ";
                    getline(cin, lista.livros[i].nome);
                }
                else if (opcao == 3)
                {
                    cout << "Digite o novo autor: ";
                    getline(cin, lista.livros[i].autor);
                }
                else if (opcao == 4)
                {
                    cout << "Digite o novo ano de publicação: ";
                    cin >> lista.livros[i].anoPublicacao;
                }
            }
        }
    }
}

void trocaElemento(int posicao1, int posicao2)
{
    Livro aux;
    aux = lista.livros[posicao1];
    lista.livros[posicao1] = lista.livros[posicao2];
    lista.livros[posicao2] = aux;
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
    cout << "8 - Editar livro" << endl;
    cout << "9 - Trocar Livros de Posição" << endl;
    cout << "10 - Exportar" << endl;
    cout << "11 - Importar" << endl;
    cout << "0 - Sair." << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}

void importarArquivo()
{
    ifstream leitura;
    leitura.open("listaLivros.txt");
    if (leitura.fail()){
        cout << "Abertura do arquivo falhou.\n";
    }
    else{
        leitura >> lista.quantidade;
        for (int i = 0; i < lista.quantidade; i++){
            leitura >> lista.livros[i].codigo;    
            getline(leitura >> ::ws, lista.livros[i].nome);
            getline(leitura >> ::ws, lista.livros[i].autor);
            leitura >> lista.livros[i].anoPublicacao;
        }
        cout << "Abertura do arquivo e a importação foram um sucesso.\n";
        leitura.close();
    }
}

void exportarArquivo(){
    ofstream escrita;
    escrita.open("listaLivros.txt");
    if (!escrita.is_open())
    { // verificação se o arquivo está aberto ou não, em modo de edição
        cout << "Arquivo não aberto.\n" << endl;
    }
    else
    {
        escrita.clear();
        escrita << lista.quantidade << endl;//colocando a quantidade, para caso este seja o arquivo importado
        for (int i = 0; i < lista.quantidade; i++)
        {
            escrita << lista.livros[i].codigo << endl;
            escrita << lista.livros[i].nome << endl;
            escrita << lista.livros[i].autor << endl;
            escrita << lista.livros[i].anoPublicacao << endl;
        }
    }
    escrita.close();
}