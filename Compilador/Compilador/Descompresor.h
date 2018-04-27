#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Descompresor
{
public:
	Descompresor();
	~Descompresor();
	bool Descomprimir(std::string Nombre);
private:
	std::string Texto, Linea, Nombre;
	std::ofstream Archivo;
	std::ifstream ArchivoT;
	std::string Palabra = ".p2";
};

