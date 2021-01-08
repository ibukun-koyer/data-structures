#include "queue.h"
template <typename T>
bool queue<T>::empty(){
	bool ret = singly_linked_list<T>::is_empty();
	return ret;
}
template <typename T>
T queue<T>::peek(){
	T val = singly_linked_list<T>::front();
	return val;
}
template <typename T>
int queue<T>::getSize(){
	int ret = singly_linked_list<T>::get_size();
	return ret;
}
template <typename T>
void queue<T>::enqueue(T data){
	singly_linked_list<T>::add_node_to_tail(data);
}
template <typename T>
void queue<T>::dequeue(){
	singly_linked_list<T>::remove_node_from_head();
}
template <typename T>
void queue<T>::print(){
	singly_linked_list<T>::print_list();
}

