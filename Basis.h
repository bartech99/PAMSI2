#pragma once
#include <iostream>
#include <ctime>
using namespace std;

const int INF = 1000000;

class Basis
{
protected:

	int V; //ilosc wierzcholkow
	int E; //ilosc krawedzi
	int V0; //wierzcholek startowy
	int* BFdata; //tablica danych algorytmu Bellmana

public:

	virtual bool Create(int, int, int) = 0; //pobiera wartosci i tworzy dana strukture
	virtual void Display() = 0; //wyswietla zawartosc danej struktury
	virtual void BF() = 0; //wywolanie algorytmu Bellmana-Forda
	int* BFdataGetter() { return this->BFdata; }

	Basis(int v, int e, int v0) //konstruktor
	{
		this->V = v;
		this->E = e;
		this->V0 = v0;
		this->BFdata = new int[v];
	}
	~Basis() //destruktor
	{
		delete[] this->BFdata;
	}
};