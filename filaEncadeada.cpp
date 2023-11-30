#include <iostream>
#include <string>

using namespace std;

struct Item
{
    int idade;
    string nome;
    Item *proximo;
};

struct Lista
{
    Item *primeiro = NULL;
    Item *ultimo = NULL;
};
Lista *L = NULL;

void criarLista()
{
    L->primeiro = new Item;
    L->ultimo = L->primeiro;
    L->primeiro->proximo = NULL;
}
int vazia()
{
    return (L->primeiro == L->ultimo);
}

void inserirUltima()
{
    Item *x = new Item;

    cout << "Digite um nome: ";
    cin >> x->nome;
    cout << "Digite a idade: ";
    cin >> x->idade;

    L->ultimo->proximo = x;
    L->ultimo = x;
    L->ultimo->proximo = NULL;
}
void mostrar()
{
    Item *aux;
    aux = L->primeiro->proximo;
    while (aux != NULL)
    {
        cout << "Nome: " << aux->nome << " "
             << "Idade: " << aux->idade << endl;
        aux = aux->proximo;
    }
}


void removerPrimeira()
{
    if (!vazia())
    {
        Item *aux = L->primeiro->proximo;
        cout << endl
             << "+++ REMOVENDO +++" << endl;
        cout << aux->nome << " " << aux->idade << endl
             << endl;
        L->primeiro->proximo = aux->proximo;
        if (aux == L->ultimo)//if usado para tratar caso a lista tenha 1 item
        {
            L->ultimo = L->primeiro;
        }
        delete aux;
    }
    else
    {
        cout << endl
             << "Vazia" << endl;
    }
}


int menu()
{
    int opcao;
    cout << "++++ Opcoes ++++ " << endl;
    cout << "1. Inserir no final" << endl;
    cout << "2. Mostrar" << endl;
    cout << "3. Remover primeira" << endl;
    cout << "0. Sair" << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}

int main()
{
    int opcao, p;
    L = new Lista;
    criarLista();
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            inserirUltima();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            removerPrimeira();
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