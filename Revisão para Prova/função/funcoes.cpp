#include <iostream>
#include <windows.h>
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace chrono;




void soma1(int a, int b, int soma){
    soma = soma * 0;    
    soma = a + b;
    cout << soma;
}

string vemDoubleSaiString(double num); // cabeçalho da função
//quero uma função que retorne uma string, com "condição" double

int main() {
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    cout << vemDoubleSaiString(25);
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}
// corpo da função
// <tipo de retorno> [nome da função] (<parametros>){
//     /* code */
//     return <variavel de retorno do tipo especificado>
// }

string vemDoubleSaiString(double num){
    return "R$ " + to_string(num);
}