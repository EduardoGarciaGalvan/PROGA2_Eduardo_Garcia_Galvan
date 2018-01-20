#pragma once
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

class Parser
{
public:
	Parser(string);
	~Parser();
	void Carga();
	bool Validez();
	bool Buscador();
	float coordenadas();
	void Cerrar();
private:
	string Documento, Linea, Vertices, token;
	ifstream Archivo;
	int NVertices = 0, i = 0;
	char *Palabra = "mesh";
	double CoordenadaX, CoordenadaY, CoordenadaZ;
};

