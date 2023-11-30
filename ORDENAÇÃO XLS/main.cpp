#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>

using namespace std;

typedef struct Funcinario{
  string nome;
  char situacao;
};


int main(){
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  srand(time(NULL));
  system("cls");

  ifstream leitura;
  leitura.open("arquiv.xls");
  Funcinario listaF[158];
  
  for(int i = 0; i < 158; i++){
    leitura >> listaF[i].situacao;
    getline(leitura >> ::ws, listaF[i].nome);
  }
  for (int i = 0; i < 20; i++)
  {
    cout << "Nome: " << listaF[i].nome;
    cout << "Situação: " << listaF[i].situacao;
  }
  

  leitura.close();
  return 0;
}