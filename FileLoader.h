#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "PlayList.h"
#include "MusicalGenre.h"
#include "Artist.h"
#include "Album.h"
#include "MusicPlayer.h"
#include "CircularDoublyList.h"

using namespace std;

class FileLoader {

private:


public:
	FileLoader() { }

	~FileLoader();

	CircularDoublyList* ReadAndLoadUserFile();

	CircularDoublyList* ReadAndLoadPlayListFile(CircularDoublyList& userList);

	CircularDoublyList* ReadAndLoadMusicalGenreFile();

	CircularDoublyList* ReadAndLoadArtistsFile(CircularDoublyList& musicalGenreList);

	CircularDoublyList* ReadAndLoadAlbumFile(CircularDoublyList& artistList);

	CircularDoublyList* ReadAndLoadSongsFile(CircularDoublyList& artistList, CircularDoublyList& albumList, CircularDoublyList& musicalGenreList, CircularDoublyList& playList);
};
