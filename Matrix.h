#pragma once
#include "Basis.h"
#include<iostream>
using namespace std;

class Matrix
	:public Basis
{
	int** arr; //tablica dwuwymiarowa - macierz

public:

	virtual bool Create(int, int, int);
	virtual void Display();
	virtual void BF();

	Matrix(int, int, int);
	~Matrix();
};