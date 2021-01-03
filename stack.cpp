#include "stack.h"

template <typename T>
bool stack<T>::empty(){
	bool ret = singly_linked_list<T>::is_empty();
	return ret;
}
template <typename T>
T stack<T>::peek(){
	T val = singly_linked_list<T>::front();
	return val;
}
template <typename T>
int stack<T>::getSize(){
	int ret = singly_linked_list<T>::get_size();
	return ret;
}
template <typename T>
void stack<T>::push(T data){
	singly_linked_list<T>::add_node_to_head(data);
}
template <typename T>
void stack<T>::pop(){
	singly_linked_list<T>::remove_node_from_head();
}
template <typename T>
void stack<T>::print(){
	singly_linked_list<T>::print_list();
}
//template <typename T>
//stack<T>::~stack()=~singly_linked_list();
/*	

	int getSize();
	void push(T data);
	void pop();
	void print();
	~stack();*/
