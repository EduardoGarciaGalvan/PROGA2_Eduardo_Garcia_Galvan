#include "stdafx.h"
#include "Lista.h"
#include <string>


Lista::Lista()
{
	Nodo *Arbol=NULL;
}

bool Lista::isEmpty()

{
	return Arbol == NULL;
}

Lista::~Lista()
{
}

bool Lista::CarpetaValida(std::string Nombre) {
	if (Arbol->getPrimerHijo() == NULL)return false;
	Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
	for (int i = 0; i < Contenido(); i++) {
		if (ArbolAuxiliar->getNombre() == Nombre)return true;
		ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
	}
	return false;
}

Nodo* Lista::CrearCarpeta(std::string Nombre) {
	Nodo *Carpeta = new Nodo();
	Carpeta->setNombre(Nombre);
	return Carpeta;
}

int Lista::Contenido() {
	int Carpetas = 0;
	if (Arbol->getPrimerHijo() == NULL)return 0;
	Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
	ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
	while (ArbolAuxiliar != NULL) {
		Carpetas++;
		ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
	}
	return Carpetas;
}

void Lista::InsertarCarpeta(std::string Nombre) {
	Nodo* Carpeta = CrearCarpeta(Nombre);
	Carpeta->setPrimerHijo(NULL);
	Carpeta->setSiguienteHermano(NULL);
	Carpeta->setHermanoAnterior(NULL);
	if (Arbol == NULL) {
		Nodo* ArbolAuxiliar= CrearCarpeta("Unidad C");
		ArbolAuxiliar->setPrimerHijo(Carpeta);
		ArbolAuxiliar->setSiguienteHermano(NULL);
		ArbolAuxiliar->setHermanoAnterior(NULL);
		Carpeta->setPadre(ArbolAuxiliar);
		Arbol = ArbolAuxiliar;
	}
	else {
		if (Arbol->getPrimerHijo() == NULL) {
			Arbol->setPrimerHijo(Carpeta);
		}
		else {
			Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
			while (ArbolAuxiliar->getSiguienteHermano() != NULL) ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
			ArbolAuxiliar->setSiguienteHermano(Carpeta);
			Carpeta->setHermanoAnterior(ArbolAuxiliar);
		}
		Carpeta->setPadre(Arbol);
	}
}

void Lista::MostrarCarpetas() {
	if (Arbol->getPrimerHijo() != NULL){
		Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
		std::string Nombre;
		do{
			Nombre = ArbolAuxiliar->getNombre();
			std::cout << Nombre << std::endl;
			ArbolAuxiliar=ArbolAuxiliar->getSiguienteHermano();
		} while (ArbolAuxiliar!=NULL);
	}
	return;
}

bool Lista::BorrarCarpeta(std::string Nombre) {
	if (isEmpty())return false;
	Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
	if (ArbolAuxiliar->getSiguienteHermano() != NULL) {
		Nodo* ArbolAuxiliar2 = ArbolAuxiliar->getSiguienteHermano();
		if (ArbolAuxiliar->getNombre() == Nombre) {
			Arbol->setPrimerHijo(ArbolAuxiliar2);
		}
		else while (ArbolAuxiliar2 != NULL) {
			if (ArbolAuxiliar2->getNombre() == Nombre) {
				ArbolAuxiliar = ArbolAuxiliar2->getHermanoAnterior();
				ArbolAuxiliar->setSiguienteHermano(ArbolAuxiliar2->getSiguienteHermano());
			}
			ArbolAuxiliar2 = NULL;
			return true;
		}
	}
		ArbolAuxiliar = NULL;
	return true;
}

bool Lista::Exists(std::string Nombre) {
	if (Arbol->getPrimerHijo() == NULL)return false;
	else {
		Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
		for (int i = 0; i < Contenido(); i++)
		{
			if (ArbolAuxiliar->getNombre() == Nombre)return true;
			ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
		}
		return false;
	}
}

void Lista::AccederCarpeta(std::string Nombre)
{
	if (Exists(Nombre)) {
		Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
		for (int i = 0; i < Contenido(); i++)
		{
			if (ArbolAuxiliar->getNombre() == Nombre) {
				Arbol = ArbolAuxiliar;
				return;
			}
			ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
		}
	}
	else std::cout << "Nombre invalido" << std::endl;
}

void Lista::RetrocederCarpeta() {
	Arbol = Arbol->getPadre();
}
