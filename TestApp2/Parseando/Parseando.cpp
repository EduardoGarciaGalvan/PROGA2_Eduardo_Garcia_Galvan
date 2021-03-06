// Parseando.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Parseando.h"
#include <conio.h>
#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define use_malloc
//#define use_new
//#define use_vector



Parseando::Parseando(string _Documento)
{
	Documento = _Documento;
}

Parseando::~Parseando()
{
}

void Parseando::Carga()
{
	Archivo.open(Documento.c_str(), ios::in);//Abre el archivo en modo lectura
}

bool Parseando::Validez()
{
	return Archivo.fail();
}
bool Parseando::Buscador()
{
	while (std::getline(Archivo, Linea))//Busca donde se encuentre la palabra mesh
	{
		if (Linea.find(Palabra) != string::npos)//Encuentra la linea donde se ubica la palabra
		{
			std::getline(Archivo, Vertices, ';');//Obtiene los vertices que tiene el documento
			std::cout << Linea << endl;
			std::getline(Archivo, Linea);
			std::cout << "space para mostrar los vertices de uno en uno." << endl << "Enter para mostrar todos los vertices." << endl;
			std::cout << "Tu objeto tiene:" << Vertices << " vertices" << endl;
			return true;
		}
	}
	return false;
}

float Parseando::coordenadas()
{
	NVertices = atoi(Vertices.c_str());//Conversion de string a int
#ifdef use_vector
	vector<Coordenadas>XYZ;
#endif
	do
	{
		char j = _getch();
		switch (j)
		{
		case(' '):// Imprime de uno en uno
		{
			std::getline(Archivo, Linea);
			istringstream Lineaux(Linea);
			while (std::getline(Lineaux, Linea, ','))//Toma la fila n de las coordenadas del vertice n
			{
				istringstream Lineaux(Linea);//Extrae las coordenadas de los vertices
#ifdef use_malloc
				Coordenadas *XYZ = (Coordenadas*)malloc(sizeof(Coordenadas));
				std::getline(Lineaux, token, ';');
				XYZ->CoordenadaX = stof(token);
				std::getline(Lineaux, token, ';');
				XYZ->CoordenadaY = stof(token);
				std::getline(Lineaux, token, ';');
				XYZ->CoordenadaZ = stof(token);
				std::cout << "X: " << XYZ->CoordenadaX << "  Y: " << XYZ->CoordenadaY << "  Z:" << XYZ->CoordenadaZ << endl;
				free(XYZ);
#elif defined use_new
				Coordenadas *XYZ = new Coordenadas[1];
				std::getline(Lineaux, token, ';');
				XYZ->CoordenadaX = stof(token);
				std::getline(Lineaux, token, ';');
				XYZ->CoordenadaY = stof(token);
				std::getline(Lineaux, token, ';');
				XYZ->CoordenadaZ = stof(token);
				std::cout << "X: " << XYZ->CoordenadaX << "  Y: " << XYZ->CoordenadaY << "  Z:" << XYZ->CoordenadaZ << endl;
				delete[]XYZ;
#elif defined use_vector
				Coordenadas Vertice;
				std::getline(Lineaux, token, ';');
				Vertice.CoordenadaX = stof(token);
				std::getline(Lineaux, token, ';');
				Vertice.CoordenadaY = stof(token);
				std::getline(Lineaux, token, ';');
				Vertice.CoordenadaZ = stof(token);
				XYZ.push_back(Vertice);
				std::cout << "X: " << Vertice.CoordenadaX << "  Y: " << Vertice.CoordenadaY << "  Z:" << Vertice.CoordenadaZ << endl;
#endif
			}
			i++;
			break;
		}
		case(13)://Imprime todos los que faltan
		{
			while (i < NVertices)
			{
				std::getline(Archivo, Linea);
				istringstream Lineaux(Linea);
				while (std::getline(Lineaux, Linea, ','))
				{
					istringstream Lineaux(Linea);
#ifdef use_malloc
					Coordenadas *XYZ = (Coordenadas*)malloc(sizeof(Coordenadas));
					std::getline(Lineaux, token, ';');
					XYZ->CoordenadaX = stof(token);
					std::getline(Lineaux, token, ';');
					XYZ->CoordenadaY = stof(token);
					std::getline(Lineaux, token, ';');
					XYZ->CoordenadaZ = stof(token);
					std::cout << "X: " << XYZ->CoordenadaX << "  Y: " << XYZ->CoordenadaY << "  Z:" << XYZ->CoordenadaZ << endl;
					free(XYZ);
#elif defined use_new
					Coordenadas *XYZ = new Coordenadas[1];
					std::getline(Lineaux, token, ';');
					XYZ->CoordenadaX = stof(token);
					std::getline(Lineaux, token, ';');
					XYZ->CoordenadaY = stof(token);
					std::getline(Lineaux, token, ';');
					XYZ->CoordenadaZ = stof(token);
					std::cout << "X: " << XYZ->CoordenadaX << "  Y: " << XYZ->CoordenadaY << "  Z:" << XYZ->CoordenadaZ << endl;
					delete[]XYZ;
#elif defined use_vector
					Coordenadas Vertice;
					std::getline(Lineaux, token, ';');
					Vertice.CoordenadaX = stof(token);
					std::getline(Lineaux, token, ';');
					Vertice.CoordenadaY = stof(token);
					std::getline(Lineaux, token, ';');
					Vertice.CoordenadaZ = stof(token);
					XYZ.push_back(Vertice);
					std::cout << "X: " << Vertice.CoordenadaX << "  Y: " << Vertice.CoordenadaY << "  Z:" << Vertice.CoordenadaZ << endl;
#endif
				}
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

void Parseando::Cerrar()
{
	Archivo.close();
}
