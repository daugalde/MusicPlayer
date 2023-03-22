#include <fstream>
#include <iostream>
#include <string>
#include "FileLoader.h"
#include "User.h"
#include "PlayList.h"
#include "Artist.h"
#include "MusicalGenre.h"
#include "Album.h"
#include "Song.h"
#include "CircularDoublyList.h"

using namespace std;

FileLoader::~FileLoader()
{

}

CircularDoublyList* FileLoader::ReadAndLoadUserFile() {

	CircularDoublyList* userList = new CircularDoublyList();

	string str;

	ifstream file("Propietario.txt");

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {
			User* user = new User();

			string delim = ";";

			size_t pos = 0;

			string token;

			while ((pos = str.find(delim)) != string::npos)
			{
				token = str.substr(0, pos);

				user->setId(stoi(token));

				str.erase(0, pos + delim.length());

			}

			user->setName(str);

			if (userList->GetElementIndexById( user->getId()) == -1)
			{
				userList->Add(user);
			}
		}
	}

	//userList->DisplayString();

	return userList;
}

CircularDoublyList* FileLoader::ReadAndLoadPlayListFile(CircularDoublyList& userList) {

	CircularDoublyList* playLists = new CircularDoublyList();

	string str;

	ifstream file("Playlist.txt");

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			PlayList* playlist = new PlayList();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 2)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					playlist->setId(stoi(token));
				}
				else if (count == 1)
				{
					playlist->setName(token);
				}
				else if (count == 2)
				{
					playlist->setUserId(stoi(token));
				}

				str.erase(0, pos + delim.length());

				count++;
			}
			int existsUser = userList.GetElementIndexById(playlist->getUserId());
			int isNotDuplicatedPlayList = playLists->GetElementIndexById( playlist->getId());

			if (existsUser != -1 &&  isNotDuplicatedPlayList == -1)
			{
				playLists->Add(playlist);
			}

		}
	}
	//playLists->DisplayString();
	return playLists;
}

CircularDoublyList* FileLoader::ReadAndLoadMusicalGenreFile() {

	CircularDoublyList* musicalGenreList = new CircularDoublyList();

	string str;

	ifstream file("Genero.txt");

	while (!file.eof()) {

		getline(file, str);

		if (str != "") {
			MusicalGenre* musicalGenre = new MusicalGenre();

			string delim = ";";

			size_t pos = 0;

			string token;

			while ((pos = str.find(delim)) != string::npos)
			{
				token = str.substr(0, pos);

				musicalGenre->setId(stoi(token));

				str.erase(0, pos + delim.length());

			}

			musicalGenre->setName(str);

			if (musicalGenreList->GetElementIndexById(musicalGenre->getId()) == -1)
			{
				musicalGenreList->Add(musicalGenre);
			}
		}
	}

	//musicalGenreList->DisplayString();

	return musicalGenreList;
}

CircularDoublyList* FileLoader::ReadAndLoadArtistsFile(CircularDoublyList& musicalGenreList) {

	CircularDoublyList* artistList = new CircularDoublyList();

	string str;

	ifstream file("Artista.txt");

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			Artist* artist = new Artist();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 2)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					artist->setId(stoi(token));
				}
				else if (count == 1)
				{
					artist->setName(token);
				}
				else if (count == 2)
				{
					artist->setMusicalGenreId(stoi(token));
				}

				str.erase(0, pos + delim.length());

				count++;
			}
			int existsGenre = musicalGenreList.GetElementIndexById(artist->getMusicalGenreId());
			int isNotDuplicated = artistList->GetElementIndexById(artist->getId());

			if (existsGenre != -1 && isNotDuplicated == -1)
			{
				artistList->Add(artist);
			}

		}
	}
	//artistList->DisplayString();
	return artistList;
}

CircularDoublyList* FileLoader::ReadAndLoadAlbumFile(CircularDoublyList& artistList) {
	CircularDoublyList* albumList = new CircularDoublyList();

	string str;

	ifstream file("Album.txt");

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			Album* album = new Album();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 2)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					album->setId(stoi(token));
				}
				else if (count == 1)
				{
					album->setName(token);
				}
				else if (count == 2)
				{
					album->setArtistId(stoi(token));
				}

				str.erase(0, pos + delim.length());

				count++;
			}
			int existsGenre = artistList.GetElementIndexById(album->getArtistId());
			int isNotDuplicated = albumList->GetElementIndexById(album->getId());

			if (existsGenre != -1 && isNotDuplicated == -1)
			{
				albumList->Add(album);
			}

		}
	}
	//albumList->DisplayString();
	return albumList;
}

CircularDoublyList* FileLoader::ReadAndLoadSongsFile(CircularDoublyList& artistList, CircularDoublyList& albumList,
	                                                 CircularDoublyList& musicalGenreList, CircularDoublyList& playList )
{
	CircularDoublyList* songList = new CircularDoublyList();

	string str;

	ifstream file("Canciones.txt");

	while (!file.eof()) {
		getline(file, str);

		if (str != "") {

			Song* song = new Song();

			string delim = ";";

			size_t pos = 0;

			string token;

			int count = 0;

			while (((pos = str.find(delim)) != string::npos) || count <= 5)
			{
				token = str.substr(0, pos);

				if (count == 0)
				{
					song->setId(stoi(token));
				}
				else if (count == 1)
				{
					song->setName(token);
				}
				else if (count == 2)
				{
					song->setArtistId(stoi(token));
				}
				else if (count == 3)
				{
					song->setAlbumId(stoi(token));
				}
				else if (count == 4)
				{
					song->setMusicGenreId(stoi(token));
				}
				else if (count == 5)
				{
					song->setPlayListId(stoi(token));
				}

				str.erase(0, pos + delim.length());

				count++;
			}
			int existsArtist = artistList.GetElementIndexById(song->getArtistId());
			int existsAlbum = albumList.GetElementIndexById(song->getAlbumId());
			int existsMusicalGenre = musicalGenreList.GetElementIndexById(song->getMusicGenreId());
			int existsPlayList = playList.GetElementIndexById(song->getPlayListId());
			int isNotDuplicated = songList->GetElementIndexById(song->getId());

			if (existsArtist != -1 && 
				existsAlbum != -1 &&
				existsMusicalGenre != -1 &&
				existsPlayList != -1 &&
				isNotDuplicated == -1)
			{
				songList->Add(song);
			}

		}
	}
	//songList->DisplayString();
	return songList;
}
