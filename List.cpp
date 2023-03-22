#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"

using namespace std;

int List::Length()
{
	int cont = 0;

	PointerNode aux = head;
	if (!IsEmpty()) {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
	}
	return cont;
};

void List::Add(string charVal, string songInfo)
{
	if (IsEmpty()) {
		head = new Node(charVal, songInfo);
	}
	else
	{
		PointerNode aux = head;
		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(charVal, songInfo);
	}
};

PointerNode List::RemoveElement() {
	PointerNode response = NULL;
	if (!IsEmpty()) {
		if (head->NextNode == NULL)
		{
			response = head;
			head = NULL;
			delete head;
		}
		else
		{
			response = head;
			head = head->NextNode;
		}
	}
	return response;
}

void List::DisplayString()
{
	PointerNode aux;
	if (IsEmpty()) {
		cout << "Lista esta vacia";
	}
	else
	{
		aux = head;
		while (aux)
		{
			cout << aux->songInfo << " " << aux->charValue;
			aux = aux->NextNode;
		}
		cout << "\n" << endl;
	}
};

