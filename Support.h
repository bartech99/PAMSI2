#pragma once
#include "List.h"
#include "List.h"
#include "Matrix.h"
#include <iostream>
#include <limits>
#include <conio.h>
using namespace std;

const int MAX_V = 100;
const int MAX_WEIGHT = 5;

void Fill(int, int, Matrix*, List*);
int Random(int, int);

int CalcEdges(int, int);
int GetValue(int, int); //pobiera wartosc z klawiatury
void PressAnyKey(); //wstrzymuje program do nacisniecia dowolnego przycisku
int Menu(); //wyswietla menu i pobiera wybor