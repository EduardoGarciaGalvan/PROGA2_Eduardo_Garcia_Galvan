#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

template <class T>
class Lista
{
public:
	Lista();
	~Lista();
	int Size();
	bool isEmpty();
	void AddNode(T value);
	bool DeleteNode(int pos);
	bool Print();
	bool Exists(T Value);
	Nodo<T>* getFirstNode();
	Nodo<T>* getLastNode();
private:
	Nodo<T>* start;
	bool isValidPos(int pos);
};


template<class T>
Lista<T>::Lista()
{
	start = NULL;
}

template<class T>
bool Lista<T>::isEmpty()
{
	return start == NULL;
}

template<class T>
Lista<T>::~Lista()
{
	if (isEmpty())return;
	start->getPrev()->setNext(NULL);
	while (start != NULL)
	{
		Nodo<T>* aux = start->getNext();
		delete start;
		start = aux;
	}
}

template<class T>
int Lista<T>::Size()
{
	if (isEmpty())return 0;
	int size = 0;
	Nodo<T>* aux = start;
	do
	{
		size++;
		aux = aux->getNext();
	} while (aux != start);
	return size;
}

template<class T>
void Lista<T>::AddNode(T value)
{
	Nodo<T> *NN = new Nodo<T>(value);
	if (!isEmpty())
	{
		NN->setPrev(start->getPrev());
	}
	NN->setNext(start);
}

template<class T>
bool Lista<T>::isValidPos(int pos)
{
	return -1 < pos && pos < Size();
}

template<class T>
bool Lista<T>::DeleteNode(int pos)
{
	if (!isValidPos(pos))return false;
	if (pos = 0 && start->getNext() == start)
	{
		delete start;
		start = NULL;
	}
	else if (pos = 0)
	{
		Nodo<T>*aux = start->getNext();
		start->getPrev()->setNext(aux);
		delete start;
		start = aux;
	}
	else {
		Nodo<T>* aux = start;
		for (int i = 0; i < pos; i++) aux = aux->getNext();
		aux->getPrev()->setNext(aux->getNext());
		delete aux;
	}
	return true;
}

template<class T>
bool Lista<T>::Print()
{
	if (isEmpty())return false;
	Nodo<T>*aux = start;
	do
	{
		std::cout << aux->getValue() << std::endl;
		aux = aux->getNext();
	} while (aux != start);
	return true;
}

template<class T>
bool Lista<T>::Exists(T Value)
{
	if (isEmpty())return false;
	Nodo<T> *aux = start;
	do
	{
		if (aux->getValue == Value)return true;
		aux = aux->getNext();
	} while (aux != start);
	return false;
}

template<class T>
Nodo<T>* Lista<T>::getFirstNode()
{
	return start;
}

template<class T>
Nodo<T>* Lista<T>::getLastNode()
{
	if (start == NULL)return NULL;
	return start->getPrev();
}

