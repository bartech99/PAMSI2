#pragma once
#include <iostream>
#include <ctime>
using namespace std;

const int INF = 1000;

class Basis
{
protected:

	int V; //ilosc wierzcholkow
	int E; //ilosc krawedzi
	int V0; //wierzcholek startowy
	int** BFdata; //tablica danych algorytmu Bellmana

public:

	virtual bool Create(int, int, int) = 0; //pobiera wartosci i tworzy dana strukture
	virtual void Display() = 0; //wyswietla zawartosc danej struktury
	virtual void BF(bool) = 0; //wywolanie algorytmu Bellmana-Forda

	Basis(int v, int e, int v0) //konstruktor
	{
		this->V = v;
		this->E = e;
		this->V0 = v0;
		this->BFdata = new int* [v];
		for (int i = 0; i < v; i++)
		{
			this->BFdata[i] = new int[2];
			this->BFdata[i][0] = INF;
			this->BFdata[i][1] = -1;
		}
		this->BFdata[v0 - 1][0] = 0;
	}
	~Basis() //destruktor
	{
		for (int i = 0; i < this->V; i++)
			delete[] this->BFdata[i];
		delete[] this->BFdata;
	}
};