#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class PlayList : public Object {

private:
	int userId = 0;


public:  // Constructors

	PlayList() {}

	PlayList(int playListId, string playListName, int userId) : Object(playListId, playListName)
	{
		this->userId = userId;
	}

	int getUserId() {
		return this->userId;
	};

	//TODO Check if this is required
	void setUserId(int userId) {
		this->userId = userId;
	};

	friend class List;
};
