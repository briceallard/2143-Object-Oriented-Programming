/*
Brice Allard
Program 5 - Team Queue
Dr. Stringfellow

Header file for my queue class.

**NOTES: enqueue is default for standard
	queues, however for the team queue in
	this program we will be using insert
*/

#pragma once

// Struct that will hold team data in Node
template <class T>
struct Node {
	T data;
	int team;
	Node<T> *next;
	Node<T> *prev;
};

template <class T>
class List {
	// Don't want to type <T> anymore
	typedef Node<T> Node;

public:
	// Constructors
	List<T>();
	List<T>(const List<T>&);

	// Destructor
	~List<T>();

	// Mutator Functions
	void enque(T, int);
	void insert(T, int);
	int deque();
	void deleteAll();
	
	// Accessor Functions
	Node* search(int);
	void print();

private:
	// Member variables
	Node *head;
	Node *tail;
};

#include "Queue.cpp"
