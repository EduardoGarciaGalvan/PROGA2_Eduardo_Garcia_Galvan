#pragma once
#include "stdio.h"
template<class T>
class Nodo
{
public:
	Nodo(T Value);
	~Nodo();
	T getValue();
	void setValue(T Value);
	Nodo* getNext();
	void setNext(Nodo* next);
	Nodo* getPrev();
	void setPrev(Nodo* prev);
private:
	T Value;
	Nodo* next;
	Nodo* prev;
};

