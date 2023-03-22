#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class User : public Object {

private:
	string mail = "";


public:  // Constructors

	User() {}

	User(int userId, string userName, string clientMail) : Object(userId, userName)
	{
		mail = clientMail;
	}

	string getEmail() {
		return this->mail;
	};

	void setEmail(string mail) {
		this->mail = mail;
	};

	

	//friend class List;
};
