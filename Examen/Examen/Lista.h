#pragma once
#include "Nodo.h"

class Lista
{
public:
	Lista();
	bool isEmpty();
	~Lista();
	Nodo* CrearCarpeta(std::string);
	int Contenido();
	void InsertarCarpeta(std::string);
	void MostrarCarpetas();
	bool BorrarCarpeta(std::string);
	bool Exists(std::string);
	void AccederCarpeta(std::string);
	void RetrocederCarpeta(std::string);
private:
	int Carpetas = 0;
	Nodo* Arbol;
	bool CarpetaValida(std::string);
};

