// ListaLigada.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"
#include <iostream>
using namespace std;

template <class T>
int main()
{
	Lista<T> lista();
	int Opcion, Posicion;
	T Valor;
	do
	{
		if (Opcion == NULL || Opcion == 3)
		{
			cout << "Que desea hacer:" << endl
				<< "1)Agregar un elemento" << endl
				<< "2)Eliminar un elemento" << endl
				<< "3)Imprimir los elementos" << endl
				<< "4)Salir" << endl;
		}
	cin >> Opcion;
		switch (Opcion)
		{
		case(1):
			cout << "Cual es el elemento a agregar" << endl;
			cin >> Valor;
			lista.AddNode(Valor);
			break;
		case(2):
			cout << "Que elemento quieres eliminar" << endl;
			cin >> Posicion;
			lista.DeleteNode(Posicion);
			break;
		case(3):
			system('cls')
			lista.Print();
			break;
		case(4):
			lista.~Lista();
			return 0;
		default:
			break;
		}
	} while (Opcion != 4);
}

