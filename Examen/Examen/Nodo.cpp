#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
	std::string Nombre;
	Nodo *Padre;
	Nodo *Hijo;
	Nodo *Hermanos;
}


Nodo::~Nodo()
{
}



std::string Nodo::getNombre() {
	return this->Nombre;
}

void Nodo::setNombre(std::string Nombre) {
	this->Nombre = Nombre;
}

Nodo* Nodo::getPrimerHijo() {
	return this->PrimerHijo;
}

void Nodo::setPrimerHijo(Nodo* PrimerHijo) {
	this->PrimerHijo = PrimerHijo;
}

Nodo* Nodo::getSiguienteHermano() {
	return this->SiguienteHermano;
}

void Nodo::setSiguienteHermano(Nodo* Hermano) {
	this->SiguienteHermano = Hermano;
}

Nodo* Nodo::getHermanoAnterior() {
	return this->HermanoAnterior;
}

void Nodo::setHermanoAnterior(Nodo* Hermano) {
	this->HermanoAnterior = Hermano;
}

Nodo* Nodo::getPadre() {
	return this->Padre;
}

void Nodo::setPadre(Nodo* Padre) {
	this->Padre = Padre;
}
