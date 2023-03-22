#pragma once
#include <iostream>
#include "MusicPlayer.h"
#include "Queue.h"

using namespace std;

class AppManager {

private:

	MusicPlayer* musicPlayer;
	Queue* musicQueue;

public:

	AppManager() {
		this->musicPlayer = new MusicPlayer;
		this->musicQueue = new Queue;
	}

	MusicPlayer* getMusicPlayer() {
		return this->musicPlayer;
	}

	void LoadMusicData();

	void ExecuteCommandByType(int type);

	void DataManager();

	void MusicPlayerManager();

	void ReportManager();

	/// <summary>
	/// Insert
	/// </summary>
	void InsertUser();

	void InsertPlayList();
	
	void InsertMusicalGenre();

	void InsertArtist();

	void InsertAlbum();

	void InsertSong();

	/// <summary>
	/// Seacrh
	/// </summary>

	void SearchUser();

	void SearchPlayList();

	void SearchMusicalGenre();

	void SearchArtist();

	void SearchAlbum();

	void SearchSong();

	/// <summary>
	/// Delete
	/// </summary>
	void DeleteUser();

	void DeletePlayList();

	void DeleteMusicalGenre();

	void DeleteArtist();

	void DeleteAlbum();

	void DeleteSong();

	/// <summary>
	/// Update
	/// </summary>
	void UpdateUser();

	void UpdatePlayList();

	void UpdateMusicalGenre();

	void UpdateArtist();

	void UpdateAlbum();

	void UpdateSong();

	/// <summary>
	/// Enqueue Music
	/// </summary>
	void EnqueueMusic();

	void PlaySongs();

	/// <summary>
	/// Reports
	/// </summary>
	void DisplayUserList();

	void DisplayUserPlayLists();

	void DisplayAlbums();

	void DisplaySongs();
};
