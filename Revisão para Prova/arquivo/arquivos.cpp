#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    /*
    ifstream e ofstream são partes da biblioteca fstream, são utilizados para
    realizar manipulação de arquivos. O ifstream seria para acessar o arquivo
    em modo de leitura, para o programa escrito em c++. O ofstream seria para
    acessar o arquivo em modo de escrita para o programa escrito em c++.
    */
    ofstream escrita;
    ifstream leitura;
    /*
       Usarei o ifstream para ler do arquivo assim como eu leria no programa,
       logo uso ">>".
       Ex: Sendo num, um varivel inteira, farei dela no arquivo da seguinte forma
       leitura >> num; para ler dum arquivo e armazenar nessa variavel um valor lido
       sem usar algo como o "cin >> num" no programa;
    */
    // escrita, se basea em abrir um arquivo, edita-lo, salva-lo e fecha-lo
    escrita.open("teste.txt"); // abrir o arquivo
    int num;
    cout << "Digite um numero";
    cin >> num;
    // edição/armazenação(salvar)
    escrita << num << endl;
    escrita << "Joao" << endl;
    escrita << "Gabriel" << endl;
    escrita << "Brunna" << endl;
    escrita << "Julya" << endl;
    escrita.close(); // fechamento

    /*
       Usarei o ofstream para "tirar" do programa, e irei escrever no arquivo, logo uso "<<".
       Ex: Sendo num, um varivel inteira, farei uma atribuição dele no programa, tipo
       num = 6; e logo em seguida irei escrever esse valor no arquivo, da seguinte forma:
       escrita << num;
    */
    // leitura, se baseia em abrir um arquivo existente, lê-lo, e fecha-lo
    leitura.open("teste.txt"); // abro em forma de leitura
    string palavra;            // varivel que vai receber cada palavra do arquivo para exibi-la na tela
    // leitura e exibição
    cout << "\nPrimeira impresão, a forma extendida\n";
    leitura >> palavra;
    cout << palavra << endl;
    leitura >> palavra;
    cout << palavra << endl;
    leitura >> palavra;
    cout << palavra << endl;
    leitura >> palavra;
    cout << palavra << endl;
    leitura >> palavra;
    cout << palavra << endl;
    cout << "\nSegunda impresão, a forma resumida\n";
    do
    {
        leitura >> palavra;
        cout << palavra << endl;
    } while (!leitura.eof());
    leitura.close(); // fechamento

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}