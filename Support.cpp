#include "Support.h"
#include "List.h"
#include "Matrix.h"
#include <iostream>
#include <limits>
#include <conio.h>
using namespace std;

void Fill(int V, int E, Matrix* m, List* l)
{
	int x, y, w;
	bool** nodes = new bool* [V]; //tablica polaczen
	//allokacja pamieci
	for (int i = 0; i < V; i++)
	{
		nodes[i] = new bool[V];
		for (int j = 0; j < V; j++)
			nodes[i][j] = false;
	}

	//tworzenie polaczen
	while (E--)
	{
		x = Random(1, V);
		y = Random(1, V);

		if (x == y || nodes[x - 1][y - 1] || nodes[y - 1][x - 1]) //jesli wierzcholek startowy=koncowy lub polaczenie juz istnieje
			E++;
		else
		{
			nodes[x - 1][y - 1] = true;
			nodes[y - 1][x - 1] = true;
			w = Random(1, MAX_WEIGHT);
			m->Create(x, y, w);
			l->Create(x, y, w);
		}
	}

	//usuwanie tablicy
	for (int i = 0; i < V; i++)
		delete[] nodes[i];
	delete[] nodes;
}

int Random(int min, int max)
{
	if (min >= max) return max;
	return min + rand() % (max - min + 1);
}

int CalcEdges(int V, int D)
{
	int E = (int)((D / 100.0) * V * (V - 1.0)) / 2;
	if (E < V - 1)
		return (V - 1);
	else
		return E;
}

int GetValue(int min, int max)
{
	int x;
	while (true)
	{
		if (!(cin >> x) || x < min || x > max)
		{
			cin.clear();
			cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cin.sync();
			cout << "Blad! Ponow: ";
		}
		else break;
	}
	return x;
}

void PressAnyKey()
{
	cout << endl << "Nacisnij dowolny przycisk, aby kontynuowac..." << endl;
	_getch();
	system("cls");
}

int Menu()
{
	cout << "------ Badanie algorytmu Bellmana-Forda dla grafow nieskierowanych ------" << endl << endl;
	cout << "1. Wygeneruj 100 grafow testowych" << endl;
	cout << "   Tworzy baze grafow wejsciowych i zapisuje je w katalogu Graph data/Graph in" << endl << endl;
	cout << "2. Wygeneruj wszystkie grafy losowo" << endl;
	cout << "   Generuje po 100 grafow dla kazdej ilosci wierzcholkow dla kazdej gestosci," << endl;
	cout << "   bada algorytmem Dijkstry i zapisuje usrednione czasy w Graph data/Time out" << endl << endl;
	cout << "3. Wczytaj wszystkie grafy z pliku" << endl;
	cout << "   Wczytuje 100 grafow z pliku, bada algorytmem Dijkstry i zapisuje najkrotsze" << endl;
	cout << "   drogi wraz z kosztami oraz czasem wykonywania w Graph Data/Graph out" << endl << endl;
	cout << "Wybor: ";
	return GetValue(1, 3);
}
