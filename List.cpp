#include "List.h"
#include "Support.h"
#include <iostream>
using namespace std;

Graph::Graph(int v_, int w_, Graph* n)
{
	this->v = v_;
	this->w = w_;
	this->next = n;
}

Graph::~Graph()
{
	this->next = nullptr;
}

void List::Push(int x, int y, int w)
{
	Graph* g = new Graph;

	g->v = y;
	g->w = w;

	if (this->arr[x] == 0)
	{
		this->arr[x] = g;
	}
	else
	{
		Graph* temp = this->arr[x];
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = g;
		g->next = 0;
	}
}

bool List::Create(int x, int y, int w)
{
	if (x == y) cout << "Polaczenie niedozwolone." << endl;
	else
	{
		try
		{
			this->Push(x - 1, y - 1, w);
			this->Push(y - 1, x - 1, w);
		}
		catch (...)
		{
			cout << "Blad tworzenia listy!" << endl;
			return false;
		}
	}
	return true;
}

void List::Display()
{
	cout << "--- Metoda listy sasiedztwa ---" << endl << endl;
	for (int i = 0; i < this->V; i++)
	{
		cout << "Wierzcholek " << i + 1 << ":" << endl;
		Graph* temp = this->arr[i];
		while (temp)
		{
			cout << "\tsasiad: " << temp->v + 1 << ", waga: " << temp->w << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	PressAnyKey();
}

void List::BF()
{
	Graph* temp;

	for (int i = 0; i < this->V; i++)
		this->BFdata[i] = INF;
	this->BFdata[this->V0 - 1] = 0;

	for (int i = 0; i < this->V; i++)
	{
		for (int j = 0; j < this->V; j++)
		{
			temp = this->arr[j];
			while (temp)
			{
				if (this->BFdata[j] + temp->w < this->BFdata[temp->v])
					this->BFdata[temp->v] = this->BFdata[j] + temp->w;
				temp = temp->next;
			}
		}
	}

	for (int j = 0; j < this->V; j++)
	{
		temp = this->arr[j];
		while (temp)
		{
			if (this->BFdata[j] + temp->w < this->BFdata[temp->v])
			{
				cout << "Graf zawiera cykl ujemny!" << endl;
				return;
			}
			temp = temp->next;
		}
	}
}

List::List(int v, int e, int v0)
	:Basis(v, e, v0)
{
	this->arr = new Graph* [this->V];
	for (int i = 0; i < this->V; i++)
	{
		this->arr[i] = 0;
	}
}

List::~List()
{
	Graph* temp;
	for (int i = 0; i < this->V; i++)
	{
		while (this->arr[i])
		{
			temp = this->arr[i]->next;
			delete this->arr[i];
			this->arr[i] = temp;
		}
	}
	delete[] this->arr;
}