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
void List<T>::insert(T data, int team) {
	Node *temp = new Node;
	temp->data = data;
	temp->team = team;

	// if there is no list, insert to head
	if (head == NULL) {
		temp->next = temp->prev = NULL;
		head = tail = temp;
		cout << "E - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
	}
	// else if there is a list, search team
	else {
		Node *pre = search(team);

		// if *pre is last Node in queue
		if (pre->next == NULL) {
			pre->next = temp;
			temp->prev = pre;
			temp->next = NULL;
			tail = temp;
			cout << "E - Employee: " << temp->data
				<< " Team: " << temp->team << endl;
		}
		else {
			Node *after = pre->next;

			pre->next = temp;
			temp->prev = pre;
			temp->next = after;
			after->prev = temp;
			cout << "E - Employee: " << temp->data
				<< " Team: " << temp->team << endl;
		}
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
		temp = head;
		cout << "D - Employee: " << temp->data
			<< " Team: " << temp->team << endl;
		head = temp->next;
		head->prev = NULL;
		delete temp;
	}
}

template <class T>
void List<T>::deleteAll() {
	Node *temp = head;

	if (temp == NULL)
		cout << "The Queue has nothing to Delete ...\n" << endl;
	else {
		while (head != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
		tail = head = NULL;
	}
}

template <class T>
Node<T>* List<T>::search(int team) {
	Node *temp = head;
	
	while (temp->team <= team && temp->next != NULL) {
		if (temp->next->team > team)
			return temp;
		else
			temp = temp->next;
	}
}

template <class T>
void List<T>::print() {
	Node *temp = head;

	if (temp == NULL)
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
