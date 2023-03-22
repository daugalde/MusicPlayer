#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Album : public Object {

private:
	int artistId = 0;


public:  // Constructors

	Album() {}

	Album(int id, string name, int artistId) : Object(id, name)
	{
		this->artistId = artistId;
	}

	int getArtistId() {
		return this->artistId;
	};

	void setArtistId(int artistId) {
		this->artistId = artistId;
	};

	friend class List;
};
