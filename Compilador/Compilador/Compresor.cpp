#include "stdafx.h"
#include "Compresor.h"


Compresor::Compresor()
{
}


Compresor::~Compresor()
{
}

bool Compresor::Comprimir(std::string Nombre) {
	std::istringstream Lineaux(Nombre);
	getline(Lineaux, Linea, '.');
	this->Nombre = Linea + ".p2";
	if (!Nombre.find(Palabra)) {
		std::cout << "Archivo no Admitido" << std::endl;
		return false;
	}
	Archivo.open(Nombre, std::ios::in);
	while (getline(Archivo, Linea)) {
		std::istringstream Lineaux(Linea);
		while (getline(Lineaux, Linea, ' '))
		{
			std::istringstream Lineaux(Linea);
			getline(Lineaux, Palabra, ' ');
			texto.push_back(Palabra);
			std::vector <int> NPalabraA = NPalabras;
			for (int i = 0; i < Palabras.size(); i++) {
				if (Palabra == Palabras[i]) {
					NPalabras[i]++;
					continue;
				}
			}
			if (NPalabraA == NPalabras) {
					Palabras.push_back(Palabra);
					NPalabras.push_back(0);
			}
		}
	}
	for (int i = 0; i < Palabras.size(); i++)
	{
		for (int j = 0; j < Numero.size(); j++)
		{
			if (NPalabras[i] == Numero[j]) {
				NPalabras[i]++;
			}
		}
	}
	for (int i = 0; i < texto.size(); i++)
	{
		for (int j = 0; j < Palabras.size(); j++)
		{
			if (texto[i] == Palabras[j]) {
				texto[i] = NPalabras[j];
			}
		}
	}
	for (int i = 0; i < texto.size(); i++)
	{
		Texto+= texto[i] + " ";
	}
	ArchivoT.open(this->Nombre, std::ios::out | std::ios::app);
	ArchivoT << Texto;
	ArchivoT.close();
	return true;
}