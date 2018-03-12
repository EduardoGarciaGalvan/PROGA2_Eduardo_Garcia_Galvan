#include "stdafx.h"
#include "Lista.h"


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
	for (int i = 0; i < Carpetas; i++) {
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
	if (Arbol->getPrimerHijo() == NULL)return 0;
	Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
	ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
	while (ArbolAuxiliar != Arbol->getPrimerHijo()) {
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
	if (Arbol->getPrimerHijo() == NULL) return;
	else {
		Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
		for (int i = 0; i < Carpetas; i++)
		{
			std::cout << &ArbolAuxiliar->getNombre() << std::endl;
			ArbolAuxiliar->setSiguienteHermano(ArbolAuxiliar->getSiguienteHermano());
		}
	}
}

bool Lista::BorrarCarpeta(std::string Nombre) {
	if (isEmpty())return false;
	Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
	Nodo* ArbolAuxiliar2 = ArbolAuxiliar->getSiguienteHermano();
	if (ArbolAuxiliar->getNombre() == Nombre) {
		Arbol->setPrimerHijo(ArbolAuxiliar2);
		ArbolAuxiliar->getHermanoAnterior()->setSiguienteHermano(ArbolAuxiliar2);
		ArbolAuxiliar2->setHermanoAnterior(ArbolAuxiliar->getHermanoAnterior());
	}
	delete ArbolAuxiliar;
	return true;
}

bool Lista::Exists(std::string Nombre) {
	if (Arbol->getPrimerHijo() == NULL)return false;
	else {
		Nodo* ArbolAuxiliar = Arbol->getPrimerHijo();
		for (int i = 0; i < Carpetas; i++)
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
		for (int i = 0; i < Carpetas; i++)
		{
			ArbolAuxiliar = ArbolAuxiliar->getSiguienteHermano();
			if (ArbolAuxiliar->getNombre() == Nombre) Arbol=ArbolAuxiliar;
		}
	}
}

void Lista::RetrocederCarpeta() {
	Nodo* ArbolAuxiliar = Arbol->getPadre();
	Arbol = ArbolAuxiliar;
}
