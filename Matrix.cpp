#include "Matrix.h"
#include "Support.h"
#include <iostream>
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