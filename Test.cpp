#include "Test.h"
#include <iostream>
#include <ctime>
using namespace std;

void Test::Begin()
{
	this->start = clock();
}

double Test::End(int i)
{
	this->final = clock();
	if (i < this->quanity)
	{
		this->results[i] = (final - start) / (double)CLOCKS_PER_SEC;
		return this->results[i];
	}
	else
		return 0.0;
}

double Test::Average()
{
	return this->average;
}

double Test::CalcAverage()
{
	this->average = 0.0;
	for (int i = 0; i < this->quanity; i++)
		this->average += this->results[i];
	this->average *= 1000;
	this->average /= (double)(this->quanity);
	return this->average;
}

void Test::Display(char type)
{
	this->CalcAverage();
	if (type == 'm')
		cout << "\t\tSredni czas dla macierzy: " << this->average << " [ms]." << endl;
	else if (type == 'l')
		cout << "\t\tSredni czas dla listy: " << this->average << " [ms]." << endl;
}

Test::Test(int q)
{
	this->start = clock();
	this->final = clock();
	this->quanity = q;
	this->average = 0.0;
	this->results = new double[q];

	cout.setf(ios::fixed);
}

Test::~Test()
{
	delete[] this->results;
}