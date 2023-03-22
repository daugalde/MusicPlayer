#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

class QueueNode {

private:
	List* list = new List();
	QueueNode* NextNode;

public:  // Constructors

	QueueNode() {
		NextNode = NULL;
	}

	QueueNode(string fileName, string songInfo)
	{
		/*ifstream file(fileName);
		string str;
		while (!file.eof()) {
			getline(file, str);
			this->list->Add(fileName, songInfo);
		}*/
		this->list->Add(fileName, songInfo);
		
		NextNode = NULL;
	}
	

	List* getList() {
		return this->list;
	};

	friend class List;
	friend class Queue;
};

typedef QueueNode* QueuePointerNode; //Alias

