// Examen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"
#include <stdlib.h>
#include <string>

std::string SeparadorComando(std::string Texto, int size) {
	char buffer[100];
	std::string Comando;
	for (int i = 0; i < size; i++)
	{
		if (Texto[i] > 'a' || Texto[i] < 'z')buffer[i] = Texto[i];
		else if (Texto[i] = ' ') {
			Comando = buffer;
			return Comando;
		}
		else
			return 0;
	}
}

std::string SeparadorNombre(std::string Texto, int size) {
	char buffer[100];
	std::string Nombre;
	bool Espacios = false;
	for (int i = 0; i < size; i++)
	{
		if (Texto[i] > 'a' || Texto[i] < 'z')buffer[i] = Texto[i];
		else if (Texto[i] = ' ') {
			if (!Espacios)Espacios = true;
			buffer[i] = Texto[i];
		}
		else
			return 0;
	}
	Nombre = buffer;
	return Nombre;
}

int main()
{
    return 0;
}

