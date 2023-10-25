#include <iostream>
#include "funcoes.cpp"

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
            ExecutaTrocaElemento();
            break;
        case 10:
            exportarArquivo();
        case 11:
            importarArquivo();
        case 0:
            cout << "Saindo...";
            Sleep(3000);
            exit(0);
        default:
            cout << "Nenhuma das opções digitadas é válida." << endl;
            break;
        }
        system("PAUSE");
    } while (opcao != 0);
    return 0;
}