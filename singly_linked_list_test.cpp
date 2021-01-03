#include "singly_linked_list.cpp"
#include <algorithm>
using namespace std;
int main(){
	//adding new nodes to the list
	singly_linked_list<string> list;
	list.add_node_to_head("i know");
	list.add_node_to_head("speak clearly");
	list.add_node_to_head("trophy");
	list.add_node_to_tail("i");
	
	list.add_node_to_tail("love");
	list.add_node("programming", 4);
	list.add_node("all day",5);
	//This changes the 6th index value and does NOT add a new node
	list[6] = "for real";
	//prints out all the elements in the linked list
	list.print_list();
	cout <<endl;
	//checks to see if the list is empty
	cout<<list.is_empty()<<endl;
	//gets the first and the last index
	cout<<list.front()<<endl<<list.back()<<endl;
	//sets the first index and tries to set a non-existent index
	list[0] = "west";
	list[20] = "side";
	//prints out the values in the array using array index 
	for (int i = 0; i < 10; i++){
		cout << list[i]<< " ";
	}
	//comparision
	if (list[0] == list[2]){
		printf("0 and 2 are the same\n");
	}
	if (list[0] != list[2]){
		printf("0 and 2 are not the same\n");
	}	
	if (list[0] >= list[2]){
		printf("0 is greater than or equal to 0\n");
	}
	if (list[0] < list[2]){
		printf("0 is less than 2\n");
	}
	if (list[2] == "west"){
		printf("2 and actual 2 are the same\n");
	}
	if (list[2] != "side"){
		printf("2 and actual 2 are not the same\n");
	}
	if (list[0] == "str"){
		printf("0 and \"str\" are the same\n");
	}
	//finds if a value exist inside the linked list
	cout<<"Find \"west\" in the list => "<<list.find("west")<<endl;
	//using an iterator
	singly_linked_list<string>::iterator itr;
	//setting the iterator to the first index
	itr = list.begin();
	//inc the itr
	itr++;
	//setting the current itr pos to a value
	*itr = "elephant";
	//printing the curr itr value
	cout <<"iterator value is "<<*itr<<endl;
	cout << "array using iterator print-out"<<endl;
	cout<<"_________________________________"<<endl;
	int j = 0;
	//looping using itr, begin and end
	for (itr = list.begin(); itr != list.end(); itr++){
		cout << *itr <<" ";
		j++;
	}
	list[2] = "lovely";
	//removing node from tail
	list.remove_node_from_tail();
	//removing node from head
	list.remove_node_from_head();
	
	cout << endl;
	for (int i = 0; i < list.get_size(); i++){
		cout << list[i]<< " ";
	}
	//removing an index
	list.remove_node(2);
	//removing a node based on its content and not index
	list.remove_node_by_value("west");
	cout <<endl;
	for (int i = 0; i < list.get_size(); i++){
		cout << list[i]<< " ";
	}
	//getting the size
	cout<<endl<< "The size of the list is: "<<list.get_size()<<endl;
	//erase/remove nodes. first value is the staring index and the second states how many nodes are gonna be deleted
	list.erase(0, list.get_size());
	for (int i = 0; i < list.get_size(); i++){
		cout << list[i]<< " ";
	}
	cout<<endl<< "The size of the list is: "<<list.get_size()<<endl;
	singly_linked_list<int> l;
	l.add_node(10, 0);
	l.add_node(23, 1);
	l.add_node(14, 2);
	l.add_node(7, 3);
	l.add_node(5, 4);
	l.add_node(1, 5);

	return 0;
}
