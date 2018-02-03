#pragma once
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Parseando
{
public:
	Parseando(string);
	~Parseando();
	void Carga();
	bool Validez();
	bool Buscador();
	float coordenadas();
	void Cerrar();
private:
	string Documento, Linea, Vertices, token;
	ifstream Archivo;
	int NVertices = 0, i = 0, *Contador;
	char *Palabra = "mesh";
};

struct Coordenadas
{
	double CoordenadaX, CoordenadaY, CoordenadaZ;
};