
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
	UINT CPAGE_UTF8 = 65001;
	UINT CPAGE_DEFAULT = GetConsoleOutputCP();
	SetConsoleOutputCP(CPAGE_UTF8);
	srand(time(NULL));

	int vet[3][3];
	int num = rand() % 10;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			num = rand() % 10;
			vet[i][j] = num;
		}
	}

	int diagSoma = 0, diag2Soma = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				diagSoma += vet[i][j]; //soma da diagonal principal
			if((i+j) == 2) 
				diag2Soma += vet[i][j]; //soma da diagonal secundaria
		}
	}

	int Linhasoma1 = 0;
	for (int j = 0; j < 3; j++)
	{
		Linhasoma1 += vet[0][j];
	}

	int Linhasoma2 = 0;
	for (int j = 0; j < 3; j++)
	{
		Linhasoma2 += vet[1][j];
	}

	int Linhasoma3 = 0;
	for (int j = 0; j < 3; j++)
	{
		Linhasoma3 += vet[2][j];
	}

	int colusoma1 = 0;
	for (int i = 0; i < 3; i++)
	{
		colusoma1 += vet[i][0];
	}

	int colusoma2 = 0;
	for (int i = 0; i < 3; i++)
	{
		colusoma2 += vet[i][1];
	}

	int colusoma3 = 0;
	for (int i = 0; i < 3; i++)
	{
		colusoma3 += vet[i][2];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << vet[i][j] << "\t";
		}
		cout << "\n";
	}

	if ((diagSoma == diag2Soma) == (Linhasoma1 == Linhasoma2 == Linhasoma3) == (colusoma1 == colusoma2 == colusoma3))
		cout << endl << "É um quadrado mágico";
	else{
		cout << endl << "Nâo um quadrado mágico";
	}
	return 0;
}