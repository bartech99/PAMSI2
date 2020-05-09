#include "File.h"
#include "Support.h"
#include <iostream>
#include <sstream>
using namespace std;

string File::MakeTitle(int i, char x)
{
	this->title.str("");
	if (x == 't') //zapis czasu
	{
		this->title << this->TimesDir;
		this->title << i;
		this->title << " wierzcholkow.txt";
	}
	else
	{
		if (x == 'i' || x == 'g') //wczytywanie lub zapis wygenerowanych
			this->title << this->ReadingDir;
		else if (x == 'o') //zapis sciezek
			this->title << this->WritingDir;
		this->title << i;
		this->title << ".txt";
	}
	return this->title.str();
}

bool File::Open(int i, char x)
{
	try
	{
		if (x == 'i')
		{
			this->file.open(this->MakeTitle(i, x), ios::in);
		}
		else if (x == 'o' || x == 't')
		{
			this->file.open(this->MakeTitle(i, x), ios::out);
		}
		else if (x == 'g')
		{
			this->file.open(this->MakeTitle(i, x), ios::out);
		}
		if (file.good())
			return true;
	}
	catch (...) { cout << "Blad pliku" << endl; }
	return false;
}

void File::Close()
{
	this->file.close();
}

void File::Make()
{
	int x, y, V, E, D;
	bool** nodes; //tablica polaczen
	for (int I = 1; I <= 100; I++)
	{
		V = Random(5, 50);
		D = 25 * Random(1, 4);
		E = CalcEdges(V, D);

		//allokacja pamieci
		nodes = new bool* [V];
		for (int i = 0; i < V; i++)
		{
			nodes[i] = new bool[V];
			for (int j = 0; j < V; j++)
				nodes[i][j] = false;
		}

		//tworzenie pliku
		this->Open(I, 'g');
		this->file << E << " " << V << " " << Random(1, MAX_WEIGHT) << endl;

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
				this->file << x << " " << y << " " << Random(1, MAX_WEIGHT) << endl;
			}
		}

		//usuwanie tablicy
		for (int i = 0; i < V; i++)
			delete[] nodes[i];
		delete[] nodes;
		this->Close();
	}
}

bool File::ReadBegin(int& E, int& V, int& V0)
{
	try
	{
		this->file >> E;
		this->file >> V;
		this->file >> V0;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

bool File::Read(List* l, Matrix* m)
{
	int x, y, w;
	if (!file.eof() && file >> x && file >> y && file >> w)
	{
		l->Create(x, y, w);
		m->Create(x, y, w);
		return true;
	}
	return false;
}

void File::WriteTimes(int D, double Mavg, double Lavg)
{
	this->file << "Gestosc " << D << "%:" << endl;
	this->file << "\tmacierz: " << Mavg << "[ms]" << endl;
	this->file << "\tlista: " << Lavg << "[ms]" << endl << endl;
}

void File::WriteGraphs(int* data, double testM, double testL, int V, int E, int V0)
{
	this->file << "Ilosc wierzcholkow i krawedzi: " << V << ", " << E << endl;
	this->file << "Wierzcholek startowy: " << V0 << endl;
	this->file << "Czas wykonania dla macierzy: " << testM << "[ms]" << endl;
	this->file << "Czas wykonania dla list: " << testL << "[ms]" << endl << endl;
	this->file << "--- wierzcholek koncowy --- koszt drogi ---" << endl;
	for (int i = 0; i < V; i++)
		this->file << "\t\t" << i + 1 << "\t\t" << data[i] << endl;
}

File::File()
{
	this->title.str("");
}

File::~File()
{
	this->Close();
}