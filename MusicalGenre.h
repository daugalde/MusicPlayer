#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class MusicalGenre : public Object {

private:
	string description = "";


public:  // Constructors

	MusicalGenre() {}

	MusicalGenre(int id, string name, string description) : Object(id, name)
	{
		this->description = description;
	}

	string getDescription() {
		return this->description;
	};

	void setDescription(string description) {
		this->description = description;
	};

	friend class List;
};
