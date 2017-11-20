#include "Queue.h"

// Default Constructor
template <class T>
List<T>::List() : start(0), current(0) {}

// Copy Constructor
template <class T>
List<T>::List(const List<T>& newList) {
	copy(newList);
}

//Destructor
template<class T>
List<T>::~List() {
	deleteAll();
}

// Operator Overload
template<class T>
List<T> & List<T>::operator= (const List<T>* newList) {
	if (this == &newList)
		return *this;
	deleteAll();
	copy(newList);
	return *this;
}
