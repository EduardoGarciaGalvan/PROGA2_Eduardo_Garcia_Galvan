// Parser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string Documento, Linea, Vertices, token;
	ifstream _Archivo;
	int nvertices = 0, i = 0;
	char *Palabra = "mesh";
	double coordenadaX, coordenadaY, coordenadaZ;
	cout << "Nota: Solo se podra abrir si esta en la misma carpeta donde se ubica el programa." << endl << "A menos que escriba la dirrecion del documento." << endl;
	cout << "Escriba el nombre o la ubicacion del archivo a abrir:" << endl;
	getline(cin, Documento);//Carga Documento o ubicacion del documento
	_Archivo.open(Documento.c_str(), ios::in);//Abre el archivo en modo lectura
	if (_Archivo.fail())//Error de archivo no encontrado
	{
		cout << "Documento inexistente" << endl;
	}
	else;
	while (getline(_Archivo, Linea))//Busca donde se encuentre la palabra mesh
	{
		if (Linea.find(Palabra) != string::npos)//Encuentra la linea donde se ubica la palabra
		{
			getline(_Archivo, Vertices, ';');//Obtiene los vertices que tiene el documento
			cout << Linea << endl;
			getline(_Archivo, Linea);
			cout << "space para mostrar los vertices de uno en uno." << endl << "Enter para mostrar todos los vertices." << endl;
			cout << "Tu objeto tiene:" << Vertices << " vertices" << endl;
			nvertices = atoi(Vertices.c_str());//Conversion de string a int
			do
			{
				char j = _getch();
				switch (j)
				{
				case(' '):// Imprime de uno en uno
				{
					getline(_Archivo, Linea);
					istringstream Lineaux(Linea);
					while (getline(Lineaux, Linea, ','))//Toma la fila n de las coordenadas del vertice n
					{
						istringstream Lineaux(Linea);//Extrae las coordenadas de los vertices
						getline(Lineaux, token, ';');
						coordenadaX = stof(token);
						getline(Lineaux, token, ';');
						coordenadaY = stof(token);
						getline(Lineaux, token, ';');
						coordenadaZ = stof(token);
					}
					cout << "X: " << coordenadaX << "  Y: " << coordenadaY << "  Z:" << coordenadaZ << endl;
					i++;
					break;
				}
				case(13)://Imprime todos los que faltan
				{
					while (i < nvertices)
					{
						getline(_Archivo, Linea);
						istringstream Lineaux(Linea);
						while (getline(Lineaux, Linea, ','))
						{
							istringstream Lineaux(Linea);
							getline(Lineaux, token, ';');
							coordenadaX = stof(token);
							getline(Lineaux, token, ';');
							coordenadaY = stof(token);
							getline(Lineaux, token, ';');
							coordenadaZ = stof(token);
						}
						cout << "X: " << coordenadaX << "  Y: " << coordenadaY << "  Z:" << coordenadaZ << endl;
						i++;
					}
					break;
				}
				default:
					break;
				}
			} while (i < nvertices);
		}
	}
	_Archivo.close();
	return 0;
}


