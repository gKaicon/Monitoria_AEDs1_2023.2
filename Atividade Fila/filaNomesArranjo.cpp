#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <fstream>
#include <string.h>

using namespace std;
using namespace chrono;

const int MAX_PEDIDOS = 100;

struct Pedido
{
    string nomeCliente;
    int numMesa;
    string desc;
};

struct Fila
{
    Pedido filaPedidos[MAX_PEDIDOS];
    int fim = -1;
};

Fila fila;

Pedido leDoTeclado();
void inserir(Pedido nome);
void remover();
void mostrar();
bool verificarSeTemAlgumaCoisa();
int menu();
void mostrarProximoPedido();
void exportar();
void importar();

int main()
{

    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    int opcao;
    Pedido p;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            p = leDoTeclado();
            inserir(p);
            break;
        case 2:
            remover();
            break;
        case 3:
            mostrar();
            break;
        case 4:
            mostrarProximoPedido();
            break;
        case 5:
            importar();
            break;
        case 6:
            exportar();
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Selecione uma opção válida!" << endl;
            break;
        }
        system("cls");
    } while (opcao != 0);

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Tempo de Execução : " << tempo.count() << " segundos " << endl;
    return 0;
}

Pedido leDoTeclado()
{
    Pedido pedidoLocal;
    cin.ignore();
    cout << "Nome do cliente: ";
    getline(cin, pedidoLocal.nomeCliente);
    cout << "Número da mesa: ";
    cin >> pedidoLocal.numMesa;
    cin.ignore();
    cout << "Descrição do pedido: ";
    getline(cin, pedidoLocal.desc);
    return pedidoLocal;
}

void inserir(Pedido pedido)
{
    if (fila.fim < MAX_PEDIDOS - 1)
    {
        fila.fim = fila.fim + 1;
        fila.filaPedidos[fila.fim] = pedido;
    }
}

void remover()
{
    if (verificarSeTemAlgumaCoisa())
    {
        cout << "Removendo:" << endl;
        cout << "Nome do cliente" << fila.filaPedidos[0].nomeCliente << endl;
        cout << "Mesa do cliente" << fila.filaPedidos[0].numMesa << endl;
        cout << "Descrição do pedido" << fila.filaPedidos[0].desc << endl;
        for (int i = 0; i < fila.fim; i++)
        {
            fila.filaPedidos[i] = fila.filaPedidos[i + 1];
        }
        fila.fim = fila.fim - 1;
        system("cls");
        cout << "Remoção concluída" << endl;
    }
}

void mostrar()
{
    cout << "++++ FILA ++++ " << endl;
    for (int i = 0; i < fila.fim; i++)
    {
        cout << "\tCliente: " << fila.filaPedidos[i].nomeCliente << endl;
        cout << "\tNúmero da mesa: " << fila.filaPedidos[i].numMesa << endl;
        cout << "\tDescrição: " << fila.filaPedidos[i].desc << endl;
        cout << "\n";
    }
    cout << "\n\n";
    system("PAUSE");
}

bool verificarSeTemAlgumaCoisa()
{
    if (fila.fim > -1)
        return true;
    return false;
}

void mostrarProximoPedido()
{
    if (verificarSeTemAlgumaCoisa())
    {
        cout << "Cliente: " << fila.filaPedidos[1].nomeCliente << "\t";
        cout << "Número da mesa: " << fila.filaPedidos[1].numMesa << "\t";
        cout << "Descrição: " << fila.filaPedidos[1].desc << "\t";
    }
}

int menu()
{
    int opcao;
    cout << "++++ Opções ++++ " << endl;
    cout << "1. Faz Pedido" << endl;
    cout << "2. Marcar pedido como concluído" << endl;
    cout << "3. Mostrar lista de pedidos completa" << endl;
    cout << "4. Mostrar o próximo pedido" << endl;
    cout << "5. Importar do arquivo" << endl;
    cout << "6. Exportar para o arquivo" << endl;
    cout << "0. Sair" << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}

void exportar()
{
    ofstream escrita;
    escrita.open("listaAtendimentos.txt");
    if (escrita.fail())
    {
        cerr << "\aErro ao abrir o arquivo.";
    }
    else
    {
        escrita << fila.fim + 1 << endl;
        for (int i = 0; i < fila.fim; i++)
        {
            escrita << fila.filaPedidos[i].nomeCliente << endl;
            escrita << fila.filaPedidos[i].numMesa << endl;
            escrita << fila.filaPedidos[i].desc << endl;
        }
        escrita.close();
        cout << "Exportação realizada com sucesso." << endl;
        Sleep(2500);
    }
}

void importar()
{
    ifstream leitura;
    leitura.open("listaAtendimentos.txt");
    if (leitura.fail())
    {
        cerr << "\aErro ao abrir o arquivo.";
    }
    else
    {
        int qtdRegistros;
        leitura >> qtdRegistros;
        if (fila.fim + qtdRegistros < MAX_PEDIDOS)
        {   
            fila.fim++;
            for (int i = fila.fim; i < (fila.fim + qtdRegistros); i++)
            {
                getline(leitura >> ::ws, fila.filaPedidos[i].nomeCliente);
                leitura >> fila.filaPedidos[i].numMesa;
                getline(leitura >> ::ws, fila.filaPedidos[i].desc);
            }
            leitura.close();
            cout << "Importação realizada com sucesso." << endl;
            fila.fim = fila.fim + qtdRegistros;
            Sleep(2500);
        }
        else{
            cout << "Importação realizada com falha." << endl;
            Sleep(2500);
        }
    }
}