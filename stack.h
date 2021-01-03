#ifndef STACK_H
#define STACK_H
#include "singly_linked_list.cpp"
using namespace std;
template <typename T>
class stack: protected singly_linked_list<T>{
public:
	bool empty();
	T peek();
	int getSize();
	void push(T data);
	void pop();
	void print();
	//~stack();
}; 
#endif
