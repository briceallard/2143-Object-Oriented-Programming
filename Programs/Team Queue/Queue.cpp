#include <iostream>
#include "Queue.h"

// Default Constructor
template <class T>
List<T>::List() : front(NULL), rear(NULL) {}

// Copy Constructor
template <class T>
List<T>::List(const List<T>& newList) {
}

//Destructor
template<class T>
List<T>::~List() {
	deleteAll();
}

template <class T>
void List<T>::enque(T data, int team) {
	Node *temp = new Node;
	temp->data = data;
	temp->team = team;
	temp->next = NULL;
	temp->prev = NULL;

	if (front == NULL) {
		front = rear = temp;
		cout << "E - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
	}
	else {
		temp->prev = rear;
		rear->next = temp;
		rear = temp;
		cout << "E - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
	}
}

template <class T>
void List<T>::deque() {
	Node *temp;
	
	if (front == NULL)
		cout << "The Queue is empty ...\n";
	else {
		temp = rear;
		cout << "D - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
		rear = temp->prev;
		delete temp;
		rear->next = NULL;
	}
}

template <class T>
void List<T>::print() {
	Node *temp = front;

	if (front == NULL)
		cout << "The Queue is empty ...\n" << endl;
	else {
		while (temp != NULL) {
			cout << "Employee " << temp->data 
				<< " belongs to team " << temp->team 
				<< endl;
			temp = temp->next;
		}
		cout << endl;
	}
}

template <class T>
void List<T>::deleteAll() {
	Node *temp = front;

	if (temp == NULL)
		cout << "The Queue has nothing to delete ...\n" << endl;
	else {
		while (front != NULL) {
			front = front->next;
			delete temp;
			temp = front;
		}
		rear = front = NULL;
	}
}
