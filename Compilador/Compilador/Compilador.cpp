// Compilador.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Compresor.h"
#include "Descompresor.h"

int main()
{
	char opcion;
	std::string Nombre;
	Compresor Archivop2;
	Descompresor Archivotxt;
	std::cout << "Menu" << std::endl
		<< "1)Compilar Archivo .txt" << std::endl
		<< "2)Descompilar Archivo .p2" << std::endl
		<< "3)Salir" << std::endl;
	do {
	std::cin >> opcion;
	system("cls");
		std::cout << "Nota: Solo se podra abrir si esta en la misma carpeta donde se ubica el programa."
		<< std::endl << "A menos que escriba la dirrecion del documento." << std::endl;
		switch (opcion)
		{
		case 1:
			std::cout << "Escriba el nombre del documento a compilar:" << std::endl;
			getline(std::cin, Nombre);
			if (!Archivop2.Comprimir(Nombre)) {
				std::cout << "Su archivo ahora es .p2" << std::endl;
			}
			else {
				std::cout << "Archivo no encontrado" << std::endl;
			}
			break;
		case 2:
			std::cout << "Escriba el nombre del documento a descompilar:" << std::endl;
			getline(std::cin, Nombre);
			if (!Archivotxt.Descomprimir(Nombre)) {
				std::cout << "Su archivo ahora es .txt" << std::endl;
			}
			else {
				std::cout << "Archivo no encontrado" << std::endl;
			}
			break;
		default:
			if (opcion != '3')
				std::cout << "Comando no reconocido" << std::endl;
			break;
		}
	} while (opcion != 3);
    return 0;
}

