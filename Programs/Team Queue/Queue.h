#pragma once

template <class T>
struct Node {
	T data;
	int team;
	Node<T> *next;
	Node<T> *prev;
};

template <class T>
class List {
	typedef Node<T> Node;

public:
	// Constructors
	List<T>();
	List<T>(const List<T>&);

	// Destructor
	~List<T>();

	// Mutator Functions
	void enque(T, int);
	void deque();
	void deleteAll();

	// Accessor Functions
	void print();

private:
	Node *head;
	Node *tail;
};

#include "Queue.cpp"
