#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class List {

private:
	PointerNode head;

public:
	List() {
		this->head = NULL;
	}

	~List() {
		this->head = NULL;
	};
	bool IsEmpty() { return head == NULL; }
	void Add(string charVal, string songInfo); // Insert at End
	PointerNode RemoveElement();
	void DisplayString();
	int Length();
};
