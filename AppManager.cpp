#include "Menu.h"
#include "AppManager.h"
#include "PLayList.h"
#include "Artist.h"
#include "Album.h"
#include "Song.h"
#include "User.h"
#include "MusicalGenre.h"
#include<windows.h>
#include<iostream>
#pragma comment(lib, "Winmm.lib")
using namespace std;

void AppManager::LoadMusicData(){
	Menu::ClearMenu();

	//cout << "Inicio de Carga de Archivos \n" << endl;

	this->musicPlayer->InitStoreLoad();

	//cout << "Carga de Archivos Completada \n" << endl;
}

void AppManager::DataManager() {
	Menu::ClearMenu();

	Menu::DisplayDataMaintenanceMenu();

	string confirmData = "";

	do {
		getline(cin, confirmData);

		switch (confirmData[0])
		{
		case '1':
			//Insert
			ExecuteCommandByType(1);
			break;
		case '2':
			//Search
			ExecuteCommandByType(2);
			break;
		case '3':
			//Delete
			ExecuteCommandByType(3);
			break;
		case '4':
			//Update
			ExecuteCommandByType(4);
			break;
		default:
			confirmData = "";
		}

	} while (confirmData.length() != 0);
	Menu::ClearMenu();
	Menu::Displaymenu();
}

void AppManager::MusicPlayerManager(){
	Menu::ClearMenu();

	Menu::DisplayPlayerMenu();

	string confirmData = "";

	do {
		getline(cin, confirmData);

		switch (confirmData[0])
		{
		case '1':
			EnqueueMusic();
			break;
		case '2':
			PlaySongs();
			break;
		default:
			confirmData = "";
		}

	} while (confirmData.length() != 0);
	Menu::ClearMenu();
	Menu::Displaymenu();
}

void AppManager::ReportManager() {
	Menu::ClearMenu();

	Menu::DisplayReportMenu();

	string confirmData = "";

	do {
		getline(cin, confirmData);

		switch (confirmData[0])
		{
		case '1':
			DisplayUserList();
			break;
		case '2':
			DisplayUserPlayLists();
			break;
		case '3':
			SearchMusicalGenre();
			break;
		case '4':
			SearchArtist();
			break;
		case '5':
			DisplayAlbums();
			break;
		case '6':
			DisplaySongs();
			break;
		default:
			confirmData = "";
		}

	} while (confirmData.length() != 0);
	Menu::ClearMenu();
	Menu::Displaymenu();
}

void AppManager::ExecuteCommandByType(int type) {
	Menu::ClearMenu();

	Menu::DisplayDataTypeMenu();

	string confirmData = "";

	do {
		getline(cin, confirmData);

		switch (confirmData[0])
		{
		case '1':
			if (type == 1)
			{
				InsertUser();
			}
			else if (type == 2) {
				SearchUser();
			}
			else if (type == 3) {
				DeleteUser();
			}
			else if (type == 4) {
				UpdateUser();
			}
			break;
		case '2':
			if (type == 1)
			{
				InsertPlayList();
			}
			else if (type == 2) {
				SearchPlayList();
			}
			else if (type == 3) {
				DeletePlayList();
			}
			else if (type == 4) {
				UpdatePlayList();
			}
			break;
		case '3':
			if (type == 1)
			{
				InsertMusicalGenre();
			}
			else if (type == 2) {
				SearchMusicalGenre();
			}
			else if (type == 3) {
				DeleteMusicalGenre();
			}
			else if (type == 4) {
				UpdateMusicalGenre();
			}
			break;
		case '4':
			if (type == 1)
			{
				InsertArtist();
			}
			else if (type == 2) {
				SearchArtist();
			}
			else if (type == 3) {
				DeleteArtist();
			}
			else if (type == 4) {
				UpdateArtist();
			}
			break;
		case '5':
			if (type == 1)
			{
				InsertAlbum();
			}
			else if (type == 2) {
				SearchAlbum();
			}
			else if (type == 3) {
				DeleteAlbum();
			}
			else if (type == 4) {
				UpdateAlbum();
			}
			break;
		case '6':
			if (type == 1)
			{
				InsertSong();
			}
			else if (type == 2) {
				SearchSong();
			}
			else if (type == 3) {
				DeleteSong();
			}
			else if (type == 4) {
				UpdateSong();
			}
			break;
		default:
			confirmData = "";
		}

	} while (confirmData.length() != 0);
	Menu::ClearMenu();
	Menu::DisplayDataMaintenanceMenu();
}

/// <summary>
/// Inserts
/// </summary>

