// TestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Parser.h>
using namespace std;

int main()
{
	Parser Parseador("NuCroc.X");
	Parseador.Carga();
	if (Parseador.Validez())
	{
		cout << "Documento inexistente" << endl;
	}
	else
	{
		if (Parseador.Buscador())
		{
			Parseador.coordenadas();
		}
	}
	Parseador.Cerrar();
    return 0;
}

