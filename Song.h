#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Song : public Object {

private:
	int artistId = 0;
	int albumId = 0;
	int musicGenre = 0;
	int playListId = 0;


public:  // Constructors

	Song() {}

	Song(int id, string name, int artistId, int albumId, int musicGenre, int playListId) : Object(id, name)
	{
		this->artistId = artistId;
		this->albumId = albumId;
		this->musicGenre = musicGenre;
		this->playListId = playListId;
	}

	int getArtistId() {
		return this->artistId;
	};

	void setArtistId(int artistId) {
		this->artistId = artistId;
	};

	int getAlbumId() {
		return this->albumId;
	};

	void setAlbumId(int albumId) {
		this->albumId = albumId;
	};

	int getMusicGenreId() {
		return this->musicGenre;
	};

	void setMusicGenreId(int musicGenre) {
		this->musicGenre = musicGenre;
	};

	int getPlayListId() {
		return this->playListId;
	};

	void setPlayListId(int playListId) {
		this->playListId = playListId;
	};

	friend class List;
};
