#pragma once
#include "Nodo.h"
#include <iostream>

template <class T>
class Lista
{
public:
	Lista();
	~Lista();
	int Size();
	bool isEmpty();
	T AddNode(T value);
	bool DeleteNode(int pos);
	bool Print();
	bool Exists(T Value);
	Nodo* getFirstNode();
	Nodo* getLastNode();
private:
	Nodo* start;
	bool isValidPos(int pos);
};

