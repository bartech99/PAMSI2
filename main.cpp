#include "Basis.h"
#include "File.h"
#include "List.h"
#include "Matrix.h"
#include "Support.h"
#include "Test.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	Matrix* m; //wskaznik na obiekt macierzy
	List* l; //wskaznik na obiekt listy
	Test* testL; //obsluga pomiaru czasu list
	Test* testM; //obsluga pomiaru czasu macierzy
	File* file = new File();
	File* file2;

	int Vs[5] = { 30, 50, 100, 200, 300 }; //tablica ilosci wierzcholkow
	int Ds[4] = { 25, 50, 75, 100 }; //tablica gestosci
	int V; //ilosc wierzcholkow
	int E; //ilosc krawedzi
	int D; //gestosc
	int V0; //wezel startowy

	srand(static_cast<unsigned int>(time(NULL)));

	switch (Menu())
	{
	case 1:

		cout << "Generowanie grafow..." << endl;
		file->Make();
		delete file;
		break;

	case 2: //wagi i polaczenia losowe, gestosc i ilosc wierzcholkow wg tablicy

		for (int iV = 0; iV < 5; iV++)
		{
			V = Vs[iV];
			cout << iV + 1 << ". Ilosc wierzcholkow: " << V << endl << endl;

			file->Open(V, 't');

			for (int iD = 0; iD < 4; iD++)
			{
				D = Ds[iD];
				E = CalcEdges(V, D);
				V0 = Random(1, V);
				cout << "\t" << iD + 1 << ") Gestosc: " << D << "%" << endl;
				testM = new Test(100);
				testL = new Test(100);
				for (int i = 0; i < 100; i++)
				{
					m = new Matrix(V, E, V0);
					l = new List(V, E, V0);

					Fill(V, E, m, l);

					testM->Begin();
					m->BF();
					testM->End(i);

					testL->Begin();
					l->BF();
					testL->End(i);

					delete m;
					delete l;
				}
				testM->CalcAverage();
				testM->Display('m');
				testL->CalcAverage();
				testL->Display('l');
				cout << endl;

				file->WriteTimes(D, testM->Average(), testL->Average());

				delete testL;
				delete testM;
			}
			file->Close();
		}
		delete file;
		break;

	case 3: //z pliku

		int j = 0;
		file2 = new File();
		Test* test = new Test(1);
		double tM, tL;

		while (file->Open(j + 1, 'i'))
		{
			j++;
			if (file->ReadBegin(E, V, V0))
			{
				m = new Matrix(V, E, V0);
				l = new List(V, E, V0);

				for (int i = 0; i < E; i++)
				{
					if (!file->Read(l, m))
					{
						cout << "Zbyt mala ilosc krawedzi w pliku nr: " << j << ".txt." << endl;
						return 0;
					}
				}

				test->Begin();
				m->BF();
				tM = test->End();

				test->Begin();
				l->BF();
				tL = test->End();

				file2->Open(j, 'o');
				file2->WriteGraphs(l->BFdataGetter(), tM, tL, V, E, V0);
				file2->Close();

				delete m;
				delete l;
			}
			file->Close();
		}
		cout << "Wczytano plikow: " << j << "." << endl;

		delete test;
		delete file;
		delete file2;
		break;
	}
	return 0;
}