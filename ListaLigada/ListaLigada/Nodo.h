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

template <class T>
Nodo<T>::Nodo(T Value)
{
	this->Value = Value;
	this->next = NULL;
	this->prev = NULL;
}

template<class T>
Nodo<T>::~Nodo()
{
}

template<class T>
T Nodo<T>::getValue()
{
	return this->Value;
}

template<class T>
void Nodo<T>::setValue(T value)
{
	this->Value = Value;
}

template<class T>
Nodo<T>* Nodo<T>::getNext()
{
	return this->next;
}

template<class T>
void Nodo<T>::setNext(Nodo* next)
{
	this->next = next;
}

template<class T>
Nodo<T>* Nodo<T>::getPrev()
{
	return this->prev;
}

template<class T>
void Nodo<T>::setPrev(Nodo* prev)
{
	this->prev = prev;
}
