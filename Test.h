#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Test
{
	clock_t start; //czas rozpoczecia testu
	clock_t final; //czas zakonczenia testu
	int quanity; //ilosc pomiarow
	double* results; //tablica wynikow
	double average; //sredni czas dla 100 pomiarow

public:

	void Begin();
	double End(int);

	double Average();
	double CalcAverage();

	void Display(char);

	Test(int);
	~Test();
};