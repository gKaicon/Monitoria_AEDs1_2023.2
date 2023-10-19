#include "func.cpp"

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2); // Define a cor verde para o texto

    int op;
    do
    {
        menu();
        cin >> op;
        switch (op)
        {
        case 1:
            for (int i = 0; i < qtdH; i++)
            {
                cout << "Registro " << i + 1 << "° \n";
                cout << "Informe o salário: R$ ";
                cin >> h[i].salario;
                cout << "Informe a idade: ";
                cin >> h[i].idade;
                cout << "Informe a quantidade de filhos: ";
                cin >> h[i].numFilho;
                cout << "Informe o sexo: ";
                cin >> h[i].sexo;
            }
            calculaRelatorio();
            MostraRelatorio();
            do
            {
                cout << "Deseja salvar as informações no arquivo?\n 1 - Sim\n 2 - Não\nOpção: ";
                cin >> op;
            } while (op != 1 && op != 2);
            system("cls");
            if (op == 1)
            {
                salvaRelatorio();
                salvaDados();
                cout << "Relatório e dados Salvos";
            }
            if (op == 2)
            {
                cout << "Saindo...";
                Sleep(3500);
            }
            break;
        case 2:
            MostrarRegistros();
            system("PAUSE");
            break;
        case 3:
            PreencheSruct();
            break;
        case 4:
            MostraRelatorio();
            system("PAUSE");
            break;
        case 5:
            carregaDados();
            cout << "Inclusão realizada...";
            Sleep(3500);
            calculaRelatorio();
            MostraRelatorio();
            salvaRelatorio();
            break;
        }
    } while (op != 0);
    cout << "Saindo...";
    Sleep(3500);
    return 0;
}