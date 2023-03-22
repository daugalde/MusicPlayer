#include <iostream>
#include "QueueNode.h"

using namespace std;

class Queue {

private:
	int front;
	int back;
	QueuePointerNode queue[5];

public:

	Queue() { 
		front = 0;
		back = -1;
		for (int i = 0; i < 5; i++)
		{
			this->queue[i] = NULL;
		}
	}
	bool IsEmpty() { return back == front; }
	void Enqueue(string value, string songInfo); // Inserts lef to right
	QueuePointerNode Dequeue(); // Extract from right FIFO
	void Display(); // Print Queue Values
	int Length();
	QueuePointerNode GetElementAt(int index);
	void LoadFiles();
	friend class QueueNode;
};

