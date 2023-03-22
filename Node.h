#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {

private:
	string charValue = "";
	string songInfo = "";
	Node* NextNode;


public:  // Constructors

	Node() {
		this->charValue = "";
		this->songInfo = "";
		NextNode = NULL;
	}

	Node(string v, string songInfo)
	{
		this->charValue = v;
		this->songInfo = songInfo;
		NextNode = NULL;
	}

	Node(string charVal,string songInfo,Node* newNextNode)
	{
		this->charValue = charVal;
		this->songInfo = songInfo;
		NextNode = newNextNode;
	}

	string getCharValue() {
		return this->charValue;
	};

	void setCharValue(string charValue) {
		this->charValue = charValue;
	};

	string getSongInfo() {
		return this->songInfo;
	};

	void setSongInfo(string songInfo) {
		this->songInfo = songInfo;
	};
	friend class Queue;
	friend class Stack;
	friend class List;
};

typedef Node* PointerNode; //Alias

