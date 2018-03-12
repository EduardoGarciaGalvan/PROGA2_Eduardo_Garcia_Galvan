#pragma once
#include<iostream>
class Nodo
{
public:
	Nodo();
	~Nodo();
	std::string getNombre();
	void setNombre(std::string);
	Nodo* getPadre();
	void setPadre(Nodo*);
	Nodo* getPrimerHijo();
	void setPrimerHijo(Nodo*);
	Nodo* getSiguienteHermano();
	void setSiguienteHermano(Nodo*);
	Nodo* getHermanoAnterior();
	void setHermanoAnterior(Nodo*);
private:
	std::string Nombre;
	Nodo* Padre;
	Nodo* PrimerHijo;
	Nodo* SiguienteHermano;
	Nodo* HermanoAnterior;
	Nodo* next;
	Nodo* prev;
};

