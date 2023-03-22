#include "FileLoader.h"
using namespace std;

void MusicPlayer::InitStoreLoad()
{
	FileLoader loader;

	//cout << "Cargando Propietarios \n" << endl;
	this->setUsers(loader.ReadAndLoadUserFile());

	//cout << "Cargando Playlist \n" << endl;
	this->setPlayLists(loader.ReadAndLoadPlayListFile(*this->getUsers()));

	//cout << "Cargando Genrero Musical \n" << endl;
	this->setMusicalGenres(loader.ReadAndLoadMusicalGenreFile());

	//cout << "Cargando Artistas \n" << endl;
	this->setArtists(loader.ReadAndLoadArtistsFile(*this->getMusicalGenres()));

	//cout << "Cargando Albumns\n" << endl;
	this->setAlbums(loader.ReadAndLoadAlbumFile(*this->getArtists()));

	//cout << "Cargando Canciones\n" << endl;
	this->setSongs(loader.ReadAndLoadSongsFile(*this->getArtists(), *this->getAlbums(), *this->getMusicalGenres(), *this->getPlayLists()));
}
