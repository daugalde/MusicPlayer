#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Artist : public Object {

private:
	int musicalGenreId = 0;


public:  // Constructors

	Artist() {}

	Artist(int id, string name, int musicalGenreId) : Object(id, name)
	{
		this->musicalGenreId = musicalGenreId;
	}

	int getMusicalGenreId() {
		return this->musicalGenreId;
	};

	void setMusicalGenreId(int musicalGenreId) {
		this->musicalGenreId = musicalGenreId;
	};

	friend class List;
};