void AppManager::InsertUser() {

	string id = "";

	string name = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Propietario \nDigite un Id \n";
	getline(cin, id);
	cout << "Digite un Nombre \n";
	getline(cin, name);
	if (Menu::Is_NOT_EmptyOrWhiteSpace(name) &&
		Menu::Is_number(id) &&
		this->musicPlayer->getUsers()->GetElementIndexById(stoi(id)) == -1)
	{
		this->musicPlayer->getUsers()->Add(new Object(stoi(id), name));
		Menu::ClearMenu();
		this->musicPlayer->getUsers()->DisplayString();
		cout << "Usuario Insertado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertPlayList() {

	string id = "";

	string name = "";

	string userId = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo PlayList \nDigite un Id \n";
	getline(cin, id);
	cout << "Digite un Nombre \n";
	getline(cin, name);
	cout << "Digite el Id del Propietario \n";
	getline(cin, userId);
	
	if (Menu::Is_NOT_EmptyOrWhiteSpace(name) &&
		Menu::Is_number(id) &&
		Menu::Is_number(userId) &&
		this->musicPlayer->getPlayLists()->GetElementIndexById(stoi(id)) == -1 &&
		this->musicPlayer->getUsers()->GetElementIndexById(stoi(userId)) != -1)
	{
		PlayList* pl = new PlayList(stoi(id), name, stoi(userId));
		this->musicPlayer->getPlayLists()->Add(pl);
		Menu::ClearMenu();
		this->musicPlayer->getPlayLists()->DisplayString();
		cout << "Playlist Insertado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertMusicalGenre() {

	string id = "";

	string name = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Genero Musical \nDigite un Id \n";
	getline(cin, id);
	cout << "Digite un Nombre \n";
	getline(cin, name);
	if (Menu::Is_NOT_EmptyOrWhiteSpace(name) &&
		Menu::Is_number(id) &&
		this->musicPlayer->getMusicalGenres()->GetElementIndexById(stoi(id)) == -1)
	{
		this->musicPlayer->getMusicalGenres()->Add(new Object(stoi(id), name));
		Menu::ClearMenu();
		this->musicPlayer->getMusicalGenres()->DisplayString();
		cout << "Genero Musical Insertado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
	
}

void AppManager::InsertArtist() {

	string id = "";

	string name = "";

	string musicalGenreId = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Artista \nDigite un Id \n";
	getline(cin, id);
	cout << "Digite un Nombre \n";
	getline(cin, name);
	cout << "Digite el Id del Genero Musical Asociado \n";
	getline(cin, musicalGenreId);

	if (Menu::Is_NOT_EmptyOrWhiteSpace(name) &&
		Menu::Is_number(id) &&
		Menu::Is_number(musicalGenreId) &&
		this->musicPlayer->getArtists()->GetElementIndexById(stoi(id)) == -1 &&
		this->musicPlayer->getMusicalGenres()->GetElementIndexById(stoi(musicalGenreId)) != -1)
	{
		Artist* artist = new Artist(stoi(id), name, stoi(musicalGenreId));
		this->musicPlayer->getArtists()->Add(artist);
		Menu::ClearMenu();
		this->musicPlayer->getArtists()->DisplayString();
		cout << "Artista Insertado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertAlbum() {

	string id = "";

	string name = "";

	string artistId = "";

	Menu::ClearMenu();
	cout << "Insertar Nuevo Album \nDigite un Id \n";
	getline(cin, id);
	cout << "Digite un Nombre \n";
	getline(cin, name);
	cout << "Digite el Id del Artista Asociado \n";
	getline(cin, artistId);

	if (Menu::Is_NOT_EmptyOrWhiteSpace(name) &&
		Menu::Is_number(id) &&
		Menu::Is_number(artistId) &&
		this->musicPlayer->getArtists()->GetElementIndexById(stoi(artistId)) != -1 &&
		this->musicPlayer->getAlbums()->GetElementIndexById(stoi(id)) == -1)
	{
		Album* album = new Album(stoi(id), name, stoi(artistId));
		this->musicPlayer->getAlbums()->Add(album);
		Menu::ClearMenu();
		this->musicPlayer->getAlbums()->DisplayString();
		cout << "Album Insertado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::InsertSong() {
	string id = "";

	string name = "";

	string artistId = "";

	string musicalGenreId = "";

	string albumId = "";

	string playListId = "";

	Menu::ClearMenu();
	cout << "Insertar Nueva Cancion \nDigite un Id \n";
	getline(cin, id);
	cout << "Digite un Nombre \n";
	getline(cin, name);
	cout << "Digite el Id del Artista Asociado \n";
	getline(cin, artistId);
	cout << "Digite el Id del Album Asociado \n";
	getline(cin, albumId);
	cout << "Digite el Id del Genero Musical Asociado \n";
	getline(cin, musicalGenreId);
	cout << "Digite el Id del PlayList Asociado \n";
	getline(cin, playListId);

	if (Menu::Is_NOT_EmptyOrWhiteSpace(name) &&
		Menu::Is_number(id) &&
		Menu::Is_number(artistId) &&
		Menu::Is_number(albumId) &&
		Menu::Is_number(musicalGenreId) &&
		Menu::Is_number(playListId)
		)
	{
		int existsArtist = this->musicPlayer->getArtists()->GetElementIndexById(stoi(artistId));
		int existsAlbum = this->musicPlayer->getAlbums()->GetElementIndexById(stoi(albumId));
		int existsMusicalGenre = this->musicPlayer->getMusicalGenres()->GetElementIndexById(stoi(musicalGenreId));
		int existsPlayList = this->musicPlayer->getPlayLists()->GetElementIndexById(stoi(playListId));
		int isNotDuplicated = this->musicPlayer->getSongs()->GetElementIndexById(stoi(id));

		if (existsArtist != -1 &&
			existsAlbum != -1 &&
			existsMusicalGenre != -1 &&
			existsPlayList != -1 &&
			isNotDuplicated == -1)
		{
			Song* song = new Song(stoi(id), name, stoi(artistId), stoi(albumId), stoi(musicalGenreId), stoi(playListId));
			this->musicPlayer->getSongs()->Add(song);
			Menu::ClearMenu();
			this->musicPlayer->getSongs()->DisplayString();
			cout << "Cancion Insertada Correctamente\n \n";
		}
		else {
			cout << "Alguno de los id existe o no es correcto \n";
		}
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

/// <summary>
/// Seacrh
/// </summary>

void AppManager::SearchUser(){
	Menu::ClearMenu();
	string id = "";
	cout << "Digite un Id para buscar en la Lista de propietarios\n";
	getline(cin, id);

	if (Menu::Is_number(id))
	{
		this->musicPlayer->getUsers()->DisplayElementById(stoi(id));
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchPlayList() {
	Menu::ClearMenu();
	string id = "";
	cout << "Digite un Id del Playlist para buscar en los PlayList\n";
	getline(cin, id);

	if (Menu::Is_number(id))
	{
		PlayList* p = static_cast<PlayList*>(this->musicPlayer->getPlayLists()->GetElementByKeyId(stoi(id),"playListSearchReport"));

		cout << "PlayList Id " << p->getId() << " " << p->getName() << " \n Pertenese al usuario: \n" ;
		this->musicPlayer->getUsers()->DisplayElementById(p->getUserId());
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchMusicalGenre() {
	Menu::ClearMenu();
	string id = "";
	cout << "Digite un Id para buscar Genero Musical\n";
	getline(cin, id);

	if (Menu::Is_number(id))
	{
		this->musicPlayer->getMusicalGenres()->DisplayElementById(stoi(id));
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchArtist() {
	Menu::ClearMenu();
	string id = "";
	cout << "Digite un Id de un Genero Musical para buscar el Artista \n";
	getline(cin, id);

	if (Menu::Is_number(id))
	{
		MusicalGenre* m = static_cast<MusicalGenre*>(this->musicPlayer->getMusicalGenres()->GetElementByKeyId(stoi(id),"musicalGenre"));
		
		Artist* artist = static_cast<Artist*>(this->musicPlayer->getArtists()->GetElementByKeyId(m->getId(), "artist"));
		
		if (artist != NULL)
		{
			cout << "Artist Id " << artist->getId() << " " << artist->getName() << " \n Pertenese al Genero: \n" << m->getName() << "\n";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\n Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchAlbum() {
	Menu::ClearMenu();
	string id = "";
	cout << "Digite un Id de un Genero Musical para buscar el Artista y el Album \n";
	getline(cin, id);

	if (Menu::Is_number(id))
	{
		MusicalGenre* m = static_cast<MusicalGenre*>(this->musicPlayer->getMusicalGenres()->GetElementByKeyId(stoi(id), "musicalGenre"));

		Artist* artist = static_cast<Artist*>(this->musicPlayer->getArtists()->GetElementByKeyId(m->getId(), "artist"));

		if (artist != NULL)
		{
			Album* album = static_cast<Album*>(this->musicPlayer->getAlbums()->GetElementByKeyId(artist->getId(), "album"));
			cout << "Album Id " << album->getId() << " " << album->getName() << " \n Pertenese al Genero: \n" << m->getName() << "\n";
			cout << "Y al artista " << artist->getName();
		}
		else {
			cout << "No se encontro el album con el genero y artista";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\n Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::SearchSong() {
	Menu::ClearMenu();
	string id = "";
	cout << "Digite un Id de un Genero Musical para buscar el Artista y el Album y playlist de una cancion\n";
	getline(cin, id);

	if (Menu::Is_number(id))
	{
		MusicalGenre* m = static_cast<MusicalGenre*>(this->musicPlayer->getMusicalGenres()->GetElementByKeyId(stoi(id), "musicalGenre"));

		Artist* artist = static_cast<Artist*>(this->musicPlayer->getArtists()->GetElementByKeyId(m->getId(), "artist"));

		if (artist != NULL)
		{
			Album* album = static_cast<Album*>(this->musicPlayer->getAlbums()->GetElementByKeyId(artist->getId(), "album"));

			string playListId = "";
			cout << "Digite un Id de un PlayList de una cancion\n";
			getline(cin, playListId);
			PlayList* p = static_cast<PlayList*>(this->musicPlayer->getPlayLists()->GetElementByKeyId(stoi(playListId), "playList"));
			if (p != NULL) {
				
				Song* s = static_cast<Song*>(this->musicPlayer->getSongs()->GetElementByKeyId(p->getId(), "song"));

				if (s!= NULL)
				{
					cout << "Album Id " << album->getId() << " " << album->getName() << " \n Pertenese al Genero: \n" << m->getName() << "\n";
					cout << "Y al artista " << artist->getName() << "\n" ;
					cout << "Y el play list  " << p->getName() << " " << " del propietario " << "\n";
					this->musicPlayer->getUsers()->DisplayElementById(p->getUserId());
					cout << "La cancion es " << s->getName();

				}
			}
		

		}
		else {
			cout << "No se encontro el album con el genero y artista";
		}
	}
	else {
		cout << "El id existe o no es correcto \n";
	}
	cout << "\n Presione Enter para Volver al Menu Anterior \n";
}

/// <summary>
/// Delete
/// </summary>

void AppManager::DeleteUser() {

	string userId = "";

	Menu::ClearMenu();
	cout << "Eliminar Propietario \nDigite un Id \n";
	getline(cin, userId);
	Menu::ClearMenu();
	cout << "Eliminar Propietario \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(userId) &&
		this->musicPlayer->getUsers()->GetElementIndexById(stoi(userId)) != -1) // User Exists
	{
		//while finding playlist associated to user
		while (this->musicPlayer->getPlayLists()->GetElementByKeyId(stoi(userId),"playList") != NULL) {

			//Get each playlist
			PlayList* p = static_cast<PlayList*>(this->musicPlayer->getPlayLists()->GetElementByKeyId(stoi(userId), "playList"));

			cout << "\tEliminando PlayLists -> " << p->getName() << " \n";
			cout << "\n ------------------------------------------ \n";
			// Check all playlist associated with user found
			while ( this->musicPlayer->getPlayLists()->GetElementIndexById(p->getId()) != -1) {

				
				while (this->musicPlayer->getSongs()->GetElementByKeyId(p->getId(), "song") != NULL) {

					cout << "\t\tEliminando la Cancion -> " << this->musicPlayer->getSongs()->GetElementByKeyId(p->getId(), "song")->getName() << "\n \n";
					this->musicPlayer->getSongs()->RemoveElementAtIndex(
						this->musicPlayer->getSongs()->GetElementIndexById(this->musicPlayer->getSongs()->GetElementByKeyId(p->getId(), "song")->getId())
					);
					cout << "\t\tCancion Eliminada Correctamente\n";
					cout << "\n ------------------------------------------ \n";
				}
				this->musicPlayer->getPlayLists()->RemoveElementAtIndex(this->musicPlayer->getPlayLists()->GetElementIndexById(p->getId()));
				
			}
			cout << "\tPlayList Eliminada Correctamente\n";
			cout << "\n ------------------------------------------ \n";
		}
		this->musicPlayer->getUsers()->RemoveElementAtIndex(this->musicPlayer->getUsers()->GetElementIndexById(stoi(userId)));
		cout << "Propietario Eliminado Correctamente\n";
		cout << "\n ------------------------------------------ \n";
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::DeletePlayList() {

	string id = "";

	string name = "";

	string userId = "";

	Menu::ClearMenu();
	cout << "Eliminar PlayList \nDigite un Id \n";
	getline(cin, id);
	Menu::ClearMenu();
	cout << "Eliminar PlayList \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(id) &&
		Menu::Is_number(userId) &&
		this->musicPlayer->getPlayLists()->GetElementIndexById(stoi(id)) != -1 )// PlayLists exists
	{
		while (this->musicPlayer->getPlayLists()->GetElementByKeyId(stoi(userId), "playList") != NULL) {

			//Get each playlist
			PlayList* p = static_cast<PlayList*>(this->musicPlayer->getPlayLists()->GetElementByKeyId(stoi(userId), "playList"));

			// Check all playlist associated with user found
			if (p->getId() == stoi(id) && p->getUserId() == stoi(userId)) {


				cout << "\tEliminando PlayLists -> " << p->getName() << " \n";
				cout << "\n ------------------------------------------ \n";
				while (this->musicPlayer->getSongs()->GetElementByKeyId(p->getId(), "song") != NULL) {

					cout << "\t\tEliminando la Cancion -> " << this->musicPlayer->getSongs()->GetElementByKeyId(p->getId(), "song")->getName() << "\n \n";
					this->musicPlayer->getSongs()->RemoveElementAtIndex(
						this->musicPlayer->getSongs()->GetElementIndexById(this->musicPlayer->getSongs()->GetElementByKeyId(p->getId(), "song")->getId())
					);
					cout << "\t\tCancion Eliminada Correctamente\n";
					cout << "\n ------------------------------------------ \n";
				}
				this->musicPlayer->getPlayLists()->RemoveElementAtIndex(this->musicPlayer->getPlayLists()->GetElementIndexById(p->getId()));

				cout << "\tPlayList Eliminada Correctamente\n";
				cout << "\n ------------------------------------------ \n";
			}
		}
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::DeleteMusicalGenre() {

	string id = "";

	Menu::ClearMenu();
	cout << "Eliminar Genero Musical \nDigite un Id \n";
	getline(cin, id);

	Menu::ClearMenu();
	cout << "Eliminar Genero Musical \n";
	cout << "\n ------------------------------------------ \n";
	if (
		Menu::Is_number(id) &&
		this->musicPlayer->getMusicalGenres()->GetElementIndexById(stoi(id)) != -1)
	{

		while (static_cast<Artist*>(this->musicPlayer->getArtists()->GetElementByKeyId(stoi(id), "artist")) != NULL)
		{
			Artist* a = static_cast<Artist*>(this->musicPlayer->getArtists()->GetElementByKeyId(stoi(id), "artist"));
			
			Album* album = static_cast<Album*>(this->musicPlayer->getAlbums()->GetElementByKeyId(a->getId(), "album"));
			if (album != NULL)
			{
				Song* song = static_cast<Song*>(this->musicPlayer->getSongs()->GetElementByKeyId(album->getId(), "songAlbum"));
				if (song != NULL) {

					cout << "Eliminando la Cancion -> " << song->getName() << "\n \n";
					this->musicPlayer->getSongs()->RemoveElementAtIndex(this->musicPlayer->getSongs()->GetElementIndexById(song->getId()));
					cout << "Cancion Eliminada Correctamente\n";
					cout << "\n ------------------------------------------ \n";
				}
				this->musicPlayer->getAlbums()->RemoveElementAtIndex(
					this->musicPlayer->getAlbums()->GetElementIndexById(album->getId())
				);
			}
			cout << "Eliminando la Artista -> " << a->getName() << "\n \n";
			this->musicPlayer->getArtists()->RemoveElementAtIndex(this->musicPlayer->getArtists()->GetElementIndexById(a->getId()));
			cout << "Artista Eliminado Correctamente\n \n";
		}

		cout << "\n ------------------------------------------ \n";

		cout << "Eliminando Genero Musical -> " <<this->musicPlayer->getMusicalGenres()->GetElementByKeyId(stoi(id),"musicalGenre")->getName() << "\n \n";

		this->musicPlayer->getMusicalGenres()->RemoveElementAtIndex(this->musicPlayer->getMusicalGenres()->GetElementIndexById(stoi(id)));
		
		cout << "Genero Musical Eliminado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";

}

void AppManager::DeleteArtist() {

	string id = "";

	Menu::ClearMenu();
	cout << "Eliminar Artista \nDigite un Id \n";
	getline(cin, id);

	if (
		Menu::Is_number(id) &&
		this->musicPlayer->getArtists()->GetElementIndexById(stoi(id)) != -1 ) //Artist exists
	{
		Artist* a = static_cast<Artist*>(this->musicPlayer->getArtists()->GetElementByKeyId(stoi(id), "artist"));
		if (a!= NULL)
		{
			this->musicPlayer->getArtists()->RemoveElementAtIndex(this->musicPlayer->getArtists()->GetElementIndexById(stoi(id)));
			Album* album = static_cast<Album*>(this->musicPlayer->getAlbums()->GetElementByKeyId(a->getId(), "album"));
			if (album != NULL)
			{
				Song* song = static_cast<Song*>(this->musicPlayer->getSongs()->GetElementByKeyId(album->getId(), "songAlbum"));
				if (song != NULL) {

					cout << "Eliminando la Cancion -> " << song->getName() << "\n \n";
					this->musicPlayer->getSongs()->RemoveElementAtIndex(this->musicPlayer->getSongs()->GetElementIndexById(song->getId()));
					cout << "Cancion Eliminada Correctamente\n";
					cout << "\n ------------------------------------------ \n";
				}
				this->musicPlayer->getAlbums()->RemoveElementAtIndex(
					this->musicPlayer->getAlbums()->GetElementIndexById(album->getId())
				);
			}
			
		}
		
		cout << "Artista Eliminado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::DeleteAlbum() {

	string id = "";

	Menu::ClearMenu();
	cout << "Eliminar Album \nDigite un Id \n";
	getline(cin, id);
	Menu::ClearMenu();
	cout << "Eliminar Album\n\n";
	if (
		Menu::Is_number(id)&&
		this->musicPlayer->getAlbums()->GetElementIndexById(stoi(id)) != -1) // Album Exists
	{
		int albumIndex = this->musicPlayer->getAlbums()->GetElementIndexById(stoi(id));
		Album* album = static_cast<Album*>(this->musicPlayer->getAlbums()->GetElementByKeyId(albumIndex,"album"));
		Song* song = static_cast<Song*>(this->musicPlayer->getSongs()->GetElementByKeyId(album->getId(), "songAlbum"));
		if ( song != NULL) {

			cout << "Eliminando la Cancion -> " << song->getName() << "\n \n";
			this->musicPlayer->getSongs()->RemoveElementAtIndex(this->musicPlayer->getSongs()->GetElementIndexById(song->getId()));
			cout << "Cancion Eliminada Correctamente\n";
			cout << "\n ------------------------------------------ \n";
		}
		this->musicPlayer->getAlbums()->RemoveElementAtIndex(albumIndex);
		cout << "Album Eliminado Correctamente\n \n";
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

void AppManager::DeleteSong() {

	string songId = "";

	Menu::ClearMenu();
	cout << "Eliminar Cancion \nDigite un Id \n";
	getline(cin, songId);

	if (Menu::Is_number(songId)	)
	{
		if (this->musicPlayer->getSongs()->GetElementIndexById(stoi(songId)) != -1) {
			cout << "Eliminando la Cancion -> " << this->musicPlayer->getSongs()->GetElementByKeyId(stoi(songId), "song")->getName() << "\n \n";
			this->musicPlayer->getSongs()->RemoveElementAtIndex(
				this->musicPlayer->getSongs()->GetElementIndexById(this->musicPlayer->getSongs()->GetElementByKeyId(stoi(songId), "song")->getId())
			);
			cout << "Cancion Eliminada Correctamente\n";
			cout << "\n ------------------------------------------ \n";
		}
	}
	else {
		cout << "El nombre esta vacio o alguno de los id existe o no es correcto \n";
	}

	cout << "Presione Enter para Volver al Menu Anterior \n";
}

/// <summary>
/// Update
/// </summary>

void AppManager::UpdateUser() {
	string userId = "";
	string name = "";
	Menu::ClearMenu();
	cout << "Modificar Propietario \nDigite un Id \n";
	getline(cin, userId);
	cout << "Digite el Nuevo Nombre \n";
	getline(cin, name);
	Menu::ClearMenu();
	cout << "Modificar Nombre Propietario \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(userId) &&
		this->musicPlayer->getUsers()->GetElementIndexById(stoi(userId)) != -1) 
	{
		this->musicPlayer->getUsers()->SetElementValueById(stoi(userId), name);

		cout << "El nuevo nombre del Propietario es : -> ";
		this->musicPlayer->getUsers()->DisplayElementById(stoi(userId));
	}
}

void AppManager::UpdatePlayList() {
	string playListId = "";
	string name = "";
	Menu::ClearMenu();
	cout << "Modificar PlayList \nDigite un Id \n";
	getline(cin, playListId);
	cout << "Digite el Nuevo Nombre \n";
	getline(cin, name);
	Menu::ClearMenu();
	cout << "Modificar Nombre PlayList \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(playListId) &&
		this->musicPlayer->getPlayLists()->GetElementIndexById(stoi(playListId)) != -1) 
	{
		this->musicPlayer->getPlayLists()->SetElementValueById(stoi(playListId), name);

		cout << "El nuevo nombre del Playlist es : -> ";
		this->musicPlayer->getPlayLists()->DisplayElementById(stoi(playListId));
	}
}

void AppManager::UpdateMusicalGenre() {
	string musicalGenreId = "";
	string name = "";
	Menu::ClearMenu();
	cout << "Modificar Genero Musical \nDigite un Id \n";
	getline(cin, musicalGenreId);
	cout << "Digite el Nuevo Nombre \n";
	getline(cin, name);
	Menu::ClearMenu();
	cout << "Modificar Nombre Genero Musical \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(musicalGenreId) &&
		this->musicPlayer->getMusicalGenres()->GetElementIndexById(stoi(musicalGenreId)) != -1)
	{
		this->musicPlayer->getMusicalGenres()->SetElementValueById(stoi(musicalGenreId), name);

		cout << "El nuevo nombre del Genero Musical es : -> ";
		this->musicPlayer->getMusicalGenres()->DisplayElementById(stoi(musicalGenreId));
	}
}

void AppManager::UpdateArtist() {
	string artistId = "";
	string name = "";
	Menu::ClearMenu();
	cout << "Modificar Artista \nDigite un Id \n";
	getline(cin, artistId);
	cout << "Digite el Nuevo Nombre \n";
	getline(cin, name);
	Menu::ClearMenu();
	cout << "Modificar Nombre Artista \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(artistId) &&
		this->musicPlayer->getArtists()->GetElementIndexById(stoi(artistId)) != -1)
	{
		this->musicPlayer->getArtists()->SetElementValueById(stoi(artistId), name);

		cout << "El nuevo nombre del Artista es : -> ";
		this->musicPlayer->getArtists()->DisplayElementById(stoi(artistId));
	}
}

void AppManager::UpdateAlbum() {
	string albumId = "";
	string name = "";
	Menu::ClearMenu();
	cout << "Modificar Album \nDigite un Id \n";
	getline(cin, albumId);
	cout << "Digite el Nuevo Nombre \n";
	getline(cin, name);
	Menu::ClearMenu();
	cout << "Modificar Nombre Album \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(albumId) &&
		this->musicPlayer->getAlbums()->GetElementIndexById(stoi(albumId)) != -1) 
	{
		this->musicPlayer->getAlbums()->SetElementValueById(stoi(albumId), name);

		cout << "El nuevo nombre del Album es : -> ";
		this->musicPlayer->getAlbums()->DisplayElementById(stoi(albumId));
	}
}

void AppManager::UpdateSong() {
	string songId = "";
	string name = "";
	Menu::ClearMenu();
	cout << "Modificar Cancion \nDigite un Id \n";
	getline(cin, songId);
	cout << "Digite el Nuevo Nombre \n";
	getline(cin, name);
	Menu::ClearMenu();
	cout << "Modificar Nombre Cancion \n";
	cout << "\n ------------------------------------------ \n";
	if (Menu::Is_number(songId) &&
		this->musicPlayer->getAlbums()->GetElementIndexById(stoi(songId)) != -1)
	{
		this->musicPlayer->getAlbums()->SetElementValueById(stoi(songId), name);

		cout << "El nuevo nombre del Cancion es : -> ";
		this->musicPlayer->getAlbums()->DisplayElementById(stoi(songId));
	}
}

/// <summary>
/// Enqueue Music
/// </summary>
void AppManager::EnqueueMusic() {
	Menu::ClearMenu();
	string userId = "";
	string playListId = "";
	string musicalGenreId = "";
	string artistId = "";
	string albumId = "";
	string songId = "";
	string confirm = "";

	
	int currentQueueIndex = this->musicQueue->Length();
	int maxLength = 5;

	do {
		Menu::ClearMenu();
		cout << "Digite el Id del Propietario \n";
		getline(cin, userId);
		cout << "Digite el Id del PlayList \n";
		getline(cin, playListId);
		cout << "Digite el Id del Genero Musical \n";
		getline(cin, musicalGenreId);
		cout << "Digite el Id del Artista \n";
		getline(cin, artistId);
		cout << "Digite el Id del Album \n";
		getline(cin, albumId);
		cout << "Digite el Id del Cancion \n";
		getline(cin, songId);

		if (Menu::Is_number(userId) &&
			Menu::Is_number(playListId) &&
			Menu::Is_number(musicalGenreId) &&
			Menu::Is_number(artistId) &&
			Menu::Is_number(albumId) &&
			Menu::Is_number(songId)
			)
		{

			int existsUser = this->musicPlayer->getUsers()->GetElementIndexById(stoi(userId));
			int existsArtist = this->musicPlayer->getArtists()->GetElementIndexById(stoi(artistId));
			int existsAlbum = this->musicPlayer->getAlbums()->GetElementIndexById(stoi(albumId));
			int existsMusicalGenre = this->musicPlayer->getMusicalGenres()->GetElementIndexById(stoi(musicalGenreId));
			int existsPlayList = this->musicPlayer->getPlayLists()->GetElementIndexById(stoi(playListId));
			Song* song = static_cast<Song*> (this->musicPlayer->getSongs()->GetElementByKeyIdPlayer(stoi(playListId), stoi(songId)));

			if (existsUser != -1 &&
				existsArtist != -1 &&
				existsAlbum != -1 &&
				existsPlayList != -1 &&
				existsMusicalGenre != -1 &&
				song != NULL)
			{
				User* user = static_cast<User*> (this->musicPlayer->getUsers()->GetElementByKeyId(stoi(userId), "user"));
				PlayList* playList = static_cast<PlayList*> (this->musicPlayer->getPlayLists()->GetElementByKeyId(stoi(playListId), "playListSearchReport"));
				
					string info = user->getName() + " " + playList->getName();
					if (this->musicQueue->GetElementAt(currentQueueIndex) == NULL)
					{
						this->musicQueue->Enqueue(song->getName(), info);
					}
					else {
						this->musicQueue->GetElementAt(currentQueueIndex)->getList()->Add(song->getName(), info);
					}
					

					cout << "\nCancion " << song->getName() <<" Agregada en PlayList \n";
				
			}
			else {
				cout << "\nNo Existe cancion con la informacion proveida \n";
			}
			maxLength++;
		}
		else {
			cout << "Algun Id no es valido\n\n";
		}

		cout << "Desea Agregar otra cancion ? Presione Y\n";
		getline(cin, confirm);
		if (confirm == "Y" || confirm == "y")
		{
			confirm = " ";
		}
		else {
			confirm = "";
			cout << "\nPresione Enter para Volver al Menu Anterior \n";
			break;
		}
	} while (confirm.length() != 0 && maxLength != 5);
	
}

void AppManager::PlaySongs() {
	Menu::ClearMenu();
	cout << "Inicia Lista de Reproduccion\n\n";

	int n = 0;
	QueueNode* node = this->musicQueue->GetElementAt(n);
	if (node == NULL)
	{
		cout << "\nNO hay Canciones a reproducir\n";
	}
	while (n != this->musicQueue->Length()) {
		node = this->musicQueue->GetElementAt(n);
		if (node != NULL)
		{
			List* playList = node->getList();
			if (playList != NULL)
			{
				while (playList->Length() != 0) {

					PointerNode element = playList->RemoveElement();
					if (element != NULL)
					{
						cout << "------------------------------------" << "\n\n";
						string path = "C:/" + element->getCharValue() + ".wav";
						cout << element->getSongInfo() << "\n\n";
						cout << path << "\n\n";
						PlaySound((path.c_str()), NULL, SND_SYNC);
					}

				}
			}
			
		}
		
		n++;
	} ;
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}
/// <summary>
/// Reports
/// </summary>

void AppManager::DisplayUserList(){
	Menu::ClearMenu();
	cout << "Todos los Propietarios \n \n";
	this->musicPlayer->getUsers()->DisplayString();
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::DisplayUserPlayLists() {
	Menu::ClearMenu();
	string userId = "";
	cout << "Digite un Id de Propietario para buscar en los PlayList\n";
	getline(cin, userId);
	Menu::ClearMenu();
	if (Menu::Is_number(userId))
	{
		this->musicPlayer->getPlayLists()->DisplayElementByFieldTypeId(stoi(userId), "userId");
		cout << "\nPertenese al usuario: \n";
		this->musicPlayer->getUsers()->DisplayElementById(stoi(userId));
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::DisplayAlbums() {
	Menu::ClearMenu();
	string artistId = "";
	cout << "Digite un Id de Artista para ver todos los albumns\n";
	getline(cin, artistId);
	Menu::ClearMenu();
	if (Menu::Is_number(artistId))
	{
		cout << "\nLos albumes que pertenesen al artista: \n";
		this->musicPlayer->getAlbums()->DisplayElementByFieldTypeId(stoi(artistId), "album");
		cout << "\nPertenese al artista: \n";
		this->musicPlayer->getArtists()->DisplayElementById(stoi(artistId));
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}

void AppManager::DisplaySongs() {
	Menu::ClearMenu();
	string artistId = "";
	cout << "Digite un Id de Artista para ver todas las Canciones\n";
	getline(cin, artistId);
	Menu::ClearMenu();
	if (Menu::Is_number(artistId))
	{
		cout << "\nEl artista: \n \n";
		this->musicPlayer->getArtists()->DisplayElementById(stoi(artistId));

		cout << "\nLas canciones que pertenesen al artista: \n \n";
		this->musicPlayer->getSongs()->DisplayElementByFieldTypeId( stoi(artistId), "artist");
	}
	else {
		cout << "El nombre esta vacio o el id existe o no es correcto \n";
	}
	cout << "\nPresione Enter para Volver al Menu Anterior \n";
}
