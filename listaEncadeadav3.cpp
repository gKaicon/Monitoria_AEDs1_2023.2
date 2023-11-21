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

void inserirPrimeira()
{
    Item *x = new Item;

    cout << "Digite um nome: ";
    cin >> x->nome;
    cout << "Digite a idade: ";
    cin >> x->idade;

    if (!vazia())
    {
        x->proximo = L->primeiro->proximo;
        L->primeiro->proximo = x;
    }
    else
    {
        L->ultimo->proximo = x;
        L->ultimo = x;
        L->ultimo->proximo = NULL;
    }
}
void inserirPosicao(int n)
{
    int i = 0;
    Item *aux = L->primeiro;
    while (i < (n - 1) && aux != NULL)
    {
        i++;
        aux = aux->proximo;
    }

    Item *x = new Item;
    cout << "Digite um nome: ";
    cin >> x->nome;
    cout << "Digite a idade: ";
    cin >> x->idade;

    x->proximo = aux->proximo;
    aux->proximo = x;
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

void removerUltima()
{
    if (!vazia())
    {
        Item *aux = L->primeiro;
        while (aux->proximo != L->ultimo)
        {
            aux = aux->proximo;
        }
        cout << endl
             << "+++ REMOVENDO +++" << endl;
        cout << aux->proximo->nome << " " << aux->proximo->idade << endl
             << endl;
        aux->proximo = NULL;
        delete L->ultimo;
        L->ultimo = aux;
    }
    else
    {
        cout << endl
             << "Vazia" << endl;
    }
}

void removerPosicao(int posicao)
{
    if (!vazia())
    {
        int i = 1;
        Item *aux1 = L->primeiro, *aux2 = L->primeiro->proximo;
        while (i < posicao && aux2 != NULL)
        {
            i++;
            aux1 = aux2;
            aux2 = aux2->proximo;
        }
        if (aux2 == NULL)
        {
            cout << "Nada para remover" << endl;
        }
        else
        {
            cout << endl
                 << "+++ REMOVENDO +++" << endl;
            cout << aux2->nome << " " << aux2->idade << endl
                 << endl;
            if (aux2 == L->ultimo)
            {
                L->ultimo = aux1;
            }
            aux1->proximo = aux2->proximo;
            delete aux2;
        }
    }
}

int menu()
{
    int opcao;
    cout << "++++ Opcoes ++++ " << endl;
    cout << "1. Inserir no inicio" << endl;
    cout << "2. Inserir no final" << endl;
    cout << "3. Inserir em uma posicao" << endl;
    cout << "4. Mostrar" << endl;
    cout << "5. Remover primeira" << endl;
    cout << "6. Remover ultima" << endl;
    cout << "7. Remover de uma posicao" << endl;

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
            inserirPrimeira();
            break;
        case 2:
            inserirUltima();
            break;
        case 3:
            cout << "Digite a posicao: ";
            cin >> p;
            inserirPosicao(p);
            break;
        case 4:
            mostrar();
            break;
        case 5:
            removerPrimeira();
            break;
        case 6:
            removerUltima();
            break;
        case 7:
            cout << "Digite a posicao: ";
            cin >> p;
            removerPosicao(p);
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