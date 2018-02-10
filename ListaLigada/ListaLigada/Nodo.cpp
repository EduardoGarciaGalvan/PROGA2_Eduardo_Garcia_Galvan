#include "stdafx.h"
#include "Nodo.h"
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
