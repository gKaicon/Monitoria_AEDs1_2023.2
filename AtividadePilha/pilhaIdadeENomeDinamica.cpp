#include <iostream>
#include <string>

using namespace std;

struct Item
{
    int idade; //variavel qualquer do tipo int
    string nome; //variavel qualquer tipo string
    Item *proximo; //ponteiro do tipo Item, para apontar para uma variavel do tipo item
};

Item *topo = NULL; //alocação dinamica de uma Pilha

//cabeçalho das funções
void empilhar();
void desempilhar();
bool verificarSeTemAlgumaCoisa();
void mostrar();
int menu();

int main()
{
    int opcao;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            empilhar();
            break;
        case 2:
            desempilhar();
            break;
        case 3:
            mostrar();
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Selecione uma opção válida!" << endl;
            break;
        }
    } while (opcao != 0);
    return 0;
}

void empilhar()
{
    Item *temp = new Item;
    cout << "Nome: ";
    cin >> temp->nome;
    cout << "Idade: ";
    cin >> temp->idade;

    temp->proximo = topo;
    topo = temp;
    temp = NULL;
}

void desempilhar()
{
    if (verificarSeTemAlgumaCoisa())
    {
        Item *temp = topo;
        topo = topo->proximo;
        cout << "Removido: ";
        cout << temp->nome << " " << temp->idade << endl;
        delete temp;
    }
    else
    {
        cout << "Nada!" << endl;
    }
}

bool verificarSeTemAlgumaCoisa()
{
    if (topo != NULL)
    {
        return true;
    }
    return false;
}
void mostrar()
{
    Item *temp = topo;
    while (temp != NULL)
    {
        cout << temp->nome << " " << temp->idade << endl;
        temp = temp->proximo;
    }
}
int menu()
{
    int opcao;
    cout << "++++ Opções ++++ " << endl;
    cout << "1. Inserir" << endl;
    cout << "2. Remover" << endl;
    cout << "3. Mostrar" << endl;
    cout << "0. Sair" << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}