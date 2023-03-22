#include <iostream>
#include "QueueNode.h"
#include "Queue.h"

using namespace std;

void Queue::Enqueue(string value, string songInfo) {
	for (int i = 0; i < 5; i++) {
		if (queue[i] == NULL) {
			back++;
			queue[back] = new QueueNode(value, songInfo);
			break;
		}
	}
};

QueuePointerNode Queue::Dequeue() {
	if (!IsEmpty()) {
		QueuePointerNode queueNode = this->queue[0];
		this->queue[0] = NULL;

		for (int i = 0; i < 5; i++) {
			if (queue[i] == NULL) {
				queue[i] = queue[i + 1];
				queue[i + 1] = NULL;
			}
		}
		back--;
		return queueNode;
	}
};

void Queue::Display() {
	for (int i = 0; i < 5; i++) {
		if (queue[i] != NULL) {
			cout << "START Display List Item " + to_string(i + 1) << "\n" << endl;
			this->queue[i]->list->DisplayString();
			cout << "\n\nEND Display List Item " + to_string(i + 1) << endl;
			cout << "     " << endl;
			cout << "---------------------------------------------------------" << endl;
			cout << "     " << endl;
		}
	}
};

int Queue::Length()
{
	int cont = 0;

	for (int i = 0; i < 5; i++)
	{
		if (this->queue[i] != NULL) {
			cont++;
		}
		
	}
	return cont;
};

QueuePointerNode Queue::GetElementAt(int index) {
	QueuePointerNode queueNode = this->queue[index];

	return queueNode;
}

void Queue::LoadFiles() {
	for (int i = 0; i < 5; i++) {
		string str = "Arch" + to_string(i + 1) + ".txt";
		//this->Enqueue(str);
	}
};
