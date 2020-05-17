#include "Matrix.h"
#include "Support.h"
#include <iostream>
#include <Windows.h>
using namespace std;

bool Matrix::Create(int x, int y, int w)
{
	if (x == y) cout << "Polaczenie niedozwolone." << endl;
	else
	{
		try
		{
			this->arr[x - 1][y - 1] = w;
			this->arr[y - 1][x - 1] = w;
		}
		catch (...)
		{
			cout << "Blad tworzenia macierzy!" << endl;
			return false;
		}
	}
	return true;
}

void Matrix::Display()
{
	cout << "--- Metoda macierzy sasiedztwa ---" << endl << endl;
	for (int i = 0; i < this->V; i++)
	{
		for (int j = 0; j < this->V; j++)
		{
			cout << this->arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	PressAnyKey();
}

void Matrix::BF()
{
	for (int i = 0; i < this->V; i++)
		this->BFdata[i] = INF;
	this->BFdata[this->V0 - 1] = 0;
	int w;

	for (int iV = 0; iV < this->V; iV++) 
	{
		for (int i = 0; i < this->V; i++) 
		{
			for (int j = 0; j < this->V; j++) 
			{
				w = this->arr[i][j];

				if (this->BFdata[i] + w < this->BFdata[j]) 
				{
					this->BFdata[j] = this->BFdata[this->V0 - 1] + w;
				}
			}
		}
	}

	for (int iV = 0; iV < this->V; iV++)
	{
		for (int i = 0; i < this->V; i++)
		{
			for (int j = 0; j < this->V; j++)
			{
				w = this->arr[i][j];

				if (this->BFdata[i] + w < this->BFdata[j]) 
				{
					if (this->BFdata[i] > INF / 2) 
						this->BFdata[i] = INF;
					else if (w == INF) 
						continue;
					else this->BFdata[j] = -INF;
				}
				else if (this->BFdata[i] > INF / 2) this->BFdata[i] = INF;
			}
		}
	}
}

Matrix::Matrix(int v, int e, int v0)
	:Basis(v, e, v0)
{
	this->arr = new int* [this->V];
	for (int i = 0; i < this->V; i++)
	{
		this->arr[i] = new int[this->V];
		for (int j = 0; j < this->V; j++)
		{
			this->arr[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->V; i++)
	{
		delete[] this->arr[i];
	}
	delete[] this->arr;
}