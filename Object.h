#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object {

private:
	int id;
	string name;
public:

	Object() {
		this->id = 0;
		this->name = "";
	}

	Object(int id, string name) {
		this->id = id;
		this->name = name;
	}

	int getId() {
		return this->id;
	};

	void setId(int id) {
		this->id = id;
	};

	string getName() {
		return this->name;
	};

	void setName(string name) {
		this->name = name;
	};

	void toString() {
		cout << this->getId() << " " << this->getName() << " \n" << endl;
	}

	friend class DoublyNode;
	friend class CircularDoublyList;
	friend class Node;
	friend class List;
};

