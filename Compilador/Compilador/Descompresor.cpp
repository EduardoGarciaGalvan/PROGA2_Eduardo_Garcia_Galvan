#include "stdafx.h"
#include "Descompresor.h"


Descompresor::Descompresor()
{
}


Descompresor::~Descompresor()
{
}

bool Descompresor::Descomprimir(std::string Nombre) {
	if (!Linea.find(Palabra)) {
		std::cout << "Archivo no Admitido" << std::endl;
		return false;
	}
	Archivo.open(Nombre, std::ios::in);

	ArchivoT.open(Nombre, std::ios::out);
}