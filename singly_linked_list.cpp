#include "singly_linked_list.h"


template <typename T>
int singly_linked_list<T>::get_size(){
	return size;
}
template <typename T>
int add_a_node(T data, node<T> **head, node<T> **tail, int index, int *size){
	if (index > *size){
		return 0;
	}
	if (index < 0){
		return 0;
	}
	if ((*head == NULL)||(*tail == NULL)){
	
		*head =new node<T>;
		(*head)->data = data;
		(*head)->nextptr = NULL;
		*tail = *head;
		*size = *size + 1;
		return 1;
	}
	else{
		node<T> *temp = *head;
		if (index != *size){
			for (int i = 0; i < index; i++){
				if (i + 1 != index)
					temp = temp->nextptr;
			}
		}
		else if (*size == index){
			temp = *tail;
		}

		node<T> *temp2 = temp->nextptr;
		node<T> *new_node = new node<T>;
		new_node->data = data;
		if (index != 0){
			temp->nextptr = new_node;
			new_node->nextptr = temp2;
		}
		if (index == 0){
			new_node->nextptr = temp;
			*head = new_node;
		}
		else if (*size == index){
			*tail = new_node;
		}
		*size = *size + 1;
	}
		
		
	return 1;

}
	
	
template <typename T>
singly_linked_list<T>::singly_linked_list(){
	size = 0;
	headptr = NULL;
	tailptr = NULL;
	waste = new node<T>;
}
template <typename T>
bool singly_linked_list<T>::is_empty(){
	return (size == 0) ? true:false;
} 
template <typename T>
int singly_linked_list<T>::add_node(T data, int index){
	int ret = add_a_node(data, &headptr, &tailptr, index, &size);
	return ret;
}
template <typename T>
int singly_linked_list<T>::add_node_to_head(T data){
	int ret = add_a_node(data, &headptr, &tailptr, 0 , &size);
	return ret;
}
template <typename T>
int singly_linked_list<T>::add_node_to_tail(T data){
	int ret = 0;
	if (size == 0)
		ret = add_a_node(data, &headptr, &tailptr, 0 , &size);
	else
		ret = add_a_node(data, &headptr, &tailptr, size , &size);
	return ret;
}
template <typename T>
T singly_linked_list<T>::front(){
	return headptr->data;
}
template <typename T>
T singly_linked_list<T>::back(){
	return tailptr->data;
}
template <typename T>
void singly_linked_list<T>::print_list(){
	node<T> *temp = headptr;
	for (int i = 0; i < size; i++){
		cout<<temp->data<<" ";
		temp = temp->nextptr;
	}	
}
template <typename T>
node<T>& singly_linked_list<T>::operator [](int index){
	
	if (index < size){
		node<T> *temp = headptr;
		for (int i = 0; i < size; i++){
			if (i == index){
				return *temp;
			}
			temp = temp->nextptr;
		}
	}
	return (*waste);
	
}
template <typename T>
node<T>* singly_linked_list<T>::begin(){
	return headptr;
}
template <typename T>
node<T>* singly_linked_list<T>::end(){
	if (tailptr == NULL){
		return NULL;
	}
	return tailptr->nextptr;
}
template <typename T>
bool singly_linked_list<T>::find(T data){
	node<T> *temp = headptr;
	for (int i = 0; i < size; i++){
		if (data == temp->data){
			return true;
		}
		temp = temp->nextptr;
	}
	return false;
}
template <typename T>
bool remove(T data, node<T> **head, node<T> **tail, int index, int *size, int which){
	//which is 0 if using remove_node_by_value
	//which is 1 if using remove_node
	node<T>*prev_node = NULL;
	node<T>* temp = *head;
	if (which == 0){
		for (int i = 0; i < *size; i++){
			if (temp->data == data){
				goto jmp;
			}
			prev_node = temp;
			temp = temp->nextptr;
		}
		return false;
	}
	if (which == 1){
		if (index >= *size){
			return false;
		} 
		if (index < 0){
			return false;
		}
		for (int i = 0; i < *size; i++){
			if (i == index){
				goto jmp;
			}
			prev_node = temp;
			temp = temp->nextptr;
		}
		return false;
	}
jmp:    if (prev_node == NULL){
		*head = temp->nextptr;
		*size = *size - 1;
		delete temp;
	}
	else{
		prev_node->nextptr = temp->nextptr;
		if (temp->nextptr == NULL){
			*tail = prev_node;
		}
		*size = *size - 1;
		delete temp;
	}
	return true;
}
		
template <typename T>
bool singly_linked_list<T>::remove_node_from_head(){
	T data;
	bool ret = remove(data, &headptr, &tailptr, 0, &size, 1);
	return ret;
}	
template <typename T>
bool singly_linked_list<T>::remove_node_from_tail(){
	T data;
	bool ret = remove(data, &headptr, &tailptr, size-1, &size, 1);
	return ret;
}
template <typename T>
bool singly_linked_list<T>::remove_node(int index){
	T data;	
	bool ret = remove(data, &headptr, &tailptr, index, &size, 1);
	return ret;
}	
template <typename T>
bool singly_linked_list<T>::remove_node_by_value(T data){	
	bool ret = remove(data, &headptr, &tailptr, 0, &size, 0);
	return ret;
}
template <typename T>
bool singly_linked_list<T>::erase(int index, int num_of_nodes_to_remove){
	bool ret = 0;
	for (int i = 0; i < num_of_nodes_to_remove ; i++){
		T data;	
		ret = remove(data, &headptr, &tailptr, index, &size, 1);
		if (ret == 0){
			return ret;
		}
		
	}
	return ret;
}
template <typename T>		
singly_linked_list<T>::~singly_linked_list(){
	erase(0, size);
	if (headptr != NULL){
		delete headptr;
		delete tailptr;
	}
	delete waste;
}
