#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main() {
	List<int> list;
	
	list.enque(254, 2);
	list.deque();

	list.enque(163, 1);
	list.enque(344, 3);
	list.enque(255, 2);
	list.deque();

	list.print();

	system("pause");
	return 0;
}
