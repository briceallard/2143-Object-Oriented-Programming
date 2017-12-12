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

// insert ==> same as enqueue except enters data by
//				priority instead of simply at 'tail'
// @param <T> data - templated data to store in Node
//		int team - team number to be stored in Node
template <class T>
void List<T>::insert(T data, int team) {
	Node *temp = new Node;
	temp->data = data;
	temp->team = team;

	// if there is no list, insert to head
	if (head == NULL) {
		temp->next = temp->prev = NULL;
		head = tail = temp;
		cout << "Member " << temp->data
			<< " from Team " << temp->team 
			<< " entered the line.\n";
		print();
	}
	// else if there is a list, search team
	else {
		// Find Node BEFORE the one you want to insert
		Node *pre = search(team);

		// if *pre is last Node in queue
		if (pre->next == NULL) {
			pre->next = temp; // Points to new node
			temp->prev = pre; // points new node to prev
			temp->next = NULL;// points next to null
			tail = temp;	// sets tail to new node

			cout << "Member " << temp->data
				<< " from Team " << temp->team
				<< " entered the line.\n";
			print();	// pretty print
		}
		// *pre is in middle of queue
		else {
			// Node after where you want to insert
			Node *after = pre->next;
			pre->next = temp; // points to new node
			temp->prev = pre; // points new node to prev
			temp->next = after; // points new node to next
			after->prev = temp; // points next to new node

			cout << "Member " << temp->data
				<< " from Team " << temp->team
				<< " entered the line.\n";
			print();		// pretty print
		}
	}
}

// dequeue ==> removes last item in list
// @return int - team number value being deleted
template <class T>
int List<T>::deque() {
	Node *temp;
	int tempData = -1;

	if (head == NULL)
		cout << "The Queue is empty ...\n";
	else if (head == tail) {
		tempData = head->data;
		temp = tail;
		cout << "Member " << temp->data
			<< " from Team " << temp->team
			<< " left the line.";
		head = tail = NULL;
		delete temp;	// reallocate space
		print();
	}
	else {
		tempData = head->data;
		temp = head;
		cout << "Member " << temp->data
			<< " from Team " << temp->team
			<< " left the line.\n";
		head = temp->next;
		head->prev = NULL;
		delete temp;	// reallocate space
		print();
	}
	return tempData;	// member number
}

// deleteAll ==> deletes all Nodes from list
//		and acts as a standard destructor
template <class T>
void List<T>::deleteAll() {
	Node *temp = head;

	//if (temp == NULL)
	//	cout << "Deleting all Queue instances ...\n" << endl;
	//if {
		cout << "Deleting all Queue instances ...\n";
		while (head != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
		tail = head = NULL;
	//}
}

// search ==> finds node located before entry location
//				of new node you want to insert
// @param ==> int team - team to insert into (behind last)
// @return ==> Node<T> - pointer of location to insert behind
template <class T>
Node<T>* List<T>::search(int team) {
	Node *temp = head;
	
	// Check that team is less than or equal to search
	// variable and that next node is not null
	while (temp->team <= team && temp->next != NULL) {
		if (temp->next->team > team)
			return temp;
		else
			temp = temp->next;
	}
}

// print ==> pretty print for current items in list
// @param ==> none
// @return ==> none
template <class T>
void List<T>::print() {
	Node *temp = head;

	//if (temp == NULL)
	// 	cout << "\nThe Queue is empty ...\n" << endl;
	//else {
		while (temp != NULL) {
			cout << "<- " << temp->data 
				<< ':' << temp->team << " -> ";
			temp = temp->next;
		}
		cout << endl << endl;
	//}
}