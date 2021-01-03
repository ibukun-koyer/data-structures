#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <iostream>
#include <memory>
#include <stdio.h>
using namespace std;
template <typename T>
struct node{
	T data;
	T operator = (T value){
		data = value;
		return data;
	}

	bool operator == (node<T> node){
		return (data == node.data);
	}
	bool operator != (node<T> node){
		return (data != node.data);
	}
	bool operator >= (node<T> node){
		return (data >= node.data);
	}
	bool operator <= (node<T> node){
		return (data <= node.data);
	}
	bool operator < (node<T> node){
		return (data < node.data);
	}
	bool operator > (node<T> node){
		return (data > node.data);
	}

	bool operator == (T node){
		return (data == node);
	}
	bool operator != (T node){
		return (data != node);
	}
	bool operator >= (T node){
		return (data >= node);
	}
	bool operator <= (T node){
		return (data <= node);
	}
	bool operator < (T node){
		return (data < node);
	}
	bool operator > (T node){
		return (data > node);
	}
	friend ostream &operator << (ostream &stream, const node<T> &n){
		stream << n.data;
		return stream;
	}
	friend istream& operator >> (istream &stream, const node<T> &n){
		stream >>n.data;
		return stream;
	}
	~node()=default;
	node *nextptr;
	
};

template <typename T>
class singly_linked_list{
public:
	struct iterator{
private:
		int pos;
		node<T> *ptr;
public:
		~iterator(){
			if (ptr != NULL){
				delete ptr;
			}
		}
		iterator* operator ++(int inc){
			if (ptr!=NULL){
				pos++;
				ptr = ptr->nextptr;
			}
			return this;		
		}
		iterator* operator =(node<T>* ptr_){
			ptr = ptr_;
			return this;
		}
		iterator* operator =(iterator &itr){
			pos = itr.pos;
			ptr = itr.ptr;
			return this;
		}		
		bool operator !=(node<T>* ptr_){
			return (ptr != ptr_);
		}
		bool operator ==(node<T>* ptr_){
			return (ptr == ptr_);
		}
		bool operator !=(iterator &itr){
			return (ptr != itr.ptr);
		}
		bool operator ==(iterator &itr){
			return (ptr == itr.ptr);
		}
		node<T>& operator *(){
			return *(this->ptr);
		}	
		friend ostream &operator << (ostream &stream, const iterator &n){
			stream << &((n.ptr)->data);
			return stream;
		}
		friend istream& operator >> (istream &stream, const iterator &n){
			stream >>&((n.ptr)->data);
			return stream;
		}

		

	};
	int add_node_to_head(T data);
	int add_node(T data, int index);
	int add_node_to_tail(T data);
	bool remove_node_from_head();
	bool remove_node(int index);
	bool remove_node_from_tail();
	bool remove_node_by_value(T data);
	bool is_empty();
	bool find(T data);
	T front();
	T back();
	bool erase(int index, int num_of_nodes_to_remove);
	singly_linked_list();
	singly_linked_list(const singly_linked_list<T> *new_list);
	void print_list();
	node<T>& operator [](int index);
	//T operator (int index);
	virtual ~singly_linked_list();
	int get_size();
	singly_linked_list *operator =(const singly_linked_list<T> *new_list);
	node<T>* begin();
	node<T>* end();
	
private:
	node<T> *headptr;
	node<T> *tailptr;
	node<T> *waste;
	int size;
};
	

#endif
