#pragma once
#include "Basis.h"
#include <iostream>
using namespace std;

struct Graph
{
	int v; //sasiad
	int w; //waga
	Graph* next; //wskaznik na kolejny element listy

	Graph(int = 0, int = 0, Graph* = 0); //konstruktor
	~Graph(); //destruktor
};

class List
	:public Basis
{
	Graph** arr; //tablica list

public:

	void Push(int, int, int);

	virtual bool Create(int, int, int);
	virtual void Display();
	virtual void BF(bool);

	List(int, int, int);
	~List();
};