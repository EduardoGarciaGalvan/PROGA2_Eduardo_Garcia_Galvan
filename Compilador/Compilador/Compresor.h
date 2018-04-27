#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Compresor
{
public:
	Compresor();
	~Compresor();
	bool Comprimir(std::string Nombre);
private:
	std::string Texto, Linea, Nombre;
	std::ifstream Archivo;
	std::ofstream ArchivoT;
	std::string Palabra = ".txt";
	std::vector <std::string> Palabras;
	std::vector <int> NPalabras;
	std::vector <int> Numero;
	std::vector <std::string> texto;
	int pos;
};

