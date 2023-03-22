#pragma once
#include <iostream>
#include "CircularDoublyList.h"

using namespace std;

class MusicPlayer {

private:

	CircularDoublyList* users;
	CircularDoublyList* playLists;
	CircularDoublyList* musicalGenres;
	CircularDoublyList* artists;
	CircularDoublyList* albums;
	CircularDoublyList* songs;

public:

	MusicPlayer() {
		users = new CircularDoublyList();
		playLists = new CircularDoublyList();
		musicalGenres = new CircularDoublyList();
		artists = new CircularDoublyList();
		albums = new CircularDoublyList();
		songs = new CircularDoublyList();
	}

	void InitStoreLoad();

	void setUsers(CircularDoublyList* users) {
		this->users = users;
	};

	CircularDoublyList* getUsers() {
		return this->users;
	};

	void setPlayLists(CircularDoublyList* playLists) {
		this->playLists = playLists;
	};

	CircularDoublyList* getPlayLists() {
		return this->playLists;
	};

	void setMusicalGenres(CircularDoublyList* musicalGenres) {
		this->musicalGenres = musicalGenres;
	};

	CircularDoublyList* getMusicalGenres() {
		return this->musicalGenres;
	};

	void setArtists(CircularDoublyList* artists) {
		this->artists = artists;
	};

	CircularDoublyList* getArtists() {
		return this->artists;
	};

	void setAlbums(CircularDoublyList* albums) {
		this->albums = albums;
	};

	CircularDoublyList* getAlbums() {
		return this->albums;
	};

	void setSongs(CircularDoublyList* songs) {
		this->songs = songs;
	};

	CircularDoublyList* getSongs() {
		return this->songs;
	};

	friend class CircularDoublyList;

};
