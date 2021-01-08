#ifndef QUEUE_H
#define QUEUE_H
#include "singly_linked_list.cpp"
using namespace std;
template <typename T>
class queue: protected singly_linked_list<T>{
public:
	bool empty();
	T peek();
	int getSize();
	void enqueue(T data);
	void dequeue();
	void print();
	//~stack();
}; 
#endif
