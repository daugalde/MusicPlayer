#pragma once
#include <iostream>
#include <regex>

using namespace std;

class Menu {

public:

	Menu() {}

	static void Displaymenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\tMENU \n ";
		cout << "===================================================== \n";
		cout << " 1.Mantenimiento Base de Datos\n";
		cout << " 2.Reproducir\n";
		cout << " 3.Reportes \n";
		cout << " 4.Salir \n";
	}

	static void DisplayDataMaintenanceMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Mantenimiento Base de Datos \n ";
		cout << "===================================================== \n";
		cout << " 1.Insertar\n";
		cout << " 2.Buscar\n";
		cout << " 3.Eliminar\n";
		cout << " 4.Modificar\n";
		cout << " 5.Volver al Menu Principal \n";
	}

	static void DisplayDataTypeMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Mantenimiento Base de Datos \n ";
		cout << "===================================================== \n";
		cout << " 1.Propietario\n";
		cout << " 2.PlayList\n";
		cout << " 3.Genero\n";
		cout << " 4.Artista\n";
		cout << " 5.Album\n";
		cout << " 6.Cancion\n";
		cout << " 7.Volver al Menu Anterior \n";
	}

	static void DisplayPlayerMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Reproductor \n ";
		cout << "===================================================== \n";
		cout << " 1.Generar PlayList Para Reproducir\n";
		cout << " 2.Reproducir PlayList En la Cola\n";
		cout << " 3.Volver al Menu Anterior \n";
	}

	static void DisplayReportMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Reportes de Reproductor \n ";
		cout << "===================================================== \n";
		cout << " 1.Propietarios\n";
		cout << " 2.Playlist\n";
		cout << " 3.Genero\n";
		cout << " 4.Artistas de un genero \n";
		cout << " 5.Album \n";
		cout << " 6.Canciones \n";
		cout << " 7.Volver al Menu Principal \n";
	}

	static void DisplayPlayerReportMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Reportes de Reproductor \n ";
		cout << "===================================================== \n";
		cout << " 1.Cancion Mas Reproducida\n";
		cout << " 2.Artista con mas canciones\n";
		cout << " 3.Album con mas canciones\n";
		cout << " 4.Genero Mas Solicitado \n";
		cout << " 5.Propietario Con Mas PlayList \n";
		cout << " 6.Album mas solicitado \n";
		cout << " 7.Volver al Menu Principal \n";
	}

	static void ClearMenu() {
		cout << flush;
		system("CLS");
	}

	bool static Is_number(const std::string& s)
	{
		return !s.empty() && std::find_if(s.begin(),
			s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
	}

	bool static Is_NOT_EmptyOrWhiteSpace(const std::string& s)
	{
		return !s.empty() && !(s.find_first_not_of(' ') == s.npos);
	}

	std::string ltrim(const std::string& s) {
		return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
	}

	std::string rtrim(const std::string& s) {
		return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
	}

	std::string trim(const std::string& s) {
		return ltrim(rtrim(s));
	}
};
