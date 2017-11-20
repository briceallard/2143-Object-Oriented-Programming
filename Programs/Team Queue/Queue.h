#pragma once
#include <iostream>

template <class T>
struct Node {
	T data;
	Node<T> *next;
	Node<T> *prev;
};

template <class T>
class List {
public:
	// Constructors
	List();
	List(const List<T>&);

	// Mutator Functions


	// Accessor Functions


	// Operator Overload
	List<T> & operator = (const List<T>&);
private:
	Node<T> *start;
	Node<T> *current;
};
