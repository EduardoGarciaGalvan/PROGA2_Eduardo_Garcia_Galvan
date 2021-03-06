// Examen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"
#include <stdlib.h>
#include <string>

int main()
{
	std::string Nombre, Comando, Texto;
	std::string Nombre2;
	int cd = 0;
	Lista Arbol;
	do {
		std::cout << "c:>";
		for (int i = 0; i < cd; i++)
		{
			std::cout << Nombre2 << ':';
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
			cd ++;
			Nombre2 = Nombre;
			system("cls");
		}
		else if (Comando == "cd..") {
			Arbol.RetrocederCarpeta();
			system("cls");
			cd --;
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

