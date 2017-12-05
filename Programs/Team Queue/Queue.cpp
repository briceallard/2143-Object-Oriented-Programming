/*
Brice Allard
Program 5 - Team Queue
Dr. Stringfellow

Queue class will control all variables of my
doubly linked list, including insertion, deletion,
search, and print.

**NOTES: enqueue is default for standard
queues, however for the team queue in
this program we will be using insert
*/

#include <iostream>
#include "Queue.h"

// Default Constructor
template <class T>
List<T>::List() : head(NULL), tail(NULL) {}

// Copy Constructor
template <class T>
List<T>::List(const List<T>& newList) {
	if (newList.head != NULL) {
		head = new Node(newList.head);
		Node *temp = newList.head;
		tail = head;
		while (temp->next != NULL) {
			tail->next = new Node(temp->next);
			tail - tail->next;
			temp = temp->next;
		}
	}
}

//Destructor
template<class T>
List<T>::~List() {
	deleteAll();
}

// Enqueue ==> enters item to 'tail' of queue
// @param <T> data - templated data to store in Node
//		int team - team number to be stored in Node
template <class T>
void List<T>::enque(T data, int team) {
	// Create new 'empty' node
	Node *temp = new Node;

	// Enter data into node
	temp->data = data;
	temp->team = team;

	// Set pointers for doubly linked list
	temp->next = NULL;
	temp->prev = NULL;

	// List is empty
	if (head == NULL) {
		head = tail = temp;
		cout << "E - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
	}
	// Not Empty
	else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		cout << "E - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
	}
}
