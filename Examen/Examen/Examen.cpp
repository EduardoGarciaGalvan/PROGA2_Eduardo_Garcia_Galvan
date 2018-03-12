// Examen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"
#include <stdlib.h>
#include <string>

int main()
{
	std::string Nombre, Comando, Texto;
	Lista Arbol;
	do {
		std::cout << "c:>";
		if(Comando=="cd") {
			std::cout << Nombre;
		}
		std::cin >> Comando;
		if (Comando == "mkdir") {
			std::cin >> Nombre;
			Arbol.InsertarCarpeta(Nombre);
			system("cls");
		}
		else if (Comando == "rmdir") {
			std::cin >> Nombre;
			Arbol.BorrarCarpeta(Nombre);
			system("cls");
		}
		else if (Comando == "cd") {
			std::cin >> Nombre;
			Arbol.AccederCarpeta(Nombre);
			system("cls");
		}
		else if (Comando == "cd..") {
			Arbol.RetrocederCarpeta();
			system("cls");
		}
		else if (Comando == "dir") {
			Arbol.MostrarCarpetas();
		}
		else {
			std::cout << "Comando invalido" << std::endl;
		}
	} while (Comando != "Exit");
    return 0;
}

