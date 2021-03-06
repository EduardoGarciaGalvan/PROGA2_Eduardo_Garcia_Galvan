// CParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CVertices.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

#include <Library.h>

int main()
{
	HelperPrint();

	string _Documento;
	cout << "Nota: Solo se podra abrir si esta en la misma carpeta donde se ubica el programa." << endl << "A menos que escriba la dirrecion del documento." << endl;
	cout << "Escriba el nombre del documento a abrir:" << endl;
	getline(cin, _Documento);//Carga Documento o ubicacion del documento
	CVertices Texto = _Documento;
	Texto.Carga();
	if (Texto.Validez())
	{
		cout << "Documento inexistente" << endl;
	}
	else
	{
		if (Texto.Buscador())
		{
			Texto.coordenadas();
		}
	}
	Texto.Cerrar();
    return 0;
}

