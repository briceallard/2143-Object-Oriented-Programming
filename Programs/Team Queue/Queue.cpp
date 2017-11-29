#include <iostream>
#include "Queue.h"

// Default Constructor
template <class T>
List<T>::List() : head(NULL), tail(NULL) {}

// Copy Constructor
template <class T>
List<T>::List(const List<T>& newList) : 
	head(NULL), tail(NULL) {


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

	if (head == NULL) {
		head = tail = temp;
		cout << "E - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
	}
	else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		cout << "E - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
	}
}

template <class T>
void List<T>::deque() {
	Node *temp;
	
	if (head == NULL)
		cout << "The Queue is empty ...\n";
	else if (head == tail) {
		temp = tail;
		cout << "D - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
		head = tail = NULL;
		delete temp;
	}
	else {
		temp = tail;
		cout << "D - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
		tail = temp->prev;
		delete temp;
		tail->next = NULL;
	}
}

template <class T>
void List<T>::print() {
	Node *temp = head;

	if (head == NULL)
		cout << "The Queue is empty ...\n" << endl;
	else {
		cout << endl;
		while (temp != NULL) {
			cout << "<- " << temp->data 
				<< ':' << temp->team << " -> ";
			temp = temp->next;
		}
		cout << endl << endl;
		cout << head->data << ':' << head->team << " = HEAD\n"
			<< tail->data << ':' << tail->team << " = TAIL\n\n";
	}
}

template <class T>
void List<T>::deleteAll() {
	Node *temp = head;

	if (temp == NULL)
		cout << "The Queue has nothing to delete ...\n" << endl;
	else {
		while (head != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
		tail = head = NULL;
	}
}
