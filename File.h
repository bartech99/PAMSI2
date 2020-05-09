#pragma once
#include "Basis.h"
#include "List.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class File
{
	fstream file; //plik
	stringstream title; //nazwa pliku

	const string ReadingDir = "Graph data/Graph in/"; //sciezka do plikow odczytywanych
	const string WritingDir = "Graph data/Graph out/"; //sciezka do plikow zapisywanych
	const string TimesDir = "Graph data/Time out/"; //sciezka do zapisu rezultatow

public:

	string MakeTitle(int, char);
	bool Open(int, char);
	void Close();

	void Make();

	bool ReadBegin(int&, int&, int&);
	bool Read(List*, Matrix*);

	void WriteTimes(int, double, double);
	void WriteGraphs(int*, double, double, int, int, int);

	File();
	~File();
};