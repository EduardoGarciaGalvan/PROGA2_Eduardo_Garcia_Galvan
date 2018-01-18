#include "stdafx.h"
#include "CVertices.h"
#include <conio.h>
#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
using namespace std;


CVertices::CVertices(string _Documento)
{
	Documento = _Documento;
}

CVertices::~CVertices()
{
}

void CVertices::Carga()
{
	Archivo.open(Documento.c_str(), ios::in);//Abre el archivo en modo lectura
}

bool CVertices::Validez() 
{
	return Archivo.fail();
}
bool CVertices::Buscador() 
{
	while (getline(Archivo, Linea))//Busca donde se encuentre la palabra mesh
	{
		if (Linea.find(Palabra) != string::npos)//Encuentra la linea donde se ubica la palabra
		{
			getline(Archivo, Vertices, ';');//Obtiene los vertices que tiene el documento
			cout << Linea << endl;
			getline(Archivo, Linea);
			cout << "space para mostrar los vertices de uno en uno." << endl << "Enter para mostrar todos los vertices." << endl;
			cout << "Tu objeto tiene:" << Vertices << " vertices" << endl;
			return true;
		}
	}
	return false;
}

float CVertices::coordenadas()
{
	NVertices = atoi(Vertices.c_str());//Conversion de string a int
	do
	{
		char j = _getch();
		switch (j)
		{
		case(' '):// Imprime de uno en uno
		{
			getline(Archivo, Linea);
			istringstream Lineaux(Linea);
			while (getline(Lineaux, Linea, ','))//Toma la fila n de las coordenadas del vertice n
			{
				istringstream Lineaux(Linea);//Extrae las coordenadas de los vertices
				getline(Lineaux, token, ';');
				CoordenadaX = stof(token);
				getline(Lineaux, token, ';');
				CoordenadaY = stof(token);
				getline(Lineaux, token, ';');
				CoordenadaZ = stof(token);
			}
			cout << "X: " << CoordenadaX << "  Y: " << CoordenadaY << "  Z:" << CoordenadaZ << endl;
			i++;
			break;
		}
		case(13)://Imprime todos los que faltan
		{
			while (i < NVertices)
			{
				getline(Archivo, Linea);
				istringstream Lineaux(Linea);
				while (getline(Lineaux, Linea, ','))
				{
					istringstream Lineaux(Linea);
					getline(Lineaux, token, ';');
					CoordenadaX = stof(token);
					getline(Lineaux, token, ';');
					CoordenadaY = stof(token);
					getline(Lineaux, token, ';');
					CoordenadaZ = stof(token);
				}
				cout << "X: " << CoordenadaX << "  Y: " << CoordenadaY << "  Z:" << CoordenadaZ << endl;
				i++;
			}
			break;
		}
		default:
			break;
		}
	} while (i < NVertices);
	return 0;
}

void CVertices::Cerrar()
{
	Archivo.close();
}